#include "SeqStack.h"

typedef struct PERSON {
	char name[64];
	int age;
}Person;

int main()
{
	//创建栈
	SeqStack* stack = Init_SeqStack();
	//创建数据
	Person p1 = { "aaa",10 };
	Person p2 = { "bbb",20 };
	Person p3 = { "ccc",30 };
	Person p4 = { "ddd",40 };
	Person p5 = { "eee",50 };
	//入栈
	Push_SeqStack(stack, &p1);
	Push_SeqStack(stack, &p2);
	Push_SeqStack(stack, &p3);
	Push_SeqStack(stack, &p4);
	Push_SeqStack(stack, &p5);

	//输出
	while (Size_SeqStack(stack) > 0)
	{
		//从栈顶弹出元素
		Person* pp = (Person*)Top_SeqStack(stack);
		cout << pp->name << " " << pp->age << endl;
		//弹出
		Pop_SeqStack(stack);

	}
	//释放内存
	FreeSpace_SeqStack(stack);
	return 0;
}