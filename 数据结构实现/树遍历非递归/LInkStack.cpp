#include "LinkStack.h"


//初始化
LinkStack* Init_LinkStack()
{
	LinkStack* stack = new LinkStack;
	stack->node.next = nullptr;
	stack->size = 0;
	return stack;
}
//插入
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
//出栈
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
	//辅助指针
	//LinkNode* temp = &(stack->node);
	stack->node.next = stack->node.next->next;
	stack->size--;
}
//栈顶
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
//返回size
int Size_LinkStack(LinkStack* stack)
{
	if (stack == nullptr)
	{
		return -1;
	}
	return stack->size;
}
//清空栈
void Clear_LinkStack(LinkStack* stack)
{
	if (stack == nullptr)
	{
		return;
	}
	stack->node.next = nullptr;
	stack->size = 0;
}
//销毁
void Free_LinkStack(LinkStack* stack)
{
	if (stack == nullptr)
	{
		return;
	}
	delete stack;
}