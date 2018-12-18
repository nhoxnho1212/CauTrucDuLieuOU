#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <stack>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

class BST
{
private:
	node** root;
	void insertNode(node* &Node,int data);
	void clear(node* &Node);
	void PrintLNR(const node*);
	node* Succes(node* data)
	{
		if (data == NULL)
			return NULL;
		if (data->right == NULL)
		{
			node* cur = *root;
			while (cur != NULL && cur->left)
			{
				if (cur->data > data->data)
				{
					cur = cur->left;
				}
				else
				{
					cur = cur->right;
				}
			}
			return cur;
		}
		node* cur = data->right;
		while (cur->left!=NULL)
		{
			cur = cur->left;
		}
		return cur;
	}
public:
	BST();
	~BST();
	void insert(int data);
	bool isEmpty();
	bool Delete(int data);
	bool Search(int data);
	void LNR();
};

//--------------------------------------
BST::BST()
{
	root = new node*;
	*root = NULL;
}

bool BST::isEmpty()
{
	if (*root == NULL)
		return true;
	return false;
}

void BST::insertNode(node* &Node, int data)
{
	if (Node == NULL)
	{
		Node = new node;
		Node->data = data;
		Node->left = NULL;
		Node->right = NULL;
		return;
	}
	if (Node->data > data) insertNode(Node->left, data);
	else insertNode(Node->right, data);
	return;
}

void BST::insert(int data)
{
	if (isEmpty())
	{
		node* newnode = new node;
		newnode->data = data;
		newnode->left = NULL;
		newnode->right = NULL;
		*root = new node;
		*root = newnode;
		return;
	}
	node* cur=*root;
	if (cur->data > data) insertNode(cur->left, data);
	else insertNode(cur->right,data);
}

bool BST::Delete(int Data)
{
	if (isEmpty())
	{
		return false;
	}
	
	node* cur = *root;
	node* parentCur = cur;
	while (cur != NULL)
	{		
		if (cur->data == Data)
		{
			break;
		}
		parentCur = cur;

		if (cur->data < Data)
		{
			cur = cur->right;
		}
		if (cur->data > Data)
		{
			cur = cur->left;
		}
	}
	if (cur == NULL)
		return false;
	//leaf
	if (cur->left == NULL && cur->right == NULL)
	{
		if (parentCur == cur)
		{
			delete cur;
			*root = NULL;
			return true;
		}
		if (parentCur->left == cur)
		{
			delete cur;
			parentCur->left = NULL;
			return true;
		}
		if (parentCur->right == cur)
		{
			delete cur;
			parentCur->right = NULL;
			return true;
		}
	}

	//node has 1 child
	if (cur->left == NULL)
	{
		if (parentCur->left == cur)
		{
			parentCur->left = cur->right;
			delete cur;
			return true;
		}
		if (parentCur->right == cur)
		{
			parentCur->right = cur->right;
			delete cur;
			return true;
		}
	}
	if (cur->right == NULL)
	{
		if (parentCur->left == cur)
		{
			parentCur->left = cur->left;
			delete cur;
			return true;
		}
		if (parentCur->right == cur)
		{
			parentCur->right = cur->left;
			delete cur;
			return true;
		}
	}

	//node has 2 children
	node* suc = Succes(cur);
	node* temp = cur;
	node* parentSuc = *root;
	bool isRight = true;
	while (parentSuc!=NULL)
	{
		if (parentSuc->left->data == suc->data)
		{
			isRight == false;
			break;
		}
		if (parentSuc->right->data == suc->data)
		{
			isRight == true;
			break;
		}
		if (parentSuc->data < suc->data)
			parentSuc = parentSuc->right;
		else
			parentSuc = parentSuc->left;
	}
	//
	if (parentSuc->data == cur->data)
	{
		if (!isRight)
		{
			parentSuc->left = suc->right;
		}
		else
		{
			parentSuc->right = suc->right;
		}
	}
	else
	{
		if (!isRight)
		{
			parentSuc->right = suc->right;
		}
		else
		{
			parentSuc->left = suc->right;
		}
	}
	
	cur->data = suc->data;
	delete suc;
	return true;
}

void BST::clear(node* &Node)
{
	if (Node != NULL)
	{
		clear(Node->left);
		clear(Node->right);
		delete Node;
	}
}

BST::~BST()
{
	node* Node = *root;
	clear(Node);
	delete root;
}

void BST::LNR()
{
	node* cur = *root;
	if (isEmpty())
	{
		cout << "Tree is Empty!!\n";
	}
	else
	{
		PrintLNR(cur);
		cout << "\n";
	}
}

void BST::PrintLNR(const node* Node)
{
	if (Node != NULL)
	{
		PrintLNR(Node->left);
		cout << Node->data<<" ";
		PrintLNR(Node->right);
	}
}

bool BST::Search(int Data)
{
	if (isEmpty())
	{
		return false;
	}
	node* cur = *root;
	while (cur != NULL)
	{
		if (cur->data == Data)
		{
			return true;
		}
		if (cur->data < Data)
		{
			cur = cur->right;
		}
		if (cur->data > Data)
		{
			cur = cur->left;
		}
	}
	return false;
}


//------------------------------------------

int main()
{
	ifstream fin;
	fin.open("data.txt");
	BST Tree;
	while (!fin.eof())
	{
		int data;
		if(fin >> data)
		Tree.insert(data);
	}
	//
	fin.close();
	Tree.Delete(8);
	Tree.LNR();
	system("pause");
}
