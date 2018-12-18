#include<iostream>
using namespace std;

struct student
{
	char id[10];
	char name[40];
	double mark;
};
student getstudent()
{
	student s;
	cout << "Nhap vao ma sinh vien: ";
	cin >> s.id;
	cin.ignore();
	cout << "Nhap vao ten sinh vien: ";
	cin.get(s.name, 40);
	cout << "Nhap vao diem trung binh sinh vien: ";
	cin >> s.mark;
	return s;
}
void printstudent(student s)
{
	cout << s.id << "\t|\t" << s.name << "\t|\t" << s.mark << endl;
}
struct node
{
	student info;
	node * link;
};
node * first;
void init()
{
	first = NULL;
}
void printlist()
{
	node * p = first;
	while (p != NULL)
	{
		printstudent(p->info);
		p = p->link;
	}
	cout << endl;
}
void insertfirst(student s)
{
	node * p = new node;
	p->info = s;
	p->link = first;
	first = p;
}
int deletefirst()
{
	if (first != NULL)
	{
		node * p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}
int deletelast()
{
	if (first != NULL)
	{
		node * p = first;
		node * q = NULL;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (first == p)
			first = NULL;
		else
		{
			q->link = NULL;
			delete p;
			return 1;
		}
	}
	return 0;
}
void deleteX()
{
	student x;
	node * p = first;
	node * q = new node;
	while (p != NULL && p->info.id != x.id)
	{
		q = p;
		p = p->link;
	}
	q->link = p->link;
	delete p;
}

int menu()
{
	int choose = 0;
	cout << "-------------------------------" << endl;
	cout << "1.Nhap danh sach SV\n2.Xuat danh sach SV\n3.Xoa SV dau danh sach\n4.Xoa SV cuoi danh sach\n5.Xoa SV co ma la X\n6.Xuat thong tin SV co dtb >5\n7.Tim SV co ma la X\n8.Them mot SV vao sau SV co ma la X\n9.Sap xep danh sach tang dan theo dtb\n0.Thoat\n";
	cout << "-------------------------------" << endl;
	cout << "Chon [0-9]: ";
	cin >> choose;
	return choose;
}
void application()
{
	int choose, delf, dell, x;
	init();
	student s;
	do
	{
		choose = menu();
		switch (choose)
		{
		case 1:
			s = getstudent();
			insertfirst(s);
			cout << "Nhap danh sach thanh cong" << endl;
			break;
		case 2:
			printlist();
			cout << "Xuat danh sach thanh cong" << endl;
			break;
		case 3:
			delf = deletefirst();
			if (delf == 1)
				cout << "Xoa SV dau danh sach thanh cong" << endl;
			else
				cout << "Xoa SV dau danh sach khong thanh cong" << endl;
			break;
		case 4:
			dell = deletelast();
			if (dell == 1)
				cout << "Xoa SV cuoi danh sach thanh cong" << endl;
			else
				cout << "Xoa SV cuoi danh sach khong thanh cong" << endl;
			break;
		case 5:
			cout << "Nhap vao ma X: ";
			cin >> x;

			break;
		case 6:

			break;
		case 7:

			break;
		case 8:

			break;
		case 9:

			break;
		default:
			if (choose == 0)
				cout << "Tam biet!" << endl;
			else
				cout << "Chon khong hop le!" << endl;
		}
	} while (choose != 0);
}
int main()
{
	application();
	system("pause");
}