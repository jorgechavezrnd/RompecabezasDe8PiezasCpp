#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <initializer_list>

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
	int boxes[3][3];
	int initial_state[3][3];
	int final_state[3][3];
	int empty_box_row;
	int empty_box_column;
};

#endif