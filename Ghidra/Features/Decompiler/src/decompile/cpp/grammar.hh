/* ###
 * IP: GHIDRA
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __CPUI_GRAMMAR__
#define __CPUI_GRAMMAR__

#include "funcdata.hh"

class GrammarToken {
  friend class GrammarLexer;
public:
  enum {
    openparen = 0x28,
    closeparen = 0x29,
    star = 0x2a,
    comma = 0x2c, 
    semicolon = 0x3b,
    openbracket = 0x5b,
    closebracket = 0x5d,
    openbrace = 0x7b,
    closebrace = 0x7d,
    
    badtoken = 0x100,
    endoffile = 0x101,
    dotdotdot = 0x102,

    integer = 0x103,
    charconstant = 0x104,
    identifier = 0x105,
    stringval = 0x106,
  };
private:
  uint4 type;
  union tokenvalue {
    uintb integer;
    std::string *stringval;
  };
  tokenvalue value;
  int4 lineno;			// Line number containing this token
  int4 colno;			// Column where this token starts
  int4 filenum;			// Which file were we in
  void set(uint4 tp);
  void set(uint4 tp,char *ptr,int4 len);
  void setPosition(int4 file,int4 line,int4 col) { filenum=file; lineno=line; colno=col; }
public:
  GrammarToken(void);
  uint4 getType(void) const { return type; }
  uintb getInteger(void) const { return value.integer; }
  std::string *getString(void) const { return value.stringval; }
  int4 getLineNo(void) const { return lineno; }
  int4 getColNo(void) const { return colno; }
  int4 getFileNum(void) const { return filenum; }
};

class GrammarLexer {
  std::map<int4,std::string> filenamemap;	// All files ever seen
  std::map<int4,std::istream *> streammap;
  std::vector<int4> filestack;	// Stack of current files
  int4 buffersize;		// maximum characters in buffer
  char *buffer;			// Current line being processed
  int4 bufstart;		// Next character to process
  int4 bufend;			// Next open position in buffer
  int4 curlineno;
  std::istream *in;			// Current stream
  bool endoffile;
  uint4 state;			// State of parser
  std::string error;
  enum {
    start,
    slash,
    dot1,
    dot2,
    dot3,
    punctuation,
    endofline_comment,
    c_comment,
    doublequote,
    doublequoteend,
    singlequote,
    singlequoteend,
    singlebackslash,
    number,
    identifier
  };
  void bumpLine(void);
  uint4 moveState(char lookahead);
  void establishToken(GrammarToken &token,uint4 val);
  void setError(const std::string &err) { error = err; }
public:
  GrammarLexer(int4 maxbuffer);
  ~GrammarLexer(void);
  void clear(void);
  std::istream *getCurStream(void) { return in; }
  void pushFile(const std::string &filename,std::istream *i);
  void popFile(void);
  void getNextToken(GrammarToken &token);
  void writeLocation(std::ostream &s,int4 line,int4 filenum);
  void writeTokenLocation(std::ostream &s,int4 line,int4 colno);
  const std::string &getError(void) const { return error; }
};

class TypeDeclarator;		// Forward declaration

class TypeModifier {
public:
  enum {
    pointer_mod,
    array_mod,
    function_mod,
    struct_mod,
    enum_mod
  };
  virtual ~TypeModifier(void) {}
  virtual uint4 getType(void) const=0;
  virtual bool isValid(void) const=0;
  virtual Datatype *modType(Datatype *base,const TypeDeclarator *decl,Architecture *glb) const=0;
};

class PointerModifier : public TypeModifier {
  uint4 flags;
public:
  PointerModifier(uint4 fl) { flags = fl; }
  virtual uint4 getType(void) const { return pointer_mod; }
  virtual bool isValid(void) const { return true; }
  virtual Datatype *modType(Datatype *base,const TypeDeclarator *decl,Architecture *glb) const;
};

class ArrayModifier : public TypeModifier {
  uint4 flags;
  int4 arraysize;
public:
  ArrayModifier(uint4 fl,int4 as) { flags=fl; arraysize = as; }
  virtual uint4 getType(void) const { return array_mod; }
  virtual bool isValid(void) const { return (arraysize>0); }
  virtual Datatype *modType(Datatype *base,const TypeDeclarator *decl,Architecture *glb) const;
};

class FunctionModifier : public TypeModifier {
  std::vector<TypeDeclarator *> paramlist;
  bool dotdotdot;
public:
  FunctionModifier(const std::vector<TypeDeclarator *> *p,bool dtdtdt);
  void getInTypes(std::vector<Datatype *> &intypes,Architecture *glb) const;
  void getInNames(std::vector<std::string> &innames) const;
  bool isDotdotdot(void) const { return dotdotdot; }
  virtual uint4 getType(void) const { return function_mod; }
  virtual bool isValid(void) const;
  virtual Datatype *modType(Datatype *base,const TypeDeclarator *decl,Architecture *glb) const;
};

class TypeDeclarator {
  friend class CParse;
  std::vector<TypeModifier *> mods;
  Datatype *basetype;
  std::string ident;			// variable identifier associated with type
  std::string model;			// name of model associated with function pointer
  uint4 flags;			// Specifiers qualifiers
public:
  TypeDeclarator(void) { basetype=(Datatype *)0; flags=0; }
  TypeDeclarator(const std::string &nm) { ident=nm; basetype=(Datatype *)0; flags=0; }
  ~TypeDeclarator(void);
  Datatype *getBaseType(void) const { return basetype; }
  int4 numModifiers(void) const { return mods.size(); }
  const std::string &getIdentifier(void) const { return ident; }
  ProtoModel *getModel(Architecture *glb) const;
  bool getPrototype(PrototypePieces &pieces,Architecture *glb) const;
  bool hasProperty(uint4 mask) { return ((flags&mask)!=0); }
  Datatype *buildType(Architecture *glb) const;
  bool isValid(void) const;
};

struct TypeSpecifiers {
  Datatype *type_specifier;
  std::string function_specifier;
  uint4 flags;
  TypeSpecifiers(void) { type_specifier = (Datatype *)0; flags = 0; }
};

struct Enumerator {
  std::string enumconstant;		// Identifier associated with constant
  bool constantassigned;	// True if user specified explicit constant
  uintb value;			// The actual constant
  Enumerator(const std::string &nm) { constantassigned = false; enumconstant = nm; }
  Enumerator(const std::string &nm,uintb val) { constantassigned = true; enumconstant=nm; value=val; }
};

class CParse {
public:
  enum {
    f_typedef = 1,
    f_extern = 2,
    f_static = 4,
    f_auto = 8,
    f_register = 16,
    f_const = 32,
    f_restrict = 64,
    f_volatile = 128,
    f_inline = 256,
    f_struct = 512,
    f_union = 1024,
    f_enum = 2048
  };
  enum {
    doc_declaration,
    doc_parameter_declaration
  };
private:
  Architecture *glb;
  std::map<std::string,uint4> keywords;
  GrammarLexer lexer;
  int4 lineno,colno,filenum;	// Location of last token
  std::list<TypeDeclarator *> typedec_alloc;
  std::list<TypeSpecifiers *> typespec_alloc;
  std::list<std::vector<uint4> *> vecuint4_alloc;
  std::list<std::vector<TypeDeclarator *> *> vecdec_alloc;
  std::list<std::string *> string_alloc;
  std::list<uintb *> num_alloc;
  std::list<Enumerator *> enum_alloc;
  std::list<std::vector<Enumerator *> *> vecenum_alloc;

  std::vector<TypeDeclarator *> *lastdecls;
  int4 firsttoken;		// Message to parser indicating desired object
  std::string lasterror;
  void setError(const std::string &msg);
  int4 lookupIdentifier(const std::string &nm);
  bool runParse(uint4 doctype);
public:
  CParse(Architecture *g,int4 maxbuf);
  ~CParse(void);
  void clear(void);
  std::vector<TypeDeclarator *> *mergeSpecDecVec(TypeSpecifiers *spec);
  std::vector<TypeDeclarator *> *mergeSpecDecVec(TypeSpecifiers *spec,std::vector<TypeDeclarator *> *declist);
  TypeDeclarator *mergeSpecDec(TypeSpecifiers *spec);
  TypeDeclarator *mergeSpecDec(TypeSpecifiers *spec,TypeDeclarator *dec);
  TypeSpecifiers *addSpecifier(TypeSpecifiers *spec,std::string *str);
  TypeSpecifiers *addTypeSpecifier(TypeSpecifiers *spec,Datatype *tp);
  TypeSpecifiers *addFuncSpecifier(TypeSpecifiers *spec,std::string *str);
  TypeDeclarator *mergePointer(std::vector<uint4> *ptr,TypeDeclarator *dec);
  TypeDeclarator *newDeclarator(std::string *str);
  TypeDeclarator *newDeclarator(void);
  TypeSpecifiers *newSpecifier(void);
  std::vector<TypeDeclarator *> *newVecDeclarator(void);
  std::vector<uint4> *newPointer(void);
  TypeDeclarator *newArray(TypeDeclarator *dec,uint4 flags,uintb *num);
  TypeDeclarator *newFunc(TypeDeclarator *dec,std::vector<TypeDeclarator *> *declist);
  Datatype *newStruct(const std::string &ident,std::vector<TypeDeclarator *> *declist);
  Datatype *oldStruct(const std::string &ident);
  Datatype *newUnion(const std::string &ident,std::vector<TypeDeclarator *> *declist);
  Datatype *oldUnion(const std::string &ident);
  Enumerator *newEnumerator(const std::string &ident);
  Enumerator *newEnumerator(const std::string &ident,uintb val);
  std::vector<Enumerator *> *newVecEnumerator(void);
  Datatype *newEnum(const std::string &ident,std::vector<Enumerator *> *vecenum);
  Datatype *oldEnum(const std::string &ident);
  uint4 convertFlag(std::string *str);

  void clearAllocation(void);
  int4 lex(void);

  bool parseFile(const std::string &filename,uint4 doctype);
  bool parseStream(std::istream &s,uint4 doctype);

  const std::string &getError(void) const { return lasterror; }
  void setResultDeclarations(std::vector<TypeDeclarator *> *val) { lastdecls = val; }
  std::vector<TypeDeclarator *> *getResultDeclarations(void) { return lastdecls; }
};

extern Datatype *parse_type(std::istream &s,std::string &name,Architecture *glb);
extern void parse_protopieces(PrototypePieces &pieces,std::istream &s,Architecture *glb);
extern void parse_C(Architecture *glb,std::istream &s);

// Routines to parse interface commands

extern void parse_toseparator(std::istream &s,std::string &name);
extern Address parse_machaddr(std::istream &s,int4 &defaultsize,const TypeFactory &typegrp,bool ignorecolon=false);
extern Address parse_varnode(std::istream &s,int4 &size,Address &pc,uintm &uq,const TypeFactory &typegrp);
extern Address parse_op(std::istream &s,uintm &uq,const TypeFactory &typegrp);

#endif
