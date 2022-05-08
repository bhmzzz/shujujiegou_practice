#ifndef LINKSTACK_H_
#define LINKSTACK_H_
#include<iostream>
using namespace std;

//链式栈的节点
typedef struct LINKNODE {
	struct LINKNODE* next;
}LinkNode;

//链式栈
typedef struct LINKSTACK {
	LinkNode node;
	int size;
}LinkStack;

//初始化
LinkStack* Init_LinkStack();
//插入
void Push_LinkStack(LinkStack* stack, LinkNode* data);
//出栈
void Pop_LinkStack(LinkStack* stack);
//栈顶
LinkNode* Top_LInkStack(LinkStack* stack);
//返回size
int Size_LinkStack(LinkStack* stack);
//清空栈
void Clear_LinkStack(LinkStack* stack);
//销毁
void Free_LinkStack(LinkStack* stack);










#endif LINKSTACK_H_

