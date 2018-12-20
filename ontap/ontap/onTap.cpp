#include <iostream>
#include <string>
using namespace std;

//define
struct student
{
	char ID[11];
	string name;
	double mark;
};

struct node
{
	student data;
	node* next;
};

node* head=NULL;
//

//push back
void push(student Data)
{
	if (head==NULL)
	{
		head=new node;
		head->data=Data;
		head->next=NULL;
		return;
	} 
	node* cur= head;
	while (cur->next!=NULL)
	{
		cur=cur->next;
	}
	node* newNode = new node;
	newNode->data=Data;
	newNode->next=NULL;
	cur->next = newNode;
}

student inputData()
{
	student NewData;
	cout<<"Nhap ma so sinh vien: ";
	cin>>NewData.ID;
	NewData.ID[10] = '\0';
	cout<<"Nhap ho ten sinh vien: ";
	cin.ignore();
	getline(cin,NewData.name);
	cout<<"Nhap diem sinh vien: ";
	cin>>NewData.mark;
	return NewData;
}

void PrintNode(node* Data)
{
	cout<<"\nID:      "<<Data->data.ID
		<<"\nten:     "<<Data->data.name
		<<"\nDiem TB: "<<Data->data.mark;
}

void printList()
{
	node* cur=head;
	while (cur!=NULL)
	{
		PrintNode(cur);
		cout<<"\n-------------------------\n";
		cur=cur->next;
	}
}

void printInfomationStudentGreaterMark5()
{
	node* cur = head;
	while (cur != NULL && cur->data.mark>5.0)
	{
		PrintNode(cur);
		cout << "\n-------------------------\n";
		cur = cur->next;
	}
}

//sort mark
void SortListLessToGreater()
{
	//bubble sort
	// swap data
	for (node* curI = head; curI->next != NULL; curI = curI->next)
	{
		for (node* curJ = curI->next; curJ != NULL; curJ = curJ->next)
		{
			if (curI->data.mark > curJ->data.mark)
			{
				swap(curI->data, curJ->data);
			}
		}
	}
}

// X is ID
void PushBackX(char ID[],student NewData)
{
	node* cur = head;
	while (cur->next != NULL || cur->data.ID==ID)
	{
		cur = cur->next;
	}
	if (cur->next == NULL)
	{
		push(NewData);
		return;
	}
	node* cur = head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	node* newNode = new node;
	newNode->data = NewData;
	newNode->next = cur->next;
	cur->next = newNode;
	
}
//menu
int MENU()
{
	cout<<"-----MENU---------\n"
		<<"1. nhap danh sach sinh vien\n"
		<<"2. Xuat danh sach sinh vien\n"
		<<"9. xoa toan bo danh sach\n"
		<<"10. thoat\n"
		<<"\t\chon: ";
	int choose;
	cin>>choose;
	return choose;

}

void APP()
{
	int choose=-1;
	while (choose!=10)
	{
		system("cls");
		choose=MENU();
		system("cls");
		switch (choose)
		{
		case 10:
			break;
		case 1:
			{
				student newData=inputData();
				push(newData);
				break;
			}
		case 2:
			{
				cout<<"\n";
				printList();
				system("pause");
				break;
			}
		case 3:
		{
			printInfomationStudentGreaterMark5();
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			SortListLessToGreater();
			cout << "sap xep thanh cong!\n";
			break;
		}
		case 6:
		{
			cout << "Nhap ma so sinh vien them sau :";
			char IDX[11];
			cin >> IDX;
			IDX[11] = '\0';
			cout << "\n";
			student Student = inputData();
			PushBackX(IDX, Student);
			cout << "them thanh cong!\n";
			break;
		}
		default:
			break;
		}
	}
	
}

int main()
{
	APP();
}
