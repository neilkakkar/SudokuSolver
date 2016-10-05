all: sudokuSolver.h sudokuSolver.cpp main.cpp
	g++ -o sudokuSolver sudokuSolver.cpp sudokuSolver.h main.cpp -I.

clear:
	rm sudokuSolver