#include <iostream>
#include <string>
using namespace std;

//define
struct student
{
	unsigned long ID;
	string name;
	double point;
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
	while (cur!=NULL)
	{
		cur=cur->next;
	}
	cur=new node;
	cur->data=Data;
	cur->next=NULL;	
}

student inputData()
{
	student NewData;
	cout<<"Nhap ma so sinh vien: ";
	cin>>NewData.ID;
	cout<<"Nhap ho ten sinh vien: ";
	cin.ignore();
	getline(cin,NewData.name);
	cout<<"Nhap diem sinh vien: ";
	cin>>NewData.point;
	return NewData;
}

void PrintNode(node* Data)
{
	cout<<"\nID:      "<<Data->data.ID
		<<"\nten:     "<<Data->data.name
		<<"\nDiem TB: "<<Data->data.point;
}

void printList()
{
	node* cur=head;
	if (cur!=NULL)
	{
		PrintNode(cur);
		cout<<"\n-------------------------\n";
		cur=cur->next;
	}
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
		default:
			break;
		}
	}
	
}

int main()
{
	APP();
}
