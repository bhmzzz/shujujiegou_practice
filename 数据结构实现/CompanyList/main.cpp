#include"CompanyList.h"

using namespace std;
const int SIZE = 20;
typedef struct Person {
	LinkNode* data;
	char name[SIZE];
	int age;
};

void MyPrint(LinkNode* data)
{
	Person* p = (Person*)data;
	cout << p->name << " " << p->age << endl;
}

int main(void)
{
	LinkList* list = Init_LinkList();
	Person p1;
	Person p2;
	Person p3;
	Person p4;
	strcpy_s(p1.name, "aaa");
	strcpy_s(p2.name, "bbb");
	strcpy_s(p3.name, "ccc");
	strcpy_s(p4.name, "ddd");
	p1.age = 10;
	p2.age = 20;
	p3.age = 30;
	p4.age = 40;
	Insert_LinkList(list, 0, (LinkNode*)&p1);
	Insert_LinkList(list, 0, (LinkNode*)&p2);
	Insert_LinkList(list, 0, (LinkNode*)&p3);
	Insert_LinkList(list, 0, (LinkNode*)&p4);

	Print_LinkList(list, MyPrint);

	return 0;
}