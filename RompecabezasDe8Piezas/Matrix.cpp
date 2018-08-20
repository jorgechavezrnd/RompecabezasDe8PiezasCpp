#include "Matrix.h"
using std::initializer_list;
using std::ostream;

Matrix::Matrix()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			boxes[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix & matrixToCopy)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			boxes[i][j] = matrixToCopy.boxes[i][j];
		}
	}
}

Matrix::Matrix(initializer_list<initializer_list<int>> newMatrix)
{
	int r, c;
	r = c = 0;

	for (initializer_list<initializer_list<int>>::iterator i = newMatrix.begin(); i != newMatrix.end(); ++i)
	{
		for (initializer_list<int>::iterator j = i->begin(); j != i->end(); ++j)
		{
			boxes[r][c] = *j;
			++c;
		}
		c = 0;
		++r;
	}
}

Matrix::~Matrix()
{
	// EMPTY
}

const Matrix & Matrix::operator = (const Matrix & right)
{
	if (&right != this)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				boxes[i][j] = right.boxes[i][j];
			}
		}
	}

	return *this;
}

bool Matrix::operator == (const Matrix & right) const
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (boxes[i][j] != right.boxes[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

int* Matrix::operator [] (const int & row)
{
	return boxes[row];
}

const int* Matrix::operator [] (const int & row) const
{
	return boxes[row];
}

ostream & operator << (ostream & o, const Matrix & m)
{
	o << "{ { " << m.boxes[0][0] << ", " << m.boxes[0][1] << ", " << m.boxes[0][2] << " },";
	o << "{ " << m.boxes[1][0] << ", " << m.boxes[1][1] << ", " << m.boxes[1][2] << " },";
	o << "{ " << m.boxes[2][0] << ", " << m.boxes[2][1] << ", " << m.boxes[2][2] << " } }";

	return o;
}