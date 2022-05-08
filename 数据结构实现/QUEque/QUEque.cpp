#include "QUEque.h"
#include<cstdlib>
#include<iostream>

//初始化
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
//入队
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
//返回队头元素
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
//出队
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
//返回队尾的元素
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
//返回大小
int Size_SeqQueue(SeqQueue* sq)
{
	if (sq == nullptr)
	{
		return -1;
	}
	return sq->size;
}
//清空
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
//销毁
void Free_SeqQueue(SeqQueue* sq)
{
	delete sq;
}