#include <iostream>
using namespace std;

const int MAXSIZEOFSTACK = 33;// integer

// static
int* Stack = new int[MAXSIZEOFSTACK];
int firstPosition;
//stack
void _init_();
bool isEmpty();
bool isFull();
bool push(int Data);
bool pop(int Data);
void _destruction_();

void _init_()
{
	firstPosition = -1;
}

bool isEmpty()
{
	if (firstPosition == -1)
		return true;
	return false;
}

bool isFull()
{
	if (firstPosition == MAXSIZEOFSTACK - 1)
		return true;
	return false;
}

bool push(int Data)
{
	if (isFull())
	{
		return false;
	}
	Stack[++firstPosition] = Data;
	return true;
}

bool pop()
{
	if (isEmpty())
	{
		return false;
	}
	Stack[firstPosition--] = NULL;
	return true;

}

void _destruction_()
{
	delete Stack;
}

void DecToE(int Dec,int number)
{
	if (Dec == 0 || isFull())
	{
		return;
	}
	push(Dec % number);
	return DecToE(Dec /number,number);
}

int main()
{
	cout << "nhap vao so he thap phan: ";
	int Dec;
	cin >> Dec;
	int number;

	_init_();
	cout << "nhap he can doi: ";
	cin >> number;
	DecToE(Dec,number);
	cout << "so duoc doi: ";
	if (Dec == 0) cout << "0\n";
	else
	{
		cout << Stack[firstPosition];
		while (pop())
		{
			if (!isEmpty())
				cout << Stack[firstPosition];
		}
	}
	cout << endl;
	system("pause");
	_destruction_();
}