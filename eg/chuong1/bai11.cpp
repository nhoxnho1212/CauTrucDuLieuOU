#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

class SLL
{
private:
	node* head;
public:
	SLL()
	{
		head = NULL;
	}

	bool isEmpty()
	{
		if (head == NULL)
		{
			return true;
		}
		return false;
	}

	void push_back(int DATA)
	{
		if (isEmpty())
		{
			head = new node;
			head->data = DATA;
			head->next = NULL;
			return;
		}

		//
		node* NewNode = new node;
		NewNode->data = DATA;
		NewNode->next = NULL;
		node* cur = head;
		while (cur->next!=NULL)
		{
			cur = cur->next;
		}
		cur->next = NewNode;

	}

	void pop_front()
	{
		if (!isEmpty())
		{
			node* cur = head;
			head = head->next;
			delete cur;
		}
		
	}

	int top()
	{
		if (isEmpty())
		{
			return NULL;
		}
		return head->data;
	}

	~SLL()
	{
		while (!isEmpty())
		{
			pop_front();
		}
	}
};

class Queue
{
private:
	SLL List;
public:
	bool isEmpty()
	{
		return List.isEmpty();
	}
	int top()
	{
		return List.top();
	}
	void pop()
	{
		List.pop_front();
	}
	void push(int DATA)
	{
		List.push_back(DATA);
	}

};

int MENU()
{
	cout << "--------------------MENU-----------------\n"
		<< "\t1. Front data\n"
		<< "\t2. Push data\n"
		<< "\t3. Pop data\n"
		<< "\t4. Is Empty \n"
		<< "\t0. Delete Queue and EXIT.\n"
		<< "\n\t\tChoose 1 option: ";
	int choose;
	cin >> choose;
	return choose;

}

void APPLICATION()
{
	Queue QUEUE;
	cout << "Create Queue Succeed!\n";
	bool check=true;

	while (check)
	{
		int choose = MENU();

		switch (choose)
		{
		case 0:
		{
			check = false;
			cout << "\n\nDELETED!!\n";
			break;
		}
		case 1:
		{
			if (QUEUE.isEmpty())
			{
				cout << "\n\nQueue is Empty!\n";
			}
			else
			{
				cout << "\n\n\t" << QUEUE.top() << endl;
			}
			break;
			
		}
		case 2:
		{
			cout << "\n\n\tInput Data: ";
			int DATA;
			cin >> DATA;
			QUEUE.push(DATA);
			cout << "Push succeed!\n";
			break;
		}
		case 3:
		{
			if (QUEUE.isEmpty())
			{
				cout << "\n\nQueue is Empty!\n";
			}
			else
			{
				QUEUE.pop();
				cout << "\n\nPop succeed!\n";
			}
			break;
		}
		case 4:
		{
			if (QUEUE.isEmpty())
				cout << "\n\nQueue is Empty!\n";
			else
			{
				cout << "\n\nQueue isn\'t Empty!\n";
			}
			break;
		}

		default:
			cout << "\n\nchoose ERROR!!\n";
			break;
		}

		system("pause");
		system("cls");
	}


}

int main()
{
	APPLICATION();
	return 0;
}