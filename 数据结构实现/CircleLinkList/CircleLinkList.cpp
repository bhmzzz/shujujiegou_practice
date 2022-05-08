#include "CircleLinkList.h"


//��ʼ��
Circlelinklist* Init_CircleLinkList()
{
	Circlelinklist* clist = new Circlelinklist;
	clist->head.next = &(clist->head);
	clist->size = 0;
	return clist;
}
//����
void Insert_CircleLinkList(Circlelinklist* clist, int pos, Circlelinknode* data)
{
	if (clist == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (pos < 0 || pos > clist->size)
	{
		pos = clist->size;
	}
	//����λ�ò��ҽڵ�
	Circlelinknode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//������������
	data->next = pCurrent->next;
	pCurrent->next = data;

	clist->size++;
}
//��õ�һ��Ԫ��
Circlelinknode* Front_CircleLinkList(Circlelinklist* clist)
{
	return clist->head.next;
}
//����λ��ɾ��
void RemoveByPos_CircleLinkList(Circlelinklist* clist, int pos)
{
	if (clist == NULL)
	{
		return;
	}
	if (pos < 0 || pos >= clist->size)
	{
		return;
	}
	//����pos�ҽڵ�
	//����ָ�����
	Circlelinknode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//���浱ǰ�ڵ����һ���ڵ�
	Circlelinknode* pNext = pCurrent->next;
	pCurrent->next = pCurrent->next->next;

	clist->size--;
}
//����ֵɾ��
void RemoveByVal_CircleLinkList(Circlelinklist* clist, Circlelinknode* data, COMPARENODE compare)
{
	if (clist == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	Circlelinknode* pPrev = &(clist->head);
	Circlelinknode* pCurrent = pPrev->next;
	int i = 0;
	for (i = 0; i < clist->size; i++)
	{
		if (compare(pCurrent,data) == CIRCLELINKLIST_TRUE)
		{
			pPrev->next = pCurrent->next;
			break;
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
	clist->size--;
}
//�������ĳ���
int Size_CircleLinkList(Circlelinklist* clist)
{
	return clist->size;
}
//�ж��Ƿ�Ϊ��
int IsEmpty_CircleLinkList(Circlelinklist* clist)
{
	if (clist->size == 0)
	{
		return CIRCLELINKLIST_TRUE;
	}
	return CIRCLELINKLIST_FALSE;
}
//����
int Find_CircleLinkList(Circlelinklist* clist, Circlelinknode* data, COMPARENODE compare)
{
	if (clist == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -1;
	}

	Circlelinknode* pCurrent = clist->head.next;
	int flag;
	for (int i = 0; i < clist->size; i++)
	{
		if (compare(pCurrent, data) == CIRCLELINKLIST_TRUE)
		{
			flag = i;
			break;
		}
		pCurrent = pCurrent->next;
	}

	return flag;
}
//��ӡ
void Print_CircleLinkList(Circlelinklist* clist, PRINTNODE print)
{
	if (clist == NULL)
	{
		return;
	}

	//����ָ�����
	Circlelinknode* pCurrent = clist->head.next;
	for (int i = 0; i < clist->size*2; i++)
	{
		if (pCurrent == &(clist->head))
		{
			pCurrent = pCurrent->next;
		}
		print(pCurrent);
		pCurrent = pCurrent->next;
	}
}
//�ͷ��ڴ�
void FreeSpace_CircleLinkList(Circlelinklist* clist)
{
	if (clist == NULL)
	{
		return;
	}
	delete [] clist;
}