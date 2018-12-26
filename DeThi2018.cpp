#include <iostream>
using namespace std;

//define
struct node
{
	int data;
	node* next;
};

//
node* head;

void _init_()
{
	head = NULL;
}

void push_front(int data)
{
	node* newnode = new node;
	newnode->data = data;
	newnode->next = head;
	head = newnode;
}

void printList()
{
	node* cur = head;
	while (cur != NULL)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << "\n";
}

int findX(int X)
{
	node* cur = head;
	while (cur!=NULL)
	{
		if (cur->data == X)
		{
			return int(&cur);
		}
		cur = cur->next;
	}
	return NULL;
}

bool pop_back()
{
	if (head == NULL)
	{
		return false;
	}
	node* cur = head;
	node* precur = cur;
	while (cur->next!=NULL)
	{
		precur = cur;
		cur = cur->next;
	}
	precur->next = NULL;
	delete cur;
	return true;
}

void deleteLessToX(int X)
{
	node* cur = head;
	node* preCur = cur;
	while (cur!=NULL)
	{
		if (cur->data < X) 
		{
			preCur->next = cur->next;
			node* deleteCode = cur;
			cur = cur->next;
			if (deleteCode == head)
			{
				head = cur;
			}
			delete deleteCode;
		}
		else
		{
			preCur = cur;
			cur = cur->next;
		}
	}
}

void main()
{
	_init_();
	push_front(10);
	push_front(4);
	push_front(20);
	push_front(1);
	push_front(3);
	push_front(8);
	push_front(7);
	push_front(0);
	printList();
	int x=findX(3);
	cout << "\n" << x << "\n";
	pop_back();
	pop_back();
	printList();
	deleteLessToX(5);
	printList();
	system("pause");
}