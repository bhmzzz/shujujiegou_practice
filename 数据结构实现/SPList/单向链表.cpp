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

	//数据插入链表
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);

	//打印
	Print_LinkList(list, MyPrint);
	cout << endl;
	cout << list->size << endl;

	//销毁
	Free_space(list);
	return 0;
}

//初始化链表
LinkList* Init_LinkList()
{
	LinkList* list = new LinkList;
	list->size = 0;
	//头节点 不保存数据
	list->head = new LinkNode;
	list->head->data = NULL;
	list->head->next = NULL;
	return list;
}

//指定位置插入
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

	//友好地处理,pos越界
	if (pos<0 || pos>list->size)
	{
		pos = list->size;
	}

	//创建新的节点
	LinkNode* newnode = new LinkNode;
	newnode->data = data;
	newnode->next = NULL;

	//找节点
	//辅助指针变量
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//新节点入链表
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;
	list->size++;
	cout << "插入成功" << endl;

}
//删除指定位置的值
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

	//查找删除结点的前一个结点
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
//获得链表的长度
int Size_LinkList(LinkList* list)
{
	return list->size;
}
//返回第一个节点
void* Front_LinkList(LinkList* list)
{
	return list->head->next;
}
//查找
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
	//遍历
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
//打印链表节点
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
//释放链表的内存
void Free_space(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}

	LinkNode* pCurrent = list->head;
	while (pCurrent != NULL)
	{
		//缓存下一个节点
		LinkNode* pNext = pCurrent->next;
		delete pCurrent;
		pCurrent = pNext;
	}
	list->size = 0;
	delete list;
}



