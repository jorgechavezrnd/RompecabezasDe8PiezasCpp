#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <initializer_list>
#include "Matrix.h"

class Puzzle
{
	friend std::ostream & operator << (std::ostream & o, const Puzzle & p);

public:
	Puzzle();
	Puzzle(std::initializer_list<std::initializer_list<int>> newPuzzle);
	~Puzzle();
	void setFinalState(std::initializer_list<std::initializer_list<int>> finalState);
	void showInitialState();
	void showFinalState();

	void moveUp();
	void moveLeft();
	void moveDown();
	void moveRight();

private:
	Matrix boxes;
	Matrix initial_state;
	Matrix final_state;
	int empty_box_row;
	int empty_box_column;
};

#endif