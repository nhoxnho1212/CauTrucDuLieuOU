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
	while (cur != NULL)
	{
		if (cur->data.mark > 5.0)
		{
			PrintNode(cur);
			cout << "\n-------------------------\n";
		}

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
bool PushBackX(char ID[], student NewData)
{
	node* cur = head;

	while (cur->next != NULL)
	{
		if (strcmp(ID, cur->data.ID) == 0)
		{
			break;
		}
		cur = cur->next;
	}
	if (strcmp(ID, cur->data.ID))
		return false;
	node* newNode = new node;
	newNode->data = NewData;
	newNode->next = cur->next;
	cur->next = newNode;
	return true;
}

//find X ID
student findXid(char ID[])
{
	node* cur = head;
	student NULLStudent;
	NULLStudent.ID[0] = '\0';
	while (cur != NULL )
	{
		if (strcmp(ID,cur->data.ID)==0)
		{
			return cur->data;
			break;
		}
		cur = cur->next;
	}
	return NULLStudent;
	
	
}

bool pop_front()
{
	if (head == NULL)
		return false;
	node* cur = head;
	head = head->next;
	delete cur;
	return true;
}

bool pop_back()
{
	if (head == NULL)
		return false;
	node* cur = head;
	node* preCur = cur;
	while (cur->next!=NULL)
	{
		preCur = cur;
		cur = cur->next;
	}
	if (head->next == NULL)
	{
		delete cur;
		head = NULL;
		return true;
	}
	delete cur;
	preCur->next = NULL;
	return true;

	
}

void destruc()
{
	while (head!=NULL)
	{
		pop_front();
	}
}
//menu
int MENU()
{
	cout<<"-----MENU---------\n"
		<<"1. nhap danh sach sinh vien\n"
		<<"2. Xuat danh sach sinh vien\n"
		<<"3. Xuat danh sach sinh vien co diem trung binh > 5\n"
		<<"4. tim kiem sinh vien co ma X\n"
		<<"5. sap xep danh sach sinh vien theo diem trung binh\n"
		<<"6. them 1 sinh vien sau sinh vien co ma X\n"
		<<"7. xoa sinh vien dau danh sach\n"
		<<"8. xoa sinh vien cuoi danh sach\n"
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
		{
			destruc();
			break;
		}
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
			system("pause");
			break;
		}
		case 4:
		{
			cout << "Nhap ma so sinh vien them sau :";
			char IDX[11];
			cin >> IDX;
			student find = findXid(IDX);
			if (find.ID[0] == '\0')
			{
				cout << "khong tim thay!\n";
			}
			else
			{
				cout << "tim thay sinh vien\n";
				node* pointer = new node;
				pointer->data = find;
				pointer->next = NULL;
				PrintNode(pointer);
				delete pointer;
				
			}
			system("pause");
			break;
		}
		case 5:
		{
			SortListLessToGreater();
			cout << "sap xep thanh cong!\n";
			system("pause");
			break;
		}
		case 6:
		{
			cout << "Nhap ma so sinh vien them sau :";
			char IDX[11];
			cin >> IDX;
			student find = findXid(IDX);
			if (find.ID[0] == '\0')
			{
				cout << "khong tim thay!\n";
				system("pause");
				break;
			}
			cout << "\n";
			student Student = inputData();
			bool pushX=PushBackX(IDX, Student);
			if (pushX)
				cout << "them thanh cong!\n";
			else
			{
				cout << "them that bai!\n";
			}
			
			break;
		}
		case 7:
		{
			bool check = pop_front();
			if (check)
			{
				cout << "xoa thanh cong!";
			}
			else
			{
				cout << "xoa that bai!";
			}
			cout << "\n";
			system("pause");
			break;
		}
		case 8:
		{
			bool check = pop_back();
			if (check)
			{
				cout << "xoa thanh cong!";
			}
			else
			{
				cout << "xoa that bai!";
			}
			cout << "\n";
			system("pause");
			break;
		}
		case 9:
		{
			destruc();
			cout << "da xoa toan bo danh sach!\n";
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
