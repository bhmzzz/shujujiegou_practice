#include<iostream>
#include<cstdlib>
#include "LinkStack.h"
using namespace std;

#define MY_FALSE 0
#define MY_TRUE 1

struct BinaryNode {
	char ch;
	BinaryNode* lchild;
	BinaryNode* rchild;
};

//二叉树的非递归遍历
typedef struct BITREESTACKNODE {
	LinkNode node;
	BinaryNode* root;
	int flag;
}BiTreeStackNode;

//创建栈中的节点
BiTreeStackNode* CreateBiTreeStackNode(BinaryNode* node1,int flag) {
	BiTreeStackNode* newnode = new BiTreeStackNode;
	newnode->root = node1;
	newnode->flag = flag;

	return newnode;
}

void NonRecursion(BinaryNode* root)
{
	//创建栈
	LinkStack* stack = Init_LinkStack();
	Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(root, MY_FALSE));
	while (Size_LinkStack(stack)>0) {
		BiTreeStackNode* node = (BiTreeStackNode*)Top_LInkStack(stack);
		Pop_LinkStack(stack);
		
		if (node->root == nullptr)
		{
			continue;
		}
		if (node->flag == MY_TRUE)
		{
			cout << node->root->ch;
		}
		else
		{
			//右入
			Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node->root->rchild, MY_FALSE));
			//左入
			Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node->root->lchild, MY_FALSE));
			node->flag = MY_TRUE;
			Push_LinkStack(stack, (LinkNode*)node);
		}

	}

}

void Recursion(BinaryNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	cout << root->ch;
	Recursion(root->lchild);
	Recursion(root->rchild);
}

void CreateBinaryTree()
{
	BinaryNode node1 = { 'A',nullptr,nullptr };
	BinaryNode node2 = { 'B',nullptr,nullptr };
	BinaryNode node3 = { 'C',nullptr,nullptr };
	BinaryNode node4 = { 'D',nullptr,nullptr };
	BinaryNode node5 = { 'E',nullptr,nullptr };
	BinaryNode node6 = { 'F',nullptr,nullptr };
	BinaryNode node7 = { 'G',nullptr,nullptr };
	BinaryNode node8 = { 'H',nullptr,nullptr };

	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;
	

	//二叉树非递归打印
	NonRecursion(&node1);
	cout << endl;
	Recursion(&node1);
}


int main()
{
	CreateBinaryTree();
	return 0;
}