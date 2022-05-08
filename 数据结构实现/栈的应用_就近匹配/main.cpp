#include<iostream>
#include<cstdlib>
#include "LinkStack.h"
using namespace std;

//后缀表达式运算
typedef struct MYNUM
{ 
	LinkNode node;
	int val;
}MyNum;

int isNumber(char c)
{
	return c >= '0' && c <= '9';
}

int Caculate(int left,int right,char c)
{
	int ret = 0;
	switch (c)
	{
	case '+':
		ret = left + right;
		break;
	case '-':
		ret = left - right;
		break;
	case '*':
		ret = left * right;
		break;
	case '/':
		ret = left / right;
		break;
	default:
		break;
	}
	return ret;
}

int main()
{
	char* str = (char*)"831-5*+";
	char* p = str;

	LinkStack* stack = Init_LinkStack();
	while (*p != '\0')
	{
		if (isNumber(*p))
		{
			MyNum* num = new MyNum;
			num->val = *p- '0';
			Push_LinkStack(stack, (LinkNode*)num);
		}
		else
		{
			MyNum* right = (MyNum*)Top_LInkStack(stack);
			int rightnum = right->val;
			Pop_LinkStack(stack);
			delete right;

			MyNum* left = (MyNum*)Top_LInkStack(stack);
			left = (MyNum*)Top_LInkStack(stack);
			int leftnum = left->val;
			Pop_LinkStack(stack);
			delete left;

			int ret = Caculate(leftnum,rightnum,*p);
			MyNum* num = new MyNum;
			num->val = ret;
			Push_LinkStack(stack, (LinkNode*)num);
		}

		p++;
	}
	if (Size_LinkStack(stack) == 1)
	{
		MyNum* mynum = (MyNum*)Top_LInkStack(stack);
		cout <<"结果为"<< mynum->val << endl;
		Pop_LinkStack(stack);
		delete mynum;
	}
	Free_LinkStack(stack);
	return 0;
}
/*//中变后缀
//判断是否是数字
int isNumber(char c)
{
	return c >= '0' && c <= '9';
}

void NumberOperate(char* c)
{
	cout << c << endl;
}

int isLeft(char c)
{
	return c == '(';
}

int isRight(char c)
{
	return c == ')';
}

int IsOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int GetPriority(char c)
{
	int flag = 0;
	if (c == '*' || c == '/')
		flag =  2;
	if (c == '+' || c == '-')
		flag =  1;
	return flag;
}

typedef struct MYCHAR
{
	LinkNode node;
	char* p;
}MyChar;

MyChar* CreateMyChar(char* p)
{
	MyChar* mychar = new MyChar;
	mychar->p = p;
	return mychar;
}

void LeftOperate(LinkStack* stack,char* p)
{
	Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
}

void RightOperator(LinkStack* stack)
{
	while (Size_LinkStack(stack) > 0)
	{
		MyChar* mychar = (MyChar*)Top_LInkStack(stack);
		if (isLeft(*(mychar->p)))
		{
			Pop_LinkStack(stack);
			break;
		}
		cout << *(mychar->p);
		Pop_LinkStack(stack);
		delete mychar;
	}
}

void OperatorOperate(LinkStack* stack, char* p)
{


	MyChar* mychar = (MyChar*)Top_LInkStack(stack);
	if (mychar == nullptr)
	{
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
		return;
	}
	if (GetPriority(*(mychar->p)) < GetPriority(*p))
	{
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
		return;
	}
	else
	{
		while (Size_LinkStack(stack) > 0)
		{
			MyChar* mychar2 = (MyChar*)Top_LInkStack(stack);
			if (GetPriority(*(mychar2->p)) < GetPriority(*p))
			{
				Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
				break;
			}
			cout << *(mychar2->p);
			Pop_LinkStack(stack);
			delete mychar2;
		}
	}
}

int main()
{
	char* str = (char*)"8+(3-1)*5";
	char* p = str;

	LinkStack* stack = Init_LinkStack();

	while (*p != '\0')
	{
		if (isNumber(*p))
		{
			NumberOperate(p);
		}
		if (isLeft(*p))
		{
			LeftOperate(stack, p);
		}
		
		if (isRight(*p))
		{
			RightOperator(stack);
		}

		if (IsOperator(*p))
		{
			OperatorOperate(stack,p);
		}

		p++;
	}
	while (Size_LinkStack(stack) >= 0)
	{
		MyChar* mychar = (MyChar*)Top_LInkStack(stack);
		cout << *(mychar->p);
		Pop_LinkStack(stack);
		delete mychar;
	}
	cout << stack->size << endl;
	return 0;
}
*/


/*  //括号匹配
typedef struct MyChar {
	LinkNode node;
	char* pAddres;
	int index;
};

bool IsLeft(char c) {
	return c == '(';
}

bool IsRight(char c) {
	return c == ')';
}


MyChar* CreateMyChar(char* p,int index) 
{
	MyChar* mychar = new MyChar;
	mychar->pAddres = p;
	mychar->index = index;
	return mychar;
}

void SHowError(char* str, int pos)
{
	cout << str << endl;
	for (int i = 0; i < pos; i++)
	{
		cout << " ";
	}
	cout << "A";
}
int main()
{
	int index = 0;
	LinkStack* ls = Init_LinkStack();
	char* str = (char*)"1+2+6(dfs)dfsafwda((sdfs)";
	char* p = str;
	while (*p != '\0')
	{
		if (IsLeft(*p))
		{
			cout << "检测到左括号，入栈" << endl;
			Push_LinkStack(ls, (LinkNode*)CreateMyChar(p,index));
			ls->size++;
		}
		if (IsRight(*p))
		{
			if (Size_LinkStack(ls) > 0)
			{
				MyChar* ch = (MyChar*)Top_LInkStack(ls);
				if (IsLeft(*(ch->pAddres)))
				{
					cout << "匹配成功" << endl;
					Pop_LinkStack(ls);
					ls->size--;
				}
			}
			else
			{
				cout << "最终匹配失败" << endl;
				SHowError(str, index);
				
			}
		}
		p++;
		index++;
	}
	cout << ls->size << endl;
	while (Size_LinkStack(ls) > 0)
	{
		MyChar* mychar  = (MyChar*)Top_LInkStack(ls);
		cout << "左括号没有匹配的右括号" << endl;
		SHowError(str, mychar->index);
		Pop_LinkStack(ls);
	}

	return 0;
}
*/