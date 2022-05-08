#include "SeqStack.h"

//��ʼ��ջ
SeqStack* Init_SeqStack()
{
	SeqStack* stack = new SeqStack;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		stack->data[i] = NULL;
	}
	stack->size = 0;
	return stack;
}
//��ջ
void Push_SeqStack(SeqStack* stack, void* data)
{
	if (stack == NULL)
	{
		return;
	}
	if (stack->size == MAX_SIZE)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	stack->data[stack->size] = data;
	stack->size++;
}
//����ջ��Ԫ��
void* Top_SeqStack(SeqStack* stack)
{
	if (stack == NULL)
	{
		return nullptr;
	}
	if (stack->size == 0)
	{
		return nullptr;
	}
	return stack->data[stack->size-1];
}
//��ջ
void Pop_SeqStack(SeqStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	if (stack->size == 0)
	{
		return;
	}
	stack->data[stack->size - 1] = nullptr;
	stack->size--;
}
//�п�
bool IsEmpty(SeqStack* stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	if (stack->size == 0)
	{
		return SEQSTACK_TRUE;
	}
	return SEQSTACK_FALSE;
}
//����ջ��Ԫ�صĸ���
int Size_SeqStack(SeqStack* stack)
{
	return stack->size;
}
//���
void Clear_SeqStack(SeqStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	for (int i = 0; i < stack->size; i++)
	{
		stack->data[i] = nullptr;
	}
	stack->size = 0;
}
//����
void FreeSpace_SeqStack(SeqStack* stack)
{
	if (stack == nullptr)
	{
		return;
	}
	delete stack;
}