#include "LinkList.h"
using namespace std;

typedef struct PERSON
{
	char name[64];
	int age;
	int score;
}Person;

void MyPrint(void* data)
{
	Person* p = (Person*)data;
	cout << p->name << " " << p->age << "  " << p->score << endl;
}

int main(void)
{
	LinkList* list = Init_LinkList();
	Person p1 = { "aaa",18,100 };
	Person p2 = { "bbb",19,99 };
	Person p3 = { "ccc",20,98 };
	Person p4 = { "ddd",21,59 };

	//���ݲ�������
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);

	//��ӡ
	Print_LinkList(list, MyPrint);
	cout << endl;
	cout << list->size << endl;

	//����
	Free_space(list);
	return 0;
}

//��ʼ������
LinkList* Init_LinkList()
{
	LinkList* list = new LinkList;
	list->size = 0;
	//ͷ�ڵ� ����������
	list->head = new LinkNode;
	list->head->data = NULL;
	list->head->next = NULL;
	return list;
}

//ָ��λ�ò���
void Insert_LinkList(LinkList* list, int pos, void* data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL) 
	{
		return;
	}

	//�Ѻõش���,posԽ��
	if (pos<0 || pos>list->size)
	{
		pos = list->size;
	}

	//�����µĽڵ�
	LinkNode* newnode = new LinkNode;
	newnode->data = data;
	newnode->next = NULL;

	//�ҽڵ�
	//����ָ�����
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//�½ڵ�������
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;
	list->size++;
	cout << "����ɹ�" << endl;

}
//ɾ��ָ��λ�õ�ֵ
void RemoveByPos_LinkList(LinkList* list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	if (pos < 0 || pos >= list->size)
	{
		return;
	}

	//����ɾ������ǰһ�����
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	LinkNode* newnode;
	newnode = pCurrent->next;
	pCurrent->next = newnode->next;
	delete newnode;

	list->size--;

}
//�������ĳ���
int Size_LinkList(LinkList* list)
{
	return list->size;
}
//���ص�һ���ڵ�
void* Front_LinkList(LinkList* list)
{
	return list->head->next;
}
//����
int Find_LinkList(LinkList* list, void* data)
{
	if (list == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -1;
	}
	//����
	LinkNode* pCurrent = list->head->next;
	int i = 0;
	while (pCurrent != NULL)
	{
		if (pCurrent->data == data)
		{
			break;
		}
		i++;
		pCurrent = pCurrent->next;
	}


	return i;
}
//��ӡ����ڵ�
void Print_LinkList(LinkList* list, PRINTLINKNODE print)
{
	if (list == NULL)
	{
		return;
	}
	LinkNode* pCurrent = list->head->next;
	while (pCurrent != NULL)
	{
		print(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}
//�ͷ�������ڴ�
void Free_space(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}

	LinkNode* pCurrent = list->head;
	while (pCurrent != NULL)
	{
		//������һ���ڵ�
		LinkNode* pNext = pCurrent->next;
		delete pCurrent;
		pCurrent = pNext;
	}
	list->size = 0;
	delete list;
}



