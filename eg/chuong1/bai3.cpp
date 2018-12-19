#include <iostream>
using namespace std;
//define
const int MAXSIZEOFSTACK = 100;

// static
int* Stack=new int[MAXSIZEOFSTACK];
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

// application
int Menu()
{
	int choose;
	cout << "-------------------Menu---------------------\n"
		<< "\t1. kiem tra stack rong\n"
		<< "\t2. kiem tra stack day\n"
		<< "\t3. them 1 phan tu vao stack\n"
		<< "\t4. xoa 1 phan tu trong stack\n"
		<< "\t5. xuat phan tu tren cung trong stack\n"
		<< "\t0. Xoa va thoat\n"
		<< "\t\tchon: >";
	cin >> choose;
	return choose;

}

void application()
{
	int choose = Menu();
	
	switch (choose)
	{
	case 0:
	{
		_destruction_();
		return;
		break;
	}
	case 1:
	{
		if (isEmpty())
		{
			cout << "stack rong!\n";
			
		}
		else
		{
			cout << "Stack ko rong!\n";
		}
		break;
	}
	case 2:
	{
		if (isFull())
		{
			cout << "stack day!\n";

		}
		else
		{
			cout << "Stack ko day!\n";
		}
		break;
	}
	case 3:
	{
		int data;
		cout << "\t\tnhap du lieu can them :";
		cin >> data;
		bool check=push(data);
		if (check)
			cout << "them thanh cong!\n";
		else
		{
			cout << "them that bai!\n";
		}
		break;
	}
	case 4:
	{
		bool check = pop();
		if (check)
			cout << "xoa thanh cong!\n";
		else
		{
			cout << "xoa that bai!\n";
		}
		break;
	}
	case 5:
	{
		if (isEmpty())
		{
			cout << "stack rong\n";
		}
		else
		cout << "phan tu tren cung trong stack: " << Stack[firstPosition]<<endl;
		break;
	}
	default:
	{
		cout << "chon sai chon lai!!\n";
		break;
	}
		
	}
	system("pause");
	system("cls");
	return application();
}

int main()
{
	_init_();
	cout << "khoi tao stack thanh cong\n";
	application();

}

