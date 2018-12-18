#include <iostream>
#include <conio.h>
using namespace std;

const int HashKey = 101;

struct node
{
	int data;
	node* next;
};

node* hashTable[HashKey];

void init()
{

}

bool insert(int data)
{
	int CurHashValue = data % HashKey;
	node* cur = hashTable[CurHashValue];
	if (cur == NULL)
	{
		hashTable[CurHashValue] = new node;
		hashTable[CurHashValue]->data = data;
		hashTable[CurHashValue]->next = NULL;
		return true;
	}
	node* preCur = cur;
	while (cur != NULL && cur->data <= data)
	{
		if (cur->data == data)
		{
			return false;
		}
		preCur = cur;
		cur = cur->next;
	}
	node* newNode = new node;
	newNode->data = data;
	if (preCur != NULL)
	{
		preCur->next = newNode;
	}

	newNode->next = cur;
	return true;
}

bool search(int data)
{
	int CurHashValue = data % HashKey;
	node* cur = hashTable[CurHashValue];
	while (cur != NULL)
	{
		if (cur->data == data) return true;
		cur = cur->next;
	}
	return false;
}

void printHash()
{
	cout << "\nHash Table: \n";
	for (int i = 0; i < HashKey; i++)
	{
		cout << i << " : ";
		node* cur = hashTable[i];
		while (cur != NULL)
		{
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << "\n";
		delete cur;
	}
}

void Destruct()
{
	for (int i = 0; i < HashKey; i++)
	{
		delete hashTable[i];
	}

}

int MENU()
{
	cout << "-----------------MENU--------------------\n"
		<< "\t1. insert.\n"
		<< "\t2. search.\n"
		<< "\t3. Print hash Table.\n"
		<< "\t0. exit.\n"
		<< "\t\tChoose: ";
	int choose;
	cin >> choose;
	return choose;
}

void APP()
{
	int choose = MENU();
	switch (choose)
	{
	case 0:
	{
		Destruct();
		exit(0);
		break;
	}
	case 1:
	{
		int data;
		cout << "data: >";
		cin >> data;
		if (insert(data))
		{
			cout << "insert SUCCESSES!!\n";
		}
		else
		{
			cout << "insert FAIL!!\n";
		}
		break;
	}
	case 2:
	{
		int data;
		cout << "data: >";
		cin >> data;
		if (search(data))
		{
			cout << "Data existed!!\n";
		}
		else
		{
			cout << "Can't Find!!\n";
		}
		break;
	}
	case 3:
	{
		cout << "\n";
		printHash();
		cout << "\n";
		break;
	}
	default:
	{
		system("cls");
		APP();
	}

	}
	system("pause");
	system("cls");
	APP();
}

int main()
{
	APP();
}