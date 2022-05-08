#include"CompanyList.h"



//��ʼ������
LinkList* Init_LinkList()
{
	LinkList* list = new LinkList;
	list->head.next = NULL;
	list->size = 0;
	return list;
}
//����
void Insert_LinkList(LinkList* list, int pos, LinkNode* data)
{
	if (list == NULL)
		return;
	if (data == NULL)
		return;
	if (pos<0 || pos>list->size)
		pos = list->size;

	//���Ҳ���λ��
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//�����½ڵ�
	data->next = pCurrent->next;
	pCurrent->next = data;

	list->size++;
}
//ɾ��
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
	//����ָ�����
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//ɾ���ڵ�
	pCurrent->next = pCurrent->next->next;
	list->size--;
}
//����
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
	//����ָ��
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
//���������С
int Size_LinkList(LinkList* list)
{
	return 0;
}
//��ӡ
void Print_LinkList(LinkList* list, PRINTNODE print)
{
	if (list == NULL)
		return;
	//����ָ��
	LinkNode* pCurrent = list->head.next;
	while (pCurrent != NULL)
	{
		print(pCurrent);
		pCurrent = pCurrent->next;
	}
}
//�ͷ������ڴ�
void FreeSpace_LinkList(LinkList* list)
{
	if (list == NULL)
		return;
	delete list;
}