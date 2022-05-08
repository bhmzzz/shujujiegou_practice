#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

//���������
struct BinaryNode {
	char ch;
	BinaryNode* lchild;
	BinaryNode* rchild;
};

void Recursion(BinaryNode* root)
{
	if (root == nullptr)
	{
		return;
	}

	//������ڵ�
	cout << root->ch << " ";

	//����������
	Recursion(root->lchild);

	//����������
	Recursion(root->rchild);
}

void CaculateLeafNum(BinaryNode* root,int* leafNum)
{
	if (root == nullptr)
		return;
	if (root->lchild == nullptr && root->rchild == nullptr)
		(*leafNum)++;
	//������Ҷ�ӽڵ���Ŀ
	CaculateLeafNum(root->lchild, leafNum);
	//������Ҷ�ӽڵ���Ŀ
	CaculateLeafNum(root->rchild, leafNum);
}

BinaryNode* CopyBinaryTree(BinaryNode* root)
{
	if (root == nullptr)
	{
		return nullptr;
	}

	BinaryNode* lchild = CopyBinaryTree(root->lchild);
	BinaryNode* rchild = CopyBinaryTree(root->rchild);

	BinaryNode* newnode = new BinaryNode;
	newnode->ch = root->ch;
	newnode->lchild = lchild;
	newnode->rchild = rchild;

	return newnode;
}

void FreeSpaceBinaryTree(BinaryNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	//�ͷ�������
	FreeSpaceBinaryTree(root->lchild);
	FreeSpaceBinaryTree(root->rchild);

	delete root;
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
	//�ݹ����
	//Recursion(&node1);
	//��Ҷ�ӽڵ���Ŀ
	//int leafNum = 0;
	//CaculateLeafNum(&node1, &leafNum);
	//cout << "Ҷ�ӽ�����Ŀ��" << leafNum << endl;
	//��������ĸ߶�

	//����������
	BinaryNode* root = CopyBinaryTree(&node1);
	Recursion(root);
	FreeSpaceBinaryTree(root);
}

int main()
{
	CreateBinaryTree();
	return 0;
}