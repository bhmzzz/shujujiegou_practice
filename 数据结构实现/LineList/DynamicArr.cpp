#include "DynamicArr.h"
using namespace std;

int main() {

	return 0;
}

MyArray::MyArray()
{
	//�����ڴ�
	MyArray* myArray = new MyArray;
	//��ʼ��
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
	//�жϿռ��Ƿ��㹻
	if (this->size == this->capacity)
	{
		//����һ�����Ŀռ�
		int* newSpace = new int[capacity * 2];
		//�������ݵ��¿ռ�
		memcpy(newSpace, this->pAddr, this->capacity * sizeof(int));
		//�ͷžɿռ�
		delete[] this->pAddr;
		//��������
		this->capacity = this->capacity * 2;
		this->pAddr = newSpace;
	}
	//������Ԫ��
	this->pAddr[this->size] = value;

}

void MyArray::remove_arrPos(int position)
{
	if (this->size == 0)
	{
		return;
	}
	//�ж�λ���Ƿ���Ч
	if (position < 0 || position>= this->size) {
		return;
	}
	//ɾ��Ԫ��
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
		cout << "Ϊ��" << endl;
	}
	return this->capacity;
}

int MyArray::Size_arr()
{
	if (this == NULL)
	{
		cout << "Ϊ��" << endl;
	}
	return this->size;
}

int MyArray::find_val(int pos)
{
	if (this == NULL)
	{
		cout << "Ϊ��" << endl;
	}
	return this->pAddr[pos];
}
