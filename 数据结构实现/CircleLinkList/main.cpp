#include "CircleLinkList.h"
#include <iostream>
using namespace std;
typedef struct PERSON {
	Circlelinknode node;
	char name[64];
	int age;
	int score;
}Person;

void MyPrint(Circlelinknode* data)
{
	Person* p = (Person*)data;
	cout << p->name << " " << p->age << " " << p->score << endl;
}

int MyCompare(Circlelinknode* data1,Circlelinknode* data2) {
	Person* p1 = (Person*)data1;
	Person* p2 = (Person*)data2;

	if (strcmp(p1->name, p2->name)==0 && p1->age == p2->age && p1->score == p2->score) {
		return CIRCLELINKLIST_TRUE;
	}
	return CIRCLELINKLIST_FALSE;
}
int main()
{
	Circlelinklist* clist = Init_CircleLinkList();

	Person p1, p2, p3, p4, p5;
	strcpy_s(p1.name, "aaa");
	strcpy_s(p2.name, "bbb");
	strcpy_s(p3.name, "ccc");
	strcpy_s(p4.name, "ddd");
	strcpy_s(p5.name, "eee");

	p1.age = 10;
	p2.age = 20;
	p3.age = 30;
	p4.age = 40;
	p5.age = 50;

	p1.score = 50;
	p2.score = 60;
	p3.score = 70;
	p4.score = 80;
	p5.score = 90;

	Insert_CircleLinkList(clist, 100, (Circlelinknode*)&p1);
	Insert_CircleLinkList(clist, 100, (Circlelinknode*)&p2);
	Insert_CircleLinkList(clist, 100, (Circlelinknode*)&p3);
	Insert_CircleLinkList(clist, 100, (Circlelinknode*)&p4);
	Insert_CircleLinkList(clist, 100, (Circlelinknode*)&p5);

	Print_CircleLinkList(clist, MyPrint);

	Person pDel;
	strcpy_s(pDel.name, "ccc");
	pDel.age = 40;
	pDel.score = 65;

	RemoveByVal_CircleLinkList(clist, (Circlelinknode*)&pDel, MyCompare);
	
	Print_CircleLinkList(clist, MyPrint);

	FreeSpace_CircleLinkList(clist);
	return 0;
}