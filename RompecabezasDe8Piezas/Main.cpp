#include "Puzzle.h"

using namespace std;

int main()
{
	Puzzle p	{
					{ 4, 1, 3 },
					{ 6, 0, 5 },
					{ 7, 2, 8 }
				};

	p.setFinalState({ 
						{1, 2, 3}, 
						{4, 0, 5}, 
						{6, 7, 8} 
					});

	cout << p << endl;
	p.moveUp();
	cout << p << endl;
	p.moveLeft();
	cout << p << endl;
	p.moveDown();
	cout << p << endl;
	p.moveRight();
	cout << p << endl;

	p.showInitialState();
	cout << endl;
	p.showFinalState();
	cout << endl;

	return 0;
}