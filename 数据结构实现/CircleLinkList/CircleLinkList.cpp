#include "CircleLinkList.h"


//初始化
Circlelinklist* Init_CircleLinkList()
{
	Circlelinklist* clist = new Circlelinklist;
	clist->head.next = &(clist->head);
	clist->size = 0;
	return clist;
}
//插入
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
	//根据位置查找节点
	Circlelinknode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//新数据入链表
	data->next = pCurrent->next;
	pCurrent->next = data;

	clist->size++;
}
//获得第一个元素
Circlelinknode* Front_CircleLinkList(Circlelinklist* clist)
{
	return clist->head.next;
}
//根据位置删除
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
	//根据pos找节点
	//辅助指针变量
	Circlelinknode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//缓存当前节点的下一个节点
	Circlelinknode* pNext = pCurrent->next;
	pCurrent->next = pCurrent->next->next;

	clist->size--;
}
//根据值删除
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
//获得链表的长度
int Size_CircleLinkList(Circlelinklist* clist)
{
	return clist->size;
}
//判断是否为空
int IsEmpty_CircleLinkList(Circlelinklist* clist)
{
	if (clist->size == 0)
	{
		return CIRCLELINKLIST_TRUE;
	}
	return CIRCLELINKLIST_FALSE;
}
//查找
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
//打印
void Print_CircleLinkList(Circlelinklist* clist, PRINTNODE print)
{
	if (clist == NULL)
	{
		return;
	}

	//辅助指针变量
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
//释放内存
void FreeSpace_CircleLinkList(Circlelinklist* clist)
{
	if (clist == NULL)
	{
		return;
	}
	delete [] clist;
}