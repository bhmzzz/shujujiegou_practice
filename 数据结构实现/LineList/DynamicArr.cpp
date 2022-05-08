#include "DynamicArr.h"
using namespace std;

int main() {

	return 0;
}

MyArray::MyArray()
{
	//申请内存
	MyArray* myArray = new MyArray;
	//初始化
	myArray->size = 0;
	myArray->capacity = 20;
	myArray->pAddr = new int[capacity];
}

MyArray::MyArray(const MyArray& arr)
{
	pAddr = new int[arr.capacity];
	*pAddr = *arr.pAddr;
	size = arr.size;
	capacity = arr.capacity;
}

void MyArray::operator=(const MyArray& arr)
{
	pAddr = new int[arr.capacity];
	*pAddr = *arr.pAddr;
	size = arr.size;
	capacity = arr.capacity;
}

void MyArray::push_back(int value)
{
	if (this == NULL)
	{
		return;
	}
	//判断空间是否足够
	if (this->size == this->capacity)
	{
		//申请一块更大的空间
		int* newSpace = new int[capacity * 2];
		//拷贝数据到新空间
		memcpy(newSpace, this->pAddr, this->capacity * sizeof(int));
		//释放旧空间
		delete[] this->pAddr;
		//更新容量
		this->capacity = this->capacity * 2;
		this->pAddr = newSpace;
	}
	//插入新元素
	this->pAddr[this->size] = value;

}

void MyArray::remove_arrPos(int position)
{
	if (this->size == 0)
	{
		return;
	}
	//判断位置是否有效
	if (position < 0 || position>= this->size) {
		return;
	}
	//删除元素
	for (int i = position - 1; i < this->size-1; i++)
	{
		this->pAddr[i] = this->pAddr[i + 1];
	}
	this->size--;
}

void MyArray::remove_arrVal(int val)
{
	if (this->size == 0)
	{
		return;
	}
	int pos;
	for (int i = 0; i < this->size; i++)
	{
		if (this->pAddr[i] == val)
		{
			pos = i;
		}
	}
	remove_arrPos(pos);
}

void MyArray::free_space()
{
	if (this == NULL)
	{
		return;
	}
	if (this->pAddr != NULL)
	{
		delete[] this->pAddr;
	}
	delete this;
}

int MyArray::find_pos(int val)
{
	return NULL;
}

void MyArray::print_arr()
{
	if (this == NULL)
	{
		return;
	}
	for (int i = 0; i < this->size; i++)
	{
		cout << this->pAddr[i]<<"  ";
	}
	cout << endl;
}

void MyArray::clear_arr()
{
	if (this == NULL)
	{
		return;
	}
	this->size = 0;
}

int MyArray::Capacity_arr()
{
	if (this == NULL)
	{
		cout << "为空" << endl;
	}
	return this->capacity;
}

int MyArray::Size_arr()
{
	if (this == NULL)
	{
		cout << "为空" << endl;
	}
	return this->size;
}

int MyArray::find_val(int pos)
{
	if (this == NULL)
	{
		cout << "为空" << endl;
	}
	return this->pAddr[pos];
}
