#ifndef CIRCLELINKLIST_H_
#define CIRCLELINKLIST_H_
#include<iostream>
#include<cstdlib>

#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0

//链表的小结点
typedef struct CIRCLELINKNODE {
	struct CIRCLELINKNODE* next;
}Circlelinknode;

//链表结构体
typedef struct CIRCLELINKLIST {
	Circlelinknode head;
	int size;
}Circlelinklist;

//编写针对链表结构体操作的API
// 打印回调
typedef void(*PRINTNODE)(Circlelinknode*);
//比较回调 
typedef int(*COMPARENODE)(Circlelinknode*, Circlelinknode*);
//初始化
Circlelinklist* Init_CircleLinkList();
//插入
void Insert_CircleLinkList(Circlelinklist* clist, int pos, Circlelinknode* data);
//获得第一个元素
Circlelinknode* Front_CircleLinkList(Circlelinklist* clist);
//根据位置删除
void RemoveByPos_CircleLinkList(Circlelinklist* clist,int pos);
//根据值删除
void RemoveByVal_CircleLinkList(Circlelinklist* clist, Circlelinknode* data, COMPARENODE compare);
//获得链表的长度
int Size_CircleLinkList(Circlelinklist* clist);
//判断是否为空
int IsEmpty_CircleLinkList(Circlelinklist* clist);
//查找
int Find_CircleLinkList(Circlelinklist* clist, Circlelinknode* data, COMPARENODE compare);
//打印
void Print_CircleLinkList(Circlelinklist* clist, PRINTNODE print);
//释放内存
void FreeSpace_CircleLinkList(Circlelinklist* clist);

#endif
