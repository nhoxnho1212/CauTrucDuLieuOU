//student management system
//using singly linked list

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
using namespace std;

//structure student
struct  Student
{
	char Id[10];
	char Name[40];
	float Mark;
};

//singly linked list
struct node
{
	Student data;
	node* next;
};

//define-------------------------------------------------------------------------------------------------
void _init_(node** &head_ref);
bool IsAlpha(string Data);
bool IsNumber(string Data);
Student getStudent();
bool isEmpty(node** head);
void push_front(node** &head_ref, Student DATA);
void push_back(node** &head_ref, Student newData);
void pop_front(node** &head_ref);
void pop_back(node** &head_ref);
void PrintAStudent(Student DATA);
void printStudentList(node** head);
void  PopStudentHas_x_ID(node** &head_ref, char xID[]);
void _destruction_(node** &head_ref);

//-------------------------------------------------------------------------------------------------------

// create student list
void _init_(node** &head_ref)
{
	head_ref = new node*;
	*head_ref = NULL;
}

bool IsAlpha(string Data)
{
	int leng = Data.length();
	for (int i = 0; i < leng; i++)
	{
		if ((int(Data[i]) >= 65 && int(Data[i]) <= 90) || (int(Data[i]) >= 97 && int(Data[i]) <= 122) ||Data[i]==' ')
			continue;
		else return false;
	}
	return true;
}

bool IsNumber(string Data)
{
	int leng = Data.length();
	for (int i = 0; i < leng; i++)
	{
		if ((int(Data[i]) >= 48 && int(Data[i]) <= 57 ) ||Data[i]=='.')
			continue;
		else return false;
	}
	return true;
}

float toFloat(string Data)
{
	int leng = Data.length();
	float Dec = 0;
	
	int i = 0;
	for (i = 0; i < leng; i++)
	{
		if (Data[i] == '.')
		{
			break;
		}
		Dec = Dec * 10 + int(Data[i]) - 48;
	}
	for (int j = i + 1; j < leng; j++)
	{
		Dec += ((int(Data[j]) - 48) / 10.0);
	}
	return Dec;
}

// function input information of student
Student getStudent()
{
	Student newStudent;
	string IDinput;
	string NameInput;
	
	std::system("cls");
	cout << "Enter information of student.\n";
	cout << "\n\n";

	//input id 
_InputID_:
	cout << "\tInput ID: ";
	cin >> IDinput;
	
	if (IDinput.length() != 10 || !IsNumber(IDinput))
	{
		std::system("cls");
		cout << "Enter information of student.\n";
		cout << "\n\t\tID must have 10 number!!\n";
		goto _InputID_;
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			newStudent.Id[i] = IDinput[i];
		}
	}

	//input Name of student;
_InputName_:
	
	cout << "\tInput Name: " ;
	getline(cin,NameInput);
	if (NameInput.length() <= 0 || NameInput.length() > 40 || !IsAlpha(NameInput))
	{
		std::system("cls");
		cout << "Enter information of student.\n";
		cout << "\n\t\tName must have  1-40 letters!!\n";
		cout << "\tInput ID: " << setw(15)<<IDinput<<endl;
		goto _InputName_;
	}
	else
	{
		int leng = NameInput.length();
		for (int i = 0; i < leng; i++)
		{
			newStudent.Name[i] = NameInput[i];
		}
		for (int i = leng; i < 40; i++)
		{
			newStudent.Name[i] =NULL;
		}
	}

	//input Mark
	cout << "\tInput Mark: " ;
_InputMark_:
	string MarkInput;
	getline(cin, MarkInput);
	
	if (IsNumber(MarkInput))
	{
		if ((toFloat(MarkInput) < 0.0 || toFloat(MarkInput) > 10.0))
		{
			std::system("cls");
				cout << "Enter information of student.\n";
				cout << "\n\t\tMark must be a number [0-10]!!\n";
				cout << "\tInput ID: " << IDinput << endl;
				cout << "\tInput Name: "  << NameInput << endl;
				cout << "\tInput Mark: " ;


				goto _InputMark_;
		}
		else
		{
			newStudent.Mark = toFloat(MarkInput);
		}
	}
	else
	{
		std::system("cls");
		cout << "Enter information of student.\n";
		cout << "\n\t\tMark must be a number [0-10]!!\n";
		cout << "\tInput ID: " << IDinput << endl;
		cout << "\tInput Name: "<< NameInput << endl;
		cout << "\tInput Mark: ";


		goto _InputMark_;
	}

	//return
	return newStudent;
}

bool isEmpty(node** head)
{
	if (*head == NULL)
	{
		return true;
	}
	return false;
}

void push_front(node** &head_ref, Student DATA)
{
	node* newnode = new node;
	newnode->data = DATA;
	if (isEmpty(head_ref))
	{
		newnode->next = NULL;
		*head_ref = newnode;
		return;
	}
	newnode->next = *head_ref;
	*head_ref = newnode;
}

void push_back(node** &head_ref, Student newData)
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

	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = newNode;

}

void pop_front(node** &head_ref)
{
	if (isEmpty(head_ref))
	{
		printStudentList(head_ref);
		return;
	}
	node* cur = *head_ref;
	node* tmp = cur->next;
	*head_ref = tmp;
	Student DATA = cur->data;
	delete cur;
	cout << "Deleted " << DATA.Id << endl;


}

void pop_back(node** &head_ref)
{
	if (isEmpty(head_ref))
	{
		printStudentList(head_ref);
		return;
	}
	//
	node* cur = *head_ref;
	if (cur->next == NULL)
	{
		Student DATA = cur->data;

		delete cur;
		*head_ref = NULL;
		cout << "Deleted " << DATA.Id << endl;
		return;
	}
	//
	while (cur->next != NULL)
	{
		if (cur->next->next == NULL)
			break;

		cur = cur->next;
	}
	Student DATA = cur->next->data;

	node* deleteNode = cur->next;
	cur->next = NULL;
	delete deleteNode;
	cout << "Deleted " << DATA.Id << endl;

}

void PrintAStudent(Student DATA)
{
	for (int i = 0; i < 10; i++)
	{
		cout << DATA.Id[i];
	}
	cout	<<"\t|\t" << DATA.Name 
		<< "\t|\t" << DATA.Mark;
}

// function print list information of students
void printStudentList(node** head)
{
	if (isEmpty(head))
	{
		cout << "Don\'t any student in system!!!\n";
		return;
	}
	cout << "-----------Information of all student--------------\n";
	node* cur = *head;
	while (cur!=NULL)
	{
		PrintAStudent(cur->data);
		cur = cur->next;
		cout << endl;
	}

}

bool compareString(char str1[], char str2[])
{
	for (int i = 0; i < 10; i++)
	{
		if (str1[i] != str2[i])
			return false;
	}
	return true;
}

// deleted student has x id
void  PopStudentHas_x_ID(node** &head_ref,char xID[])
{
	if (isEmpty(head_ref))
	{
		printStudentList(head_ref);
		return;
	}
	//find x
	node* cur = *head_ref;
	node* preCur = *head_ref;
	while (cur!=NULL)
	{
		if (compareString(cur->data.Id,xID))
		{
			break;
		}
		preCur = cur;
		cur = cur->next;
	}
	
	//can't find x ID
	if (cur == NULL)
	{
		cout << xID<<"not exist!!\n";
		return;
	}
	//x is first node
	if (cur == preCur)
	{
		pop_front(head_ref);
		return;
	}

	//delete xID
	preCur->next = cur->next;
	delete cur;
	cout << "Deleted" << xID << endl;

}

// destruction
void _destruction_(node** &head_ref)
{
	while (!isEmpty(head_ref))
	{
		pop_front(head_ref);
	}
	delete head_ref;
}

int Menu()
{
	cout << "----------------MENU----------------\n"
		<< "\t1. Enter Information of student\n"
		<< "\t2. Print student list\n"
		<< "\t3. Delete first student in list\n"
		<< "\t4. Delete last student in list\n"
		<< "\t5. Delete student has x ID\n"
		<< "\t0. EXIT\n"
		<< "\t\tChoose option: >";
	int choose;
	cin >> choose;
	return choose;
}

void application()
{
	node** head;
	_init_(head);

	bool check = true;
	while (check) 
	{
		std::system("cls");
		int choose = Menu();
		std::system("cls");
		switch (choose)
		{
		case 0:
		{
			_destruction_(head);
			check = false;
			break;
		}
		case 1:
		{
			Student newStudent = getStudent();
			push_back(head, newStudent);
			cout << "\nAdd SUCCEDD!!\n";
			break;
		}
		case 2:
		{
			printStudentList(head);
			break;
		}
		case 3:
		{
			pop_front(head);
			break;
		}
		case 4:
		{
			pop_back(head);
			break;
		}
		case 5:
		{
			string IDinput;
			char xID[10];
		_InputID_:
			cout << "\tInput ID: " << setw(15);
			cin >> IDinput;

			if (IDinput.length() != 10 || !IsNumber(IDinput))
			{
				std::system("cls");
				cout << "\n\t\tID must have 10 number!!\n";
				goto _InputID_;
			}
			else
			{
				for (int i = 0; i < 10; i++)
				{
					xID[i] = IDinput[i];
				}
			}
			
			PopStudentHas_x_ID(head, xID);
			break;
		}
		default:
			
			cout << "\n\t\tEnter [0-5]!!Please select again!!\n";
			break;
		}
		std::system("pause");
	}
}

int main()
{
	application();
	return 0;
}
