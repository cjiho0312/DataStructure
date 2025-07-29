#include <iostream>

using namespace std;

template <typename T>
class AdjacencyMatrix
{
private:
	int size;
	int capacity;
	int matrixCount;
	T* vertex;
	T** matrix;

public:
	AdjacencyMatrix()
	{
		size = 0;
		capacity = 0;
		matrixCount = 0;
		vertex = nullptr;
		matrix = nullptr;
	}

	void resize(int newSize)
	{
		capacity = newSize;

		T* temp = new T[capacity];

		for (int i = 0; i < newSize; i++)
		{
			temp[i] = NULL;
		}

		for (int i = 0; i < size; i++)
		{
			vertex[i] = temp[i];
		}

		if (vertex != nullptr)
		{
			delete[] vertex;
		}

		vertex = temp;
	}

	void resize()
	{
		int** newMatrix = new int* [size];

		for (int i = 0; i < size; i++)
		{
			newMatrix[i] = new int[size] {0};
		}

		for (int i = 0; i < matrixCount; i++)
		{
			for (int j = 0; j < size; j++)
			{
				newMatrix[i][j] = matrix[i][j];
			}
		}

		if (matrix != nullptr)
		{
			for (int i = 0; i < matrixCount; i++)
			{
				delete[] matrix[i];
			}

			delete[] matrix;
		}

		matrix = newMatrix;

		matrixCount = size;
	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (size >= capacity)
		{
			resize(capacity * 2);
		}

		vertex[size++] = data;

	}

	void edge(int i, int j)
	{
		if (size <= 0)
		{
			cout << "adjancency matrix is empty" << endl;
		}
		else if (i >= size || j >= size)
		{
			cout << "index out of range" << endl;
		}

		else
		{
			if (matrix == nullptr)
			{
				matrixCount = size;

				matrix = new int* [size];

				for (int i = 0; i < size; i++)
				{
					matrix[i] = new int[size];
				}

				for (int i = 0; i < size; i++)
				{
					for (int j = 0; j < size; j++)
					{
						matrix[i][j] = 0;
					}
				}
			}

			else if (matrixCount < size)
			{
				resize();
			}

			matrix[i][j] = 1;
			matrix[j][i] = 1;
		}
	}

	~AdjacencyMatrix()
	{
		if (matrix != nullptr)
		{
			for (int i = 0; i < matrixCount; i++)
			{
				delete[] matrix[i];
			}
			delete[] matrix;
		}
		delete[] vertex;
	}

	template <typename T>
	friend ostream& operator << (ostream& ostream, const AdjacencyMatrix<T>& a)
	{
		for (int i = 0; i < a.matrixCount; i++)
		{
			for (int j = 0; j < a.matrixCount; j++)
			{
				cout << a.matrix[i][j] << " ";
			}

			ostream << endl;
		}

		return ostream;
	}

};

int main()
{
	AdjacencyMatrix<int> A;

	A.push(5);
	A.push(7);
	A.push(12);
	A.push(15);

	A.edge(0, 1);
	A.edge(1, 3);

	cout << A << endl;

	return 0;
}