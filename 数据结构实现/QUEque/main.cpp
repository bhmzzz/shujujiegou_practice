#include "QUEque.h"
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

typedef struct PERSON {
	char name[30];
	int age;
}Person;

int main()
{
	SeqQueue* queue = Init_SeQueue();
	Person p1 = { "aaa",10 };
	Person p2 = { "bbb",20 };
	Person p3 = { "ccc",30 };
	Person p4 = { "ddd",40 };
	Person p5 = { "eee",50 };
	Push_SeQueue(queue, &p1);
	Push_SeQueue(queue, &p2);
	Push_SeQueue(queue, &p3);
	Push_SeQueue(queue, &p4);
	Push_SeQueue(queue, &p5);

	Person* bp = (Person*)Back_SeqQueue(queue);
	cout << bp->name << "  " << bp->age << endl;

	while (Size_SeqQueue(queue) > 0)
	{
		Person* p = (Person*)Front_SeQueue(queue);
		cout << p->name << "  " << p->age << endl;
		Pop_SeqQueue(queue);
	}


	Free_SeqQueue(queue);
	return 0;
}