#include<iostream>
#include<cstring>

//��̬�����ڴ棬�����ݴ���ڶ���
// capacity,size
class MyArray {
private:
	int* pAddr;//������ݵ�ַ
	int size;//��ǰԪ�ظ���
	int capacity;//��������ǰ�������
public:
	MyArray();//��ʼ�����顣
	MyArray(const MyArray& arr);//��������
	void operator=(const MyArray& arr);//����=���������
	void push_back(int value);//����
	void remove_arrPos(int position);//����λ��ɾ��
	void remove_arrVal(int val);//����ֵɾ��
	void free_space();//�ͷ��ڴ棬����ɾ��
	int find_pos(int val);//����
	void print_arr();//��ӡ
	void clear_arr();//�������
	int Capacity_arr();//���capacity
	int Size_arr();//���size
	int find_val(int pos);//����λ�ò���


	~MyArray() {}
};
