CC = g++
CFLAGS = -O2 -std=c++17 -g

vpath /Users/stone/Documents/Compiler

main: wordAnalysis.l grammar.y tree.cpp
	flex --noyywrap wordAnalysis.l
	yacc -d grammar.y
	$(CC) ${CFLAGS} y.tab.c lex.yy.c tree.cpp -o sysyc

runGrammar:
	./sysyc -dot ./Test/test.sy ./Output/test.dot
	dot -Tpng -o ./Output/test.png ./Output/test.dot

runAsm:
	./sysyc -s ./Test/test.sy ./Output/test.s
	cat ./Output/test.s

allGrammar: main runGrammar

allAsm: main runAsm

runTest:
	gcc ./Output/test.s -o ./Build/test
	./Build/test

clean:
	$(RM) y.tab.* lex.yy.* sysyc ./Output/test.*
