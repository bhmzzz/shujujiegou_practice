#include<iostream>
#include<cstring>

//动态增长内存，将数据存放在堆上
// capacity,size
class MyArray {
private:
	int* pAddr;//存放数据地址
	int size;//当前元素个数
	int capacity;//容量，当前最大容量
public:
	MyArray();//初始化数组。
	MyArray(const MyArray& arr);//拷贝构造
	void operator=(const MyArray& arr);//重载=运算操作符
	void push_back(int value);//插入
	void remove_arrPos(int position);//根据位置删除
	void remove_arrVal(int val);//根据值删除
	void free_space();//释放内存，但不删除
	int find_pos(int val);//查找
	void print_arr();//打印
	void clear_arr();//清空数组
	int Capacity_arr();//获得capacity
	int Size_arr();//获得size
	int find_val(int pos);//根据位置查找


	~MyArray() {}
};
