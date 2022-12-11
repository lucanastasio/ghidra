bison -l -o grammar.cc grammar.y
bison -l -o pcodeparse.cc pcodeparse.y
bison -l -H -o slghparse.cc slghparse.y
lex -L -o slghscan.cc slghscan.l
bison -l -o xml.cc xml.y
