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
/// \file loadimage_xml.hh
/// \brief Support for programs stored using an XML schema

#ifndef __LOADIMAGE_XML__
#define __LOADIMAGE_XML__

#include "loadimage.hh"

extern AttributeId ATTRIB_ARCH;		///< Marshaling attribute "arch"

extern ElementId ELEM_BINARYIMAGE;	///< Marshaling element \<binaryimage>
extern ElementId ELEM_BYTECHUNK;	///< Marshaling element \<bytechunk>

/// \brief Implementation of the LoadImage interface using underlying data stored in an XML format
///
/// The image data is stored in an XML file in a \<binaryimage> file.
/// The data is encoded in \<bytechunk> and potentially \<symbol> files.
class LoadImageXml : public LoadImage {
  const Element *rootel;			///< The root XML element
  std::string archtype;				///< The architecture string
  const AddrSpaceManager *manage;		///< Manager of addresses
  std::set<Address> readonlyset;			///< Starting address of read-only chunks
  std::map<Address,std::vector<uint1> > chunk;		///< Chunks of image data, mapped by address
  std::map<Address,std::string> addrtosymbol;		///< Symbols sorted by address
  mutable std::map<Address,std::string>::const_iterator cursymbol;	///< Current symbol being reported
  void pad(void);			///< Make sure every chunk is followed by at least 512 bytes of pad
public:
  LoadImageXml(const std::string &f,const Element *el);	///< Constructor
  void open(const AddrSpaceManager *m);		///< Read XML tags into the containers
  void clear(void);				///< Clear out all the caches
  void encode(Encoder &encoder) const;		///< Encode the image to a stream
  virtual ~LoadImageXml(void) { clear(); }
  virtual void loadFill(uint1 *ptr,int4 size,const Address &addr);
  virtual void openSymbols(void) const;
  virtual bool getNextSymbol(LoadImageFunc &record) const;
  virtual void getReadonly(RangeList &list) const;
  virtual std::string getArchType(void) const { return archtype; }
  virtual void adjustVma(long adjust);
};

#endif
