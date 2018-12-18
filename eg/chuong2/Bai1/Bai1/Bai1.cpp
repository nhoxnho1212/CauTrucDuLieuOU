#include <iostream>

using namespace std;

//Define
int* List;
int LengthList;

//
bool _init_()
{
	List = new int[100];
	LengthList = 0;
	return true;
}

bool SetList()
{
	cout << "\tNhap so luong phan tu cua day: ";
	cin >> LengthList;
	for (int i = 0; i < LengthList; i++)
	{
		cout << "\t\tnhap phan tu thu " << i + 1 << " : > ";
		cin >> List[i];
	}
	return true;
}

bool PrintList()
{
	for (int i = 0; i < LengthList; i++)
	{
		cout << List[i] << " ";
	}
	cout << endl;
	return true;
}

void SelectionSort()
{
	for (int cur = 0; cur < LengthList - 1; cur++)
	{
		int MinPos = cur;
		for (int i = cur+1; i < LengthList; i++)
		{
			if (List[MinPos] < List[i])
			{
				MinPos = i;
			}
		}
		swap(List[cur], List[MinPos]);
	}
	cout << "\nList sorted!!\n";
}

void InsertionSort()
{
	for (int cur = 1; cur < LengthList; cur++)
	{
		for (int i = cur - 1; i >= 0 && List[cur] < List[i]; i--)
		{
			swap(List[cur], List[i]);
		}
	}
	cout << "\nList Sorted!!\n";
}

void InterchangeSort()
{
	for (int cur = 0; cur < LengthList - 1; cur++)
	{
		for (int i = cur + 1; i < LengthList; i++)
		{
			if (List[i] < List[cur])
			{
				swap(List[i], List[cur]);
			}
		}
	}
	cout << "\nList Sorted!!\n";
}

void _destruction_()
{
	delete List;
}

int MENU()
{
	int choose=0;
	cout << "-------------------------------------------------\n"
		<< "\t1. Nhap danh sach\n"
		<< "\t2. Xuat danh sach\n"
		<< "\t3. Selection Sort\n"
		<< "\t4. Insertion Sort\n"
		<< "\t5. Interchange Sort\n"
		<< "\t0. thoat\n"
		<< "\t\tChon: >";
	cin >> choose;

	if (choose < 0 && choose>6)
	{
		system("cls");
		cout << "chon cl j vay nhoc, chon lai cho a coi\n";
		return MENU();
	}
	return choose;
	
}

int APP()
{
	_init_();
	int choose = MENU();
	bool check = true;

	
}

