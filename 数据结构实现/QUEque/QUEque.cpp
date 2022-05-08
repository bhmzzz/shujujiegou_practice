#include "QUEque.h"
#include<cstdlib>
#include<iostream>

//��ʼ��
SeqQueue* Init_SeQueue()
{
	SeqQueue* squeue = new SeqQueue;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		squeue->data[i] = NULL;
	}
	squeue->size = 0;
	return squeue;
}
//���
void Push_SeQueue(SeqQueue* sq, void* data)
{
	if (sq == nullptr)
	{
		return;
	}
	if (data == nullptr)
	{
		return;
	}
	if (sq->size == MAX_SIZE)
	{
		return;
	}
	sq->data[sq->size] = data;
	sq->size++;
}
//���ض�ͷԪ��
void* Front_SeQueue(SeqQueue* sq)
{
	if (sq == nullptr)
	{
		return nullptr;
	}
	if (sq->size == 0)
	{
		return nullptr;
	}

	return sq->data[0];
}
//����
void Pop_SeqQueue(SeqQueue* sq)
{
	if (sq == nullptr)
	{
		return;
	}
	if (sq->size == 0)
	{
		return;
	}
	for (int i = 1; i < sq->size; i++)
	{
		sq->data[i - 1] = sq->data[i];
	}
	sq->size--;
}
//���ض�β��Ԫ��
void* Back_SeqQueue(SeqQueue* sq)
{
	if (sq == nullptr)
	{
		return nullptr;
	}
	if (sq->size == 0)
	{
		return nullptr;
	}
	return sq->data[sq->size-1];
}
//���ش�С
int Size_SeqQueue(SeqQueue* sq)
{
	if (sq == nullptr)
	{
		return -1;
	}
	return sq->size;
}
//���
void Clear_SeqQueue(SeqQueue* sq)
{
	if (sq == nullptr)
	{
		return;
	}
	if (sq->size == 0)
	{
		return;
	}
	for (int i = 0; i < sq->size; i++)
	{
		sq->data[i] = NULL;
	}
	sq->size = 0;
}
//����
void Free_SeqQueue(SeqQueue* sq)
{
	delete sq;
}