#include <iostream>
#define SIZE 6

using namespace std;

template <typename KEY, typename VALUE>
class HashTable
{
private :

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
	const int & hash_function(T key)
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
		Node * newNode = created_node(key, value);

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
	hashtable.insert("Horse", 1000);

	return 0;
}