#pragma once
#include <vector>
#include <boost/tokenizer.hpp>

class Matrix
{
public:
	Matrix(std::string const& matrix2DString, int row, int column) : row(row), column(column)
	{
		matrix = MakeMatrixFromTheString(matrix2DString);
	}

	Matrix(){}

	std::string multiplication (Matrix const& firstMatrix, Matrix const& secondMatrix);

private:
	std::vector<std::vector<int>> MakeMatrixFromTheString (std::string const& matrix2DString);
	std::vector<std::vector<int>> matrix;
	int row, column;
};

