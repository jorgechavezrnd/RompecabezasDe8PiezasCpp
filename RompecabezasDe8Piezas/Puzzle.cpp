#include "Puzzle.h"
using std::ostream;
using std::initializer_list;
using std::cout;

Puzzle::Puzzle()
{
	int value = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			boxes[i][j] = initial_state[i][j] = value++;
		}
	}

	empty_box_row = empty_box_column = 0;

	final_state[0][0] = 1; final_state[0][1] = 2; final_state[0][2] = 3;
	final_state[1][0] = 4; final_state[1][1] = 0; final_state[1][2] = 5;
	final_state[2][0] = 6; final_state[2][1] = 7; final_state[2][2] = 8;
}

Puzzle::Puzzle(initializer_list<initializer_list<int>> newPuzzle)
{
	int r, c;
	r = c = 0;

	for (initializer_list<initializer_list<int>>::iterator i = newPuzzle.begin(); i != newPuzzle.end(); i++)
	{
		for (initializer_list<int>::iterator j = i->begin(); j != i->end(); j++)
		{
			if (*j == 0)
			{
				empty_box_row = r;
				empty_box_column = c;
			}
			boxes[r][c] = *j;
			initial_state[r][c++] = *j;
		}
		c = 0;
		++r;
	}
}

Puzzle::~Puzzle()
{
	// EMPTY
}

void Puzzle::setFinalState(std::initializer_list<std::initializer_list<int>> finalState)
{
	int r, c;
	r = c = 0;

	for (initializer_list<initializer_list<int>>::iterator i = finalState.begin(); i != finalState.end(); i++)
	{
		for (initializer_list<int>::iterator j = i->begin(); j != i->end(); j++)
		{
			final_state[r][c++] = *j;
		}
		c = 0;
		++r;
	}
}

void Puzzle::showInitialState()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << initial_state[i][j] << "\t";
		}
		cout << "\n";
	}
}

void Puzzle::showFinalState()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << final_state[i][j] << "\t";
		}
		cout << "\n";
	}
}

void Puzzle::moveUp()
{
	--empty_box_row;
	boxes[empty_box_row + 1][empty_box_column] = boxes[empty_box_row][empty_box_column];
	boxes[empty_box_row][empty_box_column] = 0;
}

void Puzzle::moveLeft()
{
	--empty_box_column;
	boxes[empty_box_row][empty_box_column + 1] = boxes[empty_box_row][empty_box_column];
	boxes[empty_box_row][empty_box_column] = 0;
}

void Puzzle::moveDown()
{
	++empty_box_row;
	boxes[empty_box_row - 1][empty_box_column] = boxes[empty_box_row][empty_box_column];
	boxes[empty_box_row][empty_box_column] = 0;
}

void Puzzle::moveRight()
{
	++empty_box_column;
	boxes[empty_box_row][empty_box_column - 1] = boxes[empty_box_row][empty_box_column];
	boxes[empty_box_row][empty_box_column] = 0;
}

ostream & operator << (ostream & o, const Puzzle & p)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			o << p.boxes[i][j] << "\t";
		}
		o << "\n";
	}

	return o;
}