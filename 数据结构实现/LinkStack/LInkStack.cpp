#include "LinkStack.h"


//��ʼ��
LinkStack* Init_LinkStack()
{
	LinkStack* stack = new LinkStack;
	stack->node.next = nullptr;
	stack->size = 0;
	return stack;
}
//����
void Push_LinkStack(LinkStack* stack, LinkNode* data)
{
	if (stack == nullptr)
	{
		return;
	}
	data->next = stack->node.next;
	stack->node.next = data;
	stack->size++;

}
//��ջ
void Pop_LinkStack(LinkStack* stack)
{
	if (stack == nullptr)
	{
		return;
	}
	if (stack->size == 0)
	{
		return;
	}
	//����ָ��
	//LinkNode* temp = &(stack->node);
	stack->node.next = stack->node.next->next;
	stack->size--;
}
//ջ��
LinkNode* Top_LInkStack(LinkStack* stack)
{
	if (stack == nullptr)
	{
		return nullptr;
	}
	if (stack->size == 0)
	{
		return nullptr;
	}
	
	return stack->node.next;
}
//����size
int Size_LinkStack(LinkStack* stack)
{
	if (stack == nullptr)
	{
		return -1;
	}
	return stack->size;
}
//���ջ
void Clear_LinkStack(LinkStack* stack)
{
	if (stack == nullptr)
	{
		return;
	}
	stack->node.next = nullptr;
	stack->size = 0;
}
//����
void Free_LinkStack(LinkStack* stack)
{
	if (stack == nullptr)
	{
		return;
	}
	delete stack;
}