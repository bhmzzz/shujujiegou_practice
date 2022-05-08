#include"CompanyList.h"



//初始化链表
LinkList* Init_LinkList()
{
	LinkList* list = new LinkList;
	list->head.next = NULL;
	list->size = 0;
	return list;
}
//插入
void Insert_LinkList(LinkList* list, int pos, LinkNode* data)
{
	if (list == NULL)
		return;
	if (data == NULL)
		return;
	if (pos<0 || pos>list->size)
		pos = list->size;

	//查找插入位置
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//插入新节点
	data->next = pCurrent->next;
	pCurrent->next = data;

	list->size++;
}
//删除
void Remove_LinkList(LinkList* list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	if (pos < 0 || pos >= list->size)
	{
		return;
	}
	//辅助指针变量
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//删除节点
	pCurrent->next = pCurrent->next->next;
	list->size--;
}
//查找
int Find_LinkList(LinkList* list, LinkNode* data, COMPARENODE compare)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	//辅助指针
	LinkNode* pCurrent = list->head.next;
	int index = 0;
	while (pCurrent != NULL)
	{
		if (compare(pCurrent, data) == 0)
		{
			break;
		}
		pCurrent = pCurrent->next;
		index++;
	}
	return index;
}
//返回链表大小
int Size_LinkList(LinkList* list)
{
	return 0;
}
//打印
void Print_LinkList(LinkList* list, PRINTNODE print)
{
	if (list == NULL)
		return;
	//辅助指针
	LinkNode* pCurrent = list->head.next;
	while (pCurrent != NULL)
	{
		print(pCurrent);
		pCurrent = pCurrent->next;
	}
}
//释放链表内存
void FreeSpace_LinkList(LinkList* list)
{
	if (list == NULL)
		return;
	delete list;
}