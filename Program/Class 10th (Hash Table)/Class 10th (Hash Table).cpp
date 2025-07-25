#include <iostream>
#define SIZE 6

using namespace std;

template <typename KEY, typename VALUE>
class HashTable
{
private:

	struct Node
	{
		KEY key;
		VALUE value;
		Node* next;
	};

	struct Bucket
	{
		int count;
		Node* head;
	};

	Bucket bucket[SIZE];

public:

	HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
	}

	template <typename T>
	const int& hash_function(T key)
	{
		unsigned int index = (unsigned int)key % SIZE;

		return index;
	}

	Node* created_node(KEY key, VALUE value)
	{
		Node* newNode = new Node;
		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;

		return newNode;
	}

	void insert(KEY key, VALUE value)
	{
		int hashIndex = hash_function(key);
		Node* newNode = created_node(key, value);

		if (bucket[hashIndex].count == 0)
		{
			bucket[hashIndex].head = newNode;
		}
		else
		{
			newNode->next = bucket[hashIndex].head;
			bucket[hashIndex].head = newNode;
		}

		bucket[hashIndex].count++;
	}

	void erase(KEY key)
	{
		int hashIndex = hash_function(key);

		bool CantFind = true;

		Node* currentNode = bucket[hashIndex].head;
		Node* previousNode = nullptr;

		while (currentNode != nullptr)
		{

			if (currentNode == bucket[hashIndex].head)
			{
				if (currentNode->key == key)
				{
					bucket[hashIndex].head = currentNode->next;
					delete currentNode;
					currentNode = bucket[hashIndex].head;
					CantFind = false;
				}

				else
				{
					previousNode = currentNode;
					currentNode = currentNode->next;
				}
			}

			else
			{
				if (currentNode->key == key)
				{
					previousNode->next = currentNode->next;
					delete currentNode;
					currentNode = previousNode->next;
					CantFind = false;
				}

				else
				{
					previousNode = currentNode;
					currentNode = currentNode->next;
				}
			}
		}


		if (CantFind == true)
		{
			cout << "Not Key Found" << endl;
		}
	}

	~HashTable()
	{
		Node* deleteNode;
		Node* nextNode;

		for (int i = 0; i < SIZE; i++)
		{
			deleteNode = bucket[i].head;
			nextNode = bucket[i].head;

			while (nextNode != nullptr)
			{
				nextNode = deleteNode->next;

				delete deleteNode;

				deleteNode = nextNode;
			}

		}
	}
};


int main()
{
	HashTable <const char*, int> hashtable;

	hashtable.insert("Snake", 500);
	hashtable.insert("Tiger", 2000);
	hashtable.insert("Tiger", 3000);
	hashtable.insert("Horse", 1000);

	hashtable.erase("Tiger");
	hashtable.erase("Tiger"); // Not Key Found

	return 0;
}