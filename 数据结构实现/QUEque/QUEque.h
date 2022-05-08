#ifndef QUEQUE_H_
#define QUEQUE_H_

#define MAX_SIZE 1024

typedef struct SEQQUEUE {
	void* data[MAX_SIZE];
	int size;
}SeqQueue;

//��ʼ��
SeqQueue* Init_SeQueue();
//���
void Push_SeQueue(SeqQueue* sq, void* data);
//���ض�ͷԪ��
void* Front_SeQueue(SeqQueue* sq);
//����
void Pop_SeqQueue(SeqQueue* sq);
//���ض�β��Ԫ��
void* Back_SeqQueue(SeqQueue* sq);
//���ش�С
int Size_SeqQueue(SeqQueue* sq);
//���
void Clear_SeqQueue(SeqQueue* sq);
//����
void Free_SeqQueue(SeqQueue* sq);







#endif QUEQUE_H_
