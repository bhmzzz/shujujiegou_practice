#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

//二叉树结点
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

	//输出根节点
	cout << root->ch << " ";

	//遍历左子树
	Recursion(root->lchild);

	//遍历右子树
	Recursion(root->rchild);
}

void CaculateLeafNum(BinaryNode* root,int* leafNum)
{
	if (root == nullptr)
		return;
	if (root->lchild == nullptr && root->rchild == nullptr)
		(*leafNum)++;
	//左子树叶子节点数目
	CaculateLeafNum(root->lchild, leafNum);
	//右子树叶子节点数目
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
	//释放所有树
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
	//递归遍历
	//Recursion(&node1);
	//求叶子节点数目
	//int leafNum = 0;
	//CaculateLeafNum(&node1, &leafNum);
	//cout << "叶子结点的数目：" << leafNum << endl;
	//求二叉树的高度

	//拷贝二叉树
	BinaryNode* root = CopyBinaryTree(&node1);
	Recursion(root);
	FreeSpaceBinaryTree(root);
}

int main()
{
	CreateBinaryTree();
	return 0;
}