#include <iostream>

using namespace std;

// singly linked list
struct node
{
	int data;
	node* next;
};
//


void __init__(node** &head_ref)
{
	head_ref = new node*;
	*head_ref = NULL;
}

// if SLL is empty return True
bool isEmpty(node** head)
{
	if (*head == NULL)
	{
		return true; 
	}
	return false;
}

void printSLL(node** head)
{
	if (isEmpty(head))
	{
		cout << "This list is EMPTY!!\n";
		return;
	}
	node* cur = *head;
	while (cur->next!=NULL)
	{
		cout << cur->data << "->";
		cur = cur->next;
	}

	cout << cur->data<<endl;
}

node* find(node** head, int DATA)
{

	if (isEmpty(head))
	{
		return NULL;
	}
	node* cur = *head;
	while (cur!=NULL)
	{
		if (cur->data == DATA)
		{
			break;
		}
		cur = cur->next;
	}

	return cur;
	
}

void push_front(node** &head_ref, int newData)
{
	if (isEmpty(head_ref))
	{
		node* newNode = new node;
		newNode->data = newData;
		newNode->next = NULL;
		*head_ref = newNode;
		cout << "Pushed " << newData << endl;
		return;
	}

	node* cur = *head_ref;

	node* newNode = new node;
	newNode->data = newData;
	newNode->next = cur;
	*head_ref = newNode;
	cout << "Pushed " << newData << endl;
}

void push_back(node** &head_ref, int newData)
{
	if (isEmpty(head_ref))
	{
		push_front(head_ref, newData);
		return;
	}
	node* cur = *head_ref;

	node* newNode = new node;
	newNode->data = newData;
	newNode->next = NULL;
	
	while (cur->next!=NULL)
	{
		cur = cur->next;
	}
	cur->next = newNode;
	cout << "Pushed " << newData << endl;
}

void pop_front(node** &head_ref)
{
	if (isEmpty(head_ref))
	{
		printSLL(head_ref);
		return;
	}
	node* cur = *head_ref;
	node* tmp = cur->next;
	*head_ref = tmp;
	int DATA = cur->data;
	delete cur;
	cout << "Popped " << DATA << endl;

}

void pop_back(node** &head_ref)
{
	if (isEmpty(head_ref))
	{
		printSLL(head_ref);
		return;
	}
	//
	node* cur = *head_ref;
	if (cur->next == NULL)
	{
		int DATA = cur->data;
		
		delete cur;
		*head_ref = NULL;
		cout << "Popped " << DATA << endl;
		return;
	}
	//
	while (cur->next != NULL)
	{
		if (cur->next->next == NULL)
			break;

		cur = cur->next;
	}
	int DATA = cur->next->data;
	
	node* deleteNode = cur->next;
	cur->next = NULL;
	delete deleteNode;
	cout << "Popped " << DATA << endl;

}

void popNode(node** &head_ref,int DATA)
{
	node* cur = find(head_ref, DATA);
	if (cur == NULL)
	{
		cout << "Don't have " << DATA << " in List\n";
		return;
	}
	if (cur == *head_ref)
	{
		pop_front(head_ref);
		return;
	}
	node* parent = *head_ref;
	node* child = cur->next;
	while (parent->next != cur)
	{
		parent = parent->next;
	}
	parent->next = child;
	int DAT = cur->data;
	delete cur;
	cout << "Popped " << DAT << endl;
} 

void SortList(node** &head_ref)
{
	//bubble sort
	if (isEmpty(head_ref))
	{
		printSLL(head_ref);
		return;
	}
	node* cur = *head_ref;
	
	while (cur!=NULL)
	{
		node* nextCur = cur->next;
		while (nextCur != NULL)
		{
			if (cur->data > nextCur->data)
			{
				int tmp = cur->data;
				cur->data = nextCur->data;
				nextCur->data = tmp;
			}
			nextCur = nextCur->next;
		}
		cur = cur->next;
	}
	cout << "Sorted List\n";
}

void __destruction_(node** &head_ref)
{
	while (!isEmpty(head_ref))
	{
		pop_front(head_ref);
	}
	delete head_ref;
}

//main
int main()
{
	node** head;
	__init__(head);
	cout << "Created a List \n";

	int choose=-1;
	while (true)
	{
		cout<< "\t1.  Print List\n"
			<< "\t2.  Find Data\n"
			<< "\t3.  push front\n"
			<< "\t4.  push back\n"
			<< "\t5.  pop front\n"
			<< "\t6.  pop back\n"
			<< "\t7.  pop Data\n"
			<< "\t8.  sort list\n"
			<< "\t9.  Delete list and EXIT\n"
			<< "\t\t Choose option:\t ";
		cin >> choose;
		cout << "\n";
		switch (choose)
		{
		case 1:
		{
			printSLL(head);
			break;
		}
		case 2:
		{
			cout << "input a data:";
			int x;
			cin >> x;
			node* findX = find(head, x);
			if (findX == NULL)
			{
				cout << "\t Don't have data in list\n";
			}
			else
			{
				cout << "\t Data exist in list\n";
			}
			break;
		}
		case 3:
		{
			cout << "input a data:";
			int x;
			cin >> x;
			push_front(head, x);
			break;
		}
		case 4:
		{
			cout << "input a data:";
			int x;
			cin >> x;
			push_back(head, x);
			break;
		}
		case 5:
		{
			pop_front(head);
			break;
		}
		case 6:
		{
			pop_back(head);
			break;
		}
		case 7:
		{
			cout << "input a data:";
			int x;
			cin >> x;
			popNode(head, x);
			break;
		}
		case 8:
		{
			SortList(head);
			break;
		}
		case 9:
		{
			__destruction_(head);
			exit(0);
		}
		default:
			cout << "\nERROR!!\n";
			break;
		}
		system("pause");
		system("cls");

	}
	
}
