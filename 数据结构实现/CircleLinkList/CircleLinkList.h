#ifndef CIRCLELINKLIST_H_
#define CIRCLELINKLIST_H_
#include<iostream>
#include<cstdlib>

#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0

//�����С���
typedef struct CIRCLELINKNODE {
	struct CIRCLELINKNODE* next;
}Circlelinknode;

//����ṹ��
typedef struct CIRCLELINKLIST {
	Circlelinknode head;
	int size;
}Circlelinklist;

//��д�������ṹ�������API
// ��ӡ�ص�
typedef void(*PRINTNODE)(Circlelinknode*);
//�Ƚϻص� 
typedef int(*COMPARENODE)(Circlelinknode*, Circlelinknode*);
//��ʼ��
Circlelinklist* Init_CircleLinkList();
//����
void Insert_CircleLinkList(Circlelinklist* clist, int pos, Circlelinknode* data);
//��õ�һ��Ԫ��
Circlelinknode* Front_CircleLinkList(Circlelinklist* clist);
//����λ��ɾ��
void RemoveByPos_CircleLinkList(Circlelinklist* clist,int pos);
//����ֵɾ��
void RemoveByVal_CircleLinkList(Circlelinklist* clist, Circlelinknode* data, COMPARENODE compare);
//�������ĳ���
int Size_CircleLinkList(Circlelinklist* clist);
//�ж��Ƿ�Ϊ��
int IsEmpty_CircleLinkList(Circlelinklist* clist);
//����
int Find_CircleLinkList(Circlelinklist* clist, Circlelinknode* data, COMPARENODE compare);
//��ӡ
void Print_CircleLinkList(Circlelinklist* clist, PRINTNODE print);
//�ͷ��ڴ�
void FreeSpace_CircleLinkList(Circlelinklist* clist);

#endif
