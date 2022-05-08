#include<iostream>
#include<ctime>
using namespace std;

#define MAX 10
 
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int* CreateArray()
{
	int* arr = new int[10];
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	return arr;
}

//冒泡
int flag = 0; //0 表示没有排序好
void BubbleSort(int arr[],int length)
{
	for (int i = 0; i < length-1; i++)
	{
		flag = 1;//表示排序好了
		for (int j = 0; j < length-i-1; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				flag = 0;
				Swap(&arr[j + 1],&arr[j]);
			}
		}
	}
}

void PrintArray(int arr[],int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;
}
//选择
void SelectSort(int arr[], int length)
{
	int min = 0;
	for (int i = 0; i < length-1; i++)
	{
		min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			Swap(&arr[min], &arr[i]);
		}
	}
}

//插入
void InsertSort(int arr[],int length)
{
	int j;
	for (int i = 1; i < length; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			int temp = arr[i];
			for (j = i - 1; j >= 0 && temp < arr[j]; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}

//希尔
void ShellSort(int arr[], int length)
{
	int increasement = length; //增量
	int i, j,k;
	do {
		//确定分组的增量
		increasement = increasement / 3 + 1;
		for (i = 0; i < increasement; i++)
		{
			for (j = i + increasement; j < length; j+= increasement)
			{
				if (arr[j] < arr[j - increasement])
				{
					int temp = arr[j];
					for (k = j - increasement; k >= 0 && temp < arr[k]; k -= increasement)
					{
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = temp;
				}
			}
		}
	} while (increasement > 1);
}

//快速
void QuickSort(int arr[],int start,int end)
{
	int i = start;
	int j = end;
	int temp = arr[start];//基准数
	if (i < j)
	{

		while (i<j)
		{
			while (i < j && arr[j]>=temp)
			{
				j--;
			}
			if (i < j) {
				arr[i] = arr[j];
				i++;
			}
			while (i < j && arr[i] < temp)
			{
				i++;
			}
			if (i < j) {
				arr[j] = arr[i];
				j--;
			}
		}
		arr[i] = temp;
		//对左半部分进行快速排序
		QuickSort(arr,start,i-1);
		//对右半部分进行快排
		QuickSort(arr, i + 1, end);
	}
}
//合并算法
void Merge(int arr[], int start, int end, int mid, int* temp)
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;

	//表示辅助空间有多少元素
	int length = 0;
	//合并两个序列
	while (i_start <= i_end && j_start <= j_end)
	{
		if (arr[i_start < arr[j_start]])
		{
			temp[length] = arr[i_start];
			length++;
			i_start++;
		}
		else
		{
			temp[length] = arr[j_start];
			j_start++;
			length++;
		}

	}
	//i这个序列
	while (i_start <= i_end)
	{
		temp[length] = arr[i_start];
		i_start++;
		length++;
	}
	//j序列
	while (j_start <= j_end)
	{
		temp[length] = arr[j_start];
		length++;
		j_start++;
	}

	//辅助空间中的数据覆盖到原空间
	for (int i = 0; i < length; i++)
	{
		arr[start + i] = temp[i];
	}
}

//归并
void MergeSort(int arr[],int start,int end,int* temp)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	//分组
	//左半边
	MergeSort(arr, start, mid, temp);
	//右半边
	MergeSort(arr, mid + 1, end,temp);
	//合并
	Merge(arr, start, end, mid, temp);
}

//待调整的节点
void HeapAdjust(int arr[], int index, int len)
{
	//先保存当前节点下标
	int max = index;
	int lchild = index * 2 + 1;
	int rchild = index * 2 + 2;
	if (lchild < len && arr[lchild] > arr[max])
	{
		max = lchild;
	}

	if (rchild < len && arr[rchild] > arr[max])
	{
		max = rchild;
	}

	if (max != index) {
		Swap(&arr[max],&arr[index]);
		HeapAdjust(arr, max,len);
	}
}

//堆
void HeapSort(int arr[], int len)
{
	//初始化堆
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		HeapAdjust(arr,i,len);
	}
	//交换堆顶和堆底
	for (int i = len - 1; i >= 0; i--)
	{
		Swap(&arr[0], &arr[i]);
		HeapAdjust(arr, 0, i);
	}
}

int main()
{
	int arr[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	cout << "冒泡" << endl;
	//排序前
	cout << "排序前" << endl;
	PrintArray(arr, MAX);
	BubbleSort(arr, MAX);
	//排序后
	cout << "排序后" << endl;
	PrintArray(arr, MAX);
	cout << "选择" << endl;
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	cout << "排序前" << endl;
	PrintArray(arr, MAX);
	SelectSort(arr, MAX);
	cout << "排序后" << endl;
	PrintArray(arr, MAX);

	cout << "插入" << endl;
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	cout << "排序前" << endl;
	PrintArray(arr, MAX);
	InsertSort(arr, MAX);
	cout << "排序后" << endl;
	PrintArray(arr, MAX);

	cout << "希尔" << endl;
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	cout << "排序前" << endl;
	PrintArray(arr, MAX);
	ShellSort(arr, MAX);
	cout << "排序后" << endl;
	PrintArray(arr, MAX);

	cout << "快速" << endl;
	int myArr[] = { 4,2,8,0,5,7,1,3,9 };
	cout << "排序前" << endl;
	PrintArray(myArr, 9);
	QuickSort(myArr, 0,8);
	cout << "排序后" << endl;
	PrintArray(myArr, 9);

	cout << "归并" << endl;
	int* myArr1 = CreateArray();
	cout << "排序前" << endl;
	PrintArray(myArr1, MAX);
	//辅助空间
	int* arrT = new int[MAX];
	MergeSort(myArr1, 0,MAX-1, arrT);
	cout << "排序后" << endl;
	PrintArray(myArr1, MAX);
	//释放
	delete [] myArr1;
	delete [] arrT;

	cout << "堆排序" << endl;
	cout << "排序前" << endl;
	int shuzu[] = { 4,2,8,0,5,7,1,3,9 };
	PrintArray(shuzu, 9);
	HeapSort(shuzu, 9);
	cout << "排序后" << endl;
	PrintArray(shuzu, 9);

	return 0;
}