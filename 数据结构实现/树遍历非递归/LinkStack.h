#ifndef LINKSTACK_H_
#define LINKSTACK_H_
#include<iostream>
using namespace std;

//��ʽջ�Ľڵ�
typedef struct LINKNODE {
	struct LINKNODE* next;
}LinkNode;

//��ʽջ
typedef struct LINKSTACK {
	LinkNode node;
	int size;
}LinkStack;

//��ʼ��
LinkStack* Init_LinkStack();
//����
void Push_LinkStack(LinkStack* stack, LinkNode* data);
//��ջ
void Pop_LinkStack(LinkStack* stack);
//ջ��
LinkNode* Top_LInkStack(LinkStack* stack);
//����size
int Size_LinkStack(LinkStack* stack);
//���ջ
void Clear_LinkStack(LinkStack* stack);
//����
void Free_LinkStack(LinkStack* stack);










#endif LINKSTACK_H_

