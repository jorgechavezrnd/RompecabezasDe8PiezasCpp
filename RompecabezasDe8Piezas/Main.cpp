#include "Puzzle.h"
#include "Grafo.h"

using namespace std;

int main()
{
	Puzzle p	{
					{ 4, 1, 3 },
					{ 6, 0, 5 },
					{ 7, 2, 8 }
				};

	p.setFinalState({ 
						{ 1, 2, 3 }, 
						{ 4, 0, 5 }, 
						{ 6, 7, 8 } 
					});

	cout << p << endl;
	p.move(UP);
	cout << p << endl;
	p.move(LEFT);
	cout << p << endl;
	p.move(DOWN);
	cout << p << endl;
	p.move(RIGHT);
	cout << p << endl;

	p.showInitialState();
	cout << endl;
	p.showFinalState();
	cout << endl;

	Grafo<Matrix> g(10);

	Matrix m1 = { {1,2,3},{4,5,6},{7,8,9} };
	Matrix m2 = { {9,8,7},{6,5,4},{3,2,1} };



	return 0;
}