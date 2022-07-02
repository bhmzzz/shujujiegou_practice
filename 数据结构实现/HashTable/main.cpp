#include<iostream>
using namespace std;
#define DEFAULT_SIZE 4

typedef struct _ListNode
{
	struct _ListNode* next;
	int key;
	void* data;
}ListNode;

typedef ListNode* List;
typedef ListNode* Element;

typedef struct _HashTable
{
	int TableSize;
	List* Thelists;
}HashTable;

int Hash(int key, int TableSIze)
{
	return (key % TableSIze);
}

HashTable* InitHash(int TableSize)
{
	int i = 0;
	HashTable* hTable = nullptr;
	if (TableSize <= 0)
		TableSize = DEFAULT_SIZE;
	hTable = (HashTable*)malloc(sizeof(HashTable));
	if(hTable == nullptr)
	{
		cout << "malloc error!" << endl;
		return nullptr;
	}

	hTable->TableSize = TableSize;

	//为Hash桶分配内存空间，其为一个指针数组。
	hTable->Thelists = (List*)malloc(sizeof(List)*TableSize);
	if (hTable->Thelists == nullptr)
	{
		cout << "HashTable malloc error" << endl;
		free(hTable);
		return nullptr;
	}

	//为Hash桶对应的指针数组初始化链表节点
	for (i = 0; i < TableSize; i++)
	{
		hTable->Thelists[i] = (ListNode*)malloc(sizeof(ListNode));
		if (hTable->Thelists[i] == nullptr)
		{
			cout << "HashTable malloc error" << endl;
			free(hTable->Thelists);
			free(hTable);
			return nullptr;
		}
		else
			memset(hTable->Thelists[i], 0, sizeof(ListNode));
	}
}

Element Find(HashTable* HashTable, int key)
{
	int i = 0;
	List L = nullptr;
	Element e = nullptr;
	i = Hash(key, HashTable->TableSize);
	L = HashTable->Thelists[i];
	e = L->next;
	while (e != nullptr && e->key != key)
		e = e->next;
	return e;
}

void Insert(HashTable* HashTable, int key, void* value)
{
	Element e = nullptr, tmp = nullptr;
	List L = nullptr;
	e = Find(HashTable, key);

	if (e == nullptr)
	{
		tmp = (Element)malloc(sizeof(ListNode));
		if (tmp == nullptr)
		{
			cout << "malloc error" << endl;
			return;
		}
		L = HashTable->Thelists[Hash(key, HashTable->TableSize)];//前插法
		tmp->data = value;
		tmp->key = key;
		tmp->next = L->next;
		L->next = tmp;
	}
	else
		cout << "the key already exist" << endl;
}

void Delete(HashTable* HashTable, int key)
{
	Element e = nullptr, last = nullptr;
	List L = nullptr;
	int i = Hash(key, HashTable->TableSize);
	L = HashTable->Thelists[i];
	last = L;
	e = L->next;
	while (e != nullptr && e->key != key)
	{
		last = e;
		e = e->next;
	}

	if (e)
	{
		last->next = e->next;
		free(e);
	}
}
//哈希表元素中提取数据 
void* Retrieve(Element e)
{
	return e ? e->data : nullptr;
}

int main()
{
	char* elems[] = { (char*)"翠花",(char*)"小芳",(char*)"苍老师" };
	int i = 0;

	HashTable* HashTable = nullptr;
	HashTable = InitHash(31);
	Insert(HashTable, 1, elems[0]);
	Insert(HashTable, 2, elems[1]);
	Insert(HashTable, 3, elems[2]);
	Delete(HashTable, 1);

	for (int i = 0; i < 4; i++)
	{
		Element e = Find(HashTable, i);
		if (e)
			cout << Retrieve(e) << endl;
		else
			cout << "No found key:"<<i << endl;
	}
	return 0;
}