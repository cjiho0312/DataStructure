#include <iostream>
#define SIZE 10
using namespace std;

template <typename T>
class AdjacencyList
{
private:

	struct Node
	{
		T data;
		Node* next;

		Node(T data, Node* link = nullptr)
		{
			this->data = data;
			next = link;
		}
	};

	int size;
	T vertex[SIZE]; // 집합
	Node* list[SIZE]; // 리스트

public:

	AdjacencyList()
	{
		size = 0;
		
		for (int i = 0; i < SIZE; i++)
		{
			vertex[i] = NULL;
			list[i] = NULL;
		}
	}

	void push(T data)
	{
		if (size >= SIZE)
		{
			cout << "Adjacency list overflow" << endl;
		}
		else
		{
			vertex[size++] = data;
		}
	}

	void edge(int i, int j)
	{
		if (size <= 0)
		{
			cout << "adjancency list is empty" << endl;
		}
		else if (i >= size || j >= size)
		{
			cout << "index out of range" << endl;
		}
		else
		{
			list[i] = new Node(vertex[j], list[i]);
			list[j] = new Node(vertex[i], list[j]);
		}
	}

	~AdjacencyList()
	{
		// for (int i = 0; i < SIZE; i++)
		// {
		// 		if (list[i] != nullptr)
		// 		{
		// 			delete[] list[i];
		// 		}
		// }
	}
};

int main()
{
	AdjacencyList<char> A;

	A.push('A');
	A.push('B');
	A.push('C');

	A.edge(0, 1);

	return 0;
}