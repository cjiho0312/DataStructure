#include <iostream>

using namespace std;

template <typename T>
class Set
{
private:

	struct Node
	{
		T data;

		Node* left;
		Node* right;
	};

	int size;
	Node* root;

public:
	Set()
	{
		size = 0;
		root = nullptr;
	}

	Node* create_node(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->left = nullptr;
		newNode->right = nullptr;

		size++;

		return newNode;
	}

	void insert(T data)
	{
		if (root == nullptr)
		{
			root = create_node(data);
		}
		else
		{
			Node* currentNode = root;

			while (currentNode != nullptr)
			{
				if (currentNode->data == data)
				{
					return;
				}
				else if (currentNode->data > data)
				{
					if (currentNode->left == nullptr)
					{
						currentNode->left = create_node(data);

						return;
					}
					else
					{
						currentNode = currentNode->left;
					}
				}
				else
				{
					if (currentNode->right == nullptr)
					{
						currentNode->right = create_node(data);

						return;
					}
					else
					{
						currentNode = currentNode->right;
					}
				}
			}
		}
	}

	// void insert(T data)
	// {
	// 	Node* newNode = new Node;
	// 	newNode->data = data;
	// 	newNode->left = nullptr;
	// 	newNode->right = nullptr;
	// 
	// 	if (root == nullptr)
	// 	{
	// 		root = newNode;
	// 	}
	// 	else
	// 	{
	// 		Node* currentNode = root;
	// 
	// 		while (currentNode != nullptr)
	// 		{
	// 			if (data == currentNode->data)
	// 			{
	// 				cout << "Already got same data" << endl;
	// 
	// 				delete newNode;
	// 				return;
	// 			}
	// 			if (data > currentNode->data)
	// 			{
	// 				currentNode = currentNode->right;
	// 			}
	// 			else if (data < currentNode->data)
	// 			{
	// 				currentNode = currentNode->left;
	// 			}
	// 		}
	// 
	// 		newNode = currentNode;
	// 		size ++;
	// 	}
	// }

	void release(Node* root)
	{
		if (root != nullptr)
		{
			release(root->left);

			release(root->right);

			delete root;
		}
	}

	void erase(T data)
	{
		Node* currentNode = root;
		Node* parentNode = nullptr;

		while (currentNode != nullptr && currentNode->data != data)
		{
			parentNode = currentNode;

			if (currentNode->data > data)
			{
				currentNode = currentNode->left;
			}
			else
			{
				currentNode = currentNode->right;
			}
		}

		if (currentNode == nullptr)
		{
			cout << "the data does not exist" << endl;
		}


		else if (currentNode->left == nullptr && currentNode->right == nullptr)
			// 자식 0개
		{
			if (parentNode != nullptr)
			{
				if (parentNode->left == currentNode)
				{
					parentNode->left = nullptr;
				}
				else
				{
					parentNode->right = nullptr;
				}
			}
			else
			{
				root = nullptr;
			}

			delete currentNode;
		}

		else if (currentNode->right != nullptr || currentNode->left != nullptr)
		{
			if (parentNode == nullptr)
			{
				if (currentNode->left != nullptr)
				{
					root = currentNode->left;
				}
				else
				{
					root = currentNode->right;
				}
			}
			else if (currentNode->left != nullptr)
			{
				parentNode->left = currentNode->left;
			}
			else if (currentNode->right != nullptr)
			{
				parentNode->right = currentNode->right;
			}

			delete currentNode;
		}

		else if (currentNode->left != nullptr && currentNode->right != nullptr)
		{
			Node* childNode = currentNode->right;
			Node* traceNode = currentNode;

			while (childNode->left != nullptr)
			{
				traceNode = childNode;
				childNode = childNode->left;
			}

			currentNode->data = childNode->data;

			traceNode->left = childNode->right;

			delete childNode;

			return;
		}
	}

	void inorder()
	{
		inorder(root);
	}

	void inorder(Node* root)
	{
		if (root != nullptr)
		{
			inorder(root->left);

			cout << root->data << " ";

			inorder(root->right);
		}
	}

	~Set()
	{
		//release(root);
	}

};

int main()
{
	Set<int> set;

	set.insert(10);
	set.insert(5);
	set.insert(15);
	set.insert(20);
	set.insert(12);

	set.erase(15);

	set.inorder();

	return 0;
}