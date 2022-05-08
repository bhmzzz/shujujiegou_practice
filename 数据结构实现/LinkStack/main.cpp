#include "LinkStack.h"
#include <cstdlib>

typedef struct PERSON {
	LinkNode node;
	char name[10];
	int age;
}Person;

int main()
{
	LinkStack* stack = Init_LinkStack();
	cout << stack->size << endl;
	Person p1, p2, p3, p4, p5;
	strcpy_s(p1.name, "aaa");
	strcpy_s(p2.name, "bbb");
	strcpy_s(p3.name, "ccc");
	strcpy_s(p4.name, "ddd");
	strcpy_s(p5.name, "eee");
	p1.age = 20;
	p2.age = 21;
	p3.age = 22;
	p4.age = 23;
	p5.age = 24;
	Push_LinkStack(stack, (LinkNode*)&p1);
	Push_LinkStack(stack, (LinkNode*)&p2);
	Push_LinkStack(stack, (LinkNode*)&p3);
	Push_LinkStack(stack, (LinkNode*)&p4);
	Push_LinkStack(stack, (LinkNode*)&p5);

	while (Size_LinkStack(stack) > 0)
	{
		Person* p = (Person*)Top_LInkStack(stack);
		cout << p->name << "  " << p->age << endl;
		Pop_LinkStack(stack);
	}
	Push_LinkStack(stack, (LinkNode*)&p1);
	cout << stack->size << endl;
	Clear_LinkStack(stack);
	cout << stack->size << endl;
	Free_LinkStack(stack);


	return 0;
}