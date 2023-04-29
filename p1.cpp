#include<iostream>
#include<queue>
using namespace std;

template <class T>
class node
{
public:
	node<T>* left;
	node<T>* right;
	T Data;
	node() : Data(0), left(NULL), right(NULL) {}
	node(T d) : Data(d), left(NULL), right(NULL) {}
};

template <class T>
class BST
{
public:
	node<T>* root;
	BST() : root(NULL) {}
	void insert(T d)
	{
		node<T>* n = new node<T>(d);
		if (root == NULL)
		{
			root = n;
		}
		else
		{
			node<T>* ptr = root;
			while (ptr != NULL)
			{
				if (d < ptr->Data)
				{
					if (ptr->left == NULL)
					{
						ptr->left = n;
						return;
					}
					else
						ptr = ptr->left;
				}
				else
				{
					if (ptr->right == NULL)
					{
						ptr->right = n;
						return;
					}
					else
						ptr = ptr->right;
				}


			}
		}

	}

	void inorderTraversal(node<T>* root)
	{
		if (root != NULL)
		{
			inorderTraversal(root->left);
			cout << root->Data << " ";
			inorderTraversal(root->right);
		}
	}

	node<T>* search(T d)
	{
		node<T>* ptr = root;
		node<T>* parent = 0;

		while (ptr != NULL)
		{
			if (d == ptr->Data)
			{
				return ptr;
			}
			else if (d < ptr->Data)
			{
				parent = ptr;
				ptr = ptr->left;
			}
			else if (d > ptr->Data)
			{
				parent = ptr;
				ptr = ptr->right;
			}
		}
		return ptr;

	}

	node<T>* mini(node<T>* temp)const
	{
		node<T>* ptr = temp;
		if (ptr != NULL)
		{
			while (ptr->left != 0)
			{
				ptr = ptr->left;
			}
		}
		return(ptr);
	}

	node<T>* maxi(node<T>* temp)const
	{
		node<T>* ptr = temp;
		if (ptr != NULL)
		{
			while (ptr->right != 0)
			{
				ptr = ptr->right;
			}
		}
		return(ptr);

	}
	void deletenode(T d)
	{
	  root = deletenode(root, d);
	}

	node<T>* deletenode(node<T>* temp,T d)
	{

		//node<T>* temp = root;
		if (temp == NULL)
		{
			return temp;
		}
		else if (d > temp->Data)
		{
			temp->right = deletenode(temp->right, d);
		}
		else if (d < temp->Data)
		{
			temp->left = deletenode(temp->left, d);
		}
		else 
		{
			if (temp->left == NULL && temp->right == NULL)
			{
				delete temp;
				return NULL;
			}
			else if (temp->left != NULL && temp->right == NULL)
			{
				node<T>* temp2 = temp-> left;
				delete temp;
				return temp2;
			}
			else if (temp->left == NULL && temp->right != NULL)
			{
				node<T>* temp2 = temp-> right;
				delete temp;
				return temp2;
			}
			else 
			{
				node<T>* temp2 = mini(temp->right);
				temp->Data = temp2->Data;
				temp->right = deletenode(temp->right, temp2->Data);
			}
		}



		//node<T>* parent = 0;

		/*while (ptr != NULL)
		{
			if (d == ptr->Data)
			{
				break;
			}
			else if (d < ptr->Data)
			{
				parent = ptr;
				ptr = ptr->left;
			}
			else if (d > ptr->Data)
			{
				parent = ptr;
				ptr = ptr->right;
			}
		}
		if (ptr == NULL) {
			cout << "Data not found luhser!" << endl;
		}

		if ((ptr->left == 0) && (ptr->right == 0))
		{
			if (parent->left == ptr)
			{
				parent->left = 0;
			}
			if (parent->right == ptr)
			{
				parent->right = 0;
			}
			delete ptr;
			ptr = NULL;
		}

		else if (ptr->left == NULL)
		{
			if (parent->left == ptr)
			{
				parent->left = ptr->right;
			}
			else
			{
				parent->right = ptr->right;
			}
			delete ptr;
			ptr = NULL;
		}

		else if (ptr->right == NULL)
		{
			if (parent->left == ptr)
			{
				parent->left = ptr->left;
			}
			else
			{
				parent->right = ptr->left;
			}
			delete ptr;
			ptr = NULL;

		}

		else if (ptr->right != NULL && ptr->left != NULL)
		{
			node<T>* minimum = mini(ptr->right);

			if (parent->left == ptr)
			{
				if (minimum == ptr->right)
				{
					parent->left = minimum;
				}
				else
				{
					parent->left = minimum;
					minimum->right = ptr->right;
					minimum->left = ptr->left;
				}

			}

			if (parent->right == ptr)
			{
				if (minimum == ptr->right)
				{
					parent->right = minimum;
				}
				else
				{
					parent->right = minimum;
					minimum->right = ptr->right;
					minimum->left = ptr->left;
				}
			}
			delete ptr;
			ptr = NULL;
		}*/

      return temp;
	}

	void BFS(node<T>* base)
	{
		cout << "\nBreadth First Search: ";
		queue<node<T>*> s;
		s.push(base);
		while (!s.empty())
		{
			cout << s.front()->data << " ";
			if (s.front()->left != NULL)
			{
				s.push(s.front()->left);
			}
			if (s.front()->right != NULL)
			{
				s.push(s.front()->right);
			}
			s.pop();
		}
	}

	~BST()
	{
		deletenode(root->Data);
	}

};

int main()
{
	BST<int> b1;
	b1.insert(12);
	b1.insert(6);
	b1.insert(3);
	b1.insert(29);
	b1.insert(21);
	b1.insert(36);
	b1.insert(20);
	b1.inorderTraversal(b1.root);
	b1.deletenode(12);
	cout << endl;

	b1.inorderTraversal(b1.root);
}