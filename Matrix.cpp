#include "pch.h"
#include "Matrix.h"
#include <iostream>

std::string Matrix::multiplication(Matrix const& firstMatrix, Matrix const& secondMatrix)
{
	if (firstMatrix.column == secondMatrix.row) {
		std::vector<std::vector<int>> resultMatrix(firstMatrix.row, std::vector<int>(secondMatrix.column, 0));

		for (int i = 0; i < firstMatrix.row; ++i)
		{
			for (int j = 0; j < secondMatrix.column; ++j)
			{
				for (int k = 0; k < firstMatrix.column; ++k) {
					resultMatrix[i][j] += firstMatrix.matrix[i][k] * secondMatrix.matrix[k][j];
				}
			}
		}

		std::string result;
		for (auto& rows : resultMatrix)
		{
			for (auto& tables : rows)
			{
				result += std::to_string(tables) + ' ';
			}
			result += "\r\n";
		}
		return result;
	}
}


std::vector<std::vector<int>> Matrix::MakeMatrixFromTheString(std::string const& matrix2DString)
{
	std::vector<std::vector<int>> readyMatrix (row, std::vector<int>(column, 0));
	boost::char_separator<char> sep(",");
	boost::tokenizer<boost::char_separator<char>> tok(matrix2DString, sep);
	for (auto it = tok.begin(); it != tok.end();) {
		for (int i = 0; i < row; ++i)
		{
			for(int j = 0; j < column; ++j)
			{
				readyMatrix[i][j] = stoi(*it++);
			}
		}
		
	}
	return readyMatrix;
}