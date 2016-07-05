#this target will compile all the files
all: run
	
run: main.o CommandProcessor.o Menu.o
		g++ -std=c++11 main.cpp CommandProcessor.cpp Menu.cpp tinyxml.cpp 				tinyxmlerror.cpp tinyxmlparser.cpp -o Run

main.o: main.cpp CommandProcessor.cpp Menu.cpp
		g++ -std=c++11  main.cpp CommandProcessor.cpp Menu.cpp tinyxml.cpp 				tinyxmlerror.cpp tinyxmlparser.cpp

CommandProcessor.o: main.cpp CommandProcessor.cpp Menu.cpp TreeNode.h GeneralTree.h AVLTree.h Heap.h
		g++ -std=c++11 main.cpp CommandProcessor.cpp Menu.cpp tinyxml.cpp 				tinyxmlerror.cpp tinyxmlparser.cpp tinyxml.h GeneralTree.h AVLTree.h TreeNode.h Heap.h

Menu.o: Menu.cpp CommandProcessor.cpp main.cpp tinyxml.cpp 				tinyxmlerror.cpp tinyxmlparser.cpp
	g++ -std=c++11 Menu.cpp CommandProcessor.cpp main.cpp tinyxml.cpp 				tinyxmlerror.cpp tinyxmlparser.cpp

Clean:
	rm -rf *o run
