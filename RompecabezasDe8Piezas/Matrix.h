#ifndef MATRIX_H
#define MATRIX_H

#include <initializer_list>
#include <iostream>

class Matrix
{
	friend std::ostream & operator << (std::ostream & o, const Matrix & m);

public:
	Matrix();
	Matrix(const Matrix & matrixToCopy);
	Matrix(std::initializer_list<std::initializer_list<int>> newMatrix);
	~Matrix();

	const Matrix & operator = (const Matrix & right);

	bool operator == (const Matrix & right) const;
	bool operator != (const Matrix & right) const { return !(*this == right); }

	int* operator [] (const int & row);
	const int* operator [] (const int & row) const;

private:
	int boxes[3][3];
};

#endif // !MATRIX_H
