#ifndef LINKLIST_H_
#define LINKLIST_H_
#include<iostream>
#include <cstdlib>

//������
typedef struct LINKNODE {
	void* data;   //ָ���κ����͵�����
	struct LINKNODE* next;
}LinkNode;

//����ṹ��
typedef struct LINKLIST {
	LinkNode* head;
	int size;
	
}LinkList;

//��ӡ����ָ��
typedef void(*PRINTLINKNODE)(void*);
//��ʼ������
LinkList* Init_LinkList();
//ָ��λ�ò���
void Insert_LinkList(LinkList* list,int pos,void* data);
//ɾ��ָ��λ�õ�ֵ
void RemoveByPos_LinkList(LinkList* list, int pos);
//�������ĳ���
int Size_LinkList(LinkList* list);
//���ص�һ���ڵ�
void* Front_LinkList(LinkList* list);
//����
int Find_LinkList(LinkList* list, void* data);
//��ӡ����ڵ�
void Print_LinkList(LinkList* list, PRINTLINKNODE print);
//�ͷ�������ڴ�
void Free_space(LinkList* list);

#endif
