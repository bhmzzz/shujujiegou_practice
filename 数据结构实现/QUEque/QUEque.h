#ifndef QUEQUE_H_
#define QUEQUE_H_

#define MAX_SIZE 1024

typedef struct SEQQUEUE {
	void* data[MAX_SIZE];
	int size;
}SeqQueue;

//初始化
SeqQueue* Init_SeQueue();
//入队
void Push_SeQueue(SeqQueue* sq, void* data);
//返回队头元素
void* Front_SeQueue(SeqQueue* sq);
//出队
void Pop_SeqQueue(SeqQueue* sq);
//返回队尾的元素
void* Back_SeqQueue(SeqQueue* sq);
//返回大小
int Size_SeqQueue(SeqQueue* sq);
//清空
void Clear_SeqQueue(SeqQueue* sq);
//销毁
void Free_SeqQueue(SeqQueue* sq);







#endif QUEQUE_H_
