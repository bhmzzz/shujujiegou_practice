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

//ð��
int flag = 0; //0 ��ʾû�������
void BubbleSort(int arr[],int length)
{
	for (int i = 0; i < length-1; i++)
	{
		flag = 1;//��ʾ�������
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
//ѡ��
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

//����
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

//ϣ��
void ShellSort(int arr[], int length)
{
	int increasement = length; //����
	int i, j,k;
	do {
		//ȷ�����������
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

//����
void QuickSort(int arr[],int start,int end)
{
	int i = start;
	int j = end;
	int temp = arr[start];//��׼��
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
		//����벿�ֽ��п�������
		QuickSort(arr,start,i-1);
		//���Ұ벿�ֽ��п���
		QuickSort(arr, i + 1, end);
	}
}
//�ϲ��㷨
void Merge(int arr[], int start, int end, int mid, int* temp)
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;

	//��ʾ�����ռ��ж���Ԫ��
	int length = 0;
	//�ϲ���������
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
	//i�������
	while (i_start <= i_end)
	{
		temp[length] = arr[i_start];
		i_start++;
		length++;
	}
	//j����
	while (j_start <= j_end)
	{
		temp[length] = arr[j_start];
		length++;
		j_start++;
	}

	//�����ռ��е����ݸ��ǵ�ԭ�ռ�
	for (int i = 0; i < length; i++)
	{
		arr[start + i] = temp[i];
	}
}

//�鲢
void MergeSort(int arr[],int start,int end,int* temp)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	//����
	//����
	MergeSort(arr, start, mid, temp);
	//�Ұ��
	MergeSort(arr, mid + 1, end,temp);
	//�ϲ�
	Merge(arr, start, end, mid, temp);
}

//�������Ľڵ�
void HeapAdjust(int arr[], int index, int len)
{
	//�ȱ��浱ǰ�ڵ��±�
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

//��
void HeapSort(int arr[], int len)
{
	//��ʼ����
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		HeapAdjust(arr,i,len);
	}
	//�����Ѷ��Ͷѵ�
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
	cout << "ð��" << endl;
	//����ǰ
	cout << "����ǰ" << endl;
	PrintArray(arr, MAX);
	BubbleSort(arr, MAX);
	//�����
	cout << "�����" << endl;
	PrintArray(arr, MAX);
	cout << "ѡ��" << endl;
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	cout << "����ǰ" << endl;
	PrintArray(arr, MAX);
	SelectSort(arr, MAX);
	cout << "�����" << endl;
	PrintArray(arr, MAX);

	cout << "����" << endl;
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	cout << "����ǰ" << endl;
	PrintArray(arr, MAX);
	InsertSort(arr, MAX);
	cout << "�����" << endl;
	PrintArray(arr, MAX);

	cout << "ϣ��" << endl;
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	cout << "����ǰ" << endl;
	PrintArray(arr, MAX);
	ShellSort(arr, MAX);
	cout << "�����" << endl;
	PrintArray(arr, MAX);

	cout << "����" << endl;
	int myArr[] = { 4,2,8,0,5,7,1,3,9 };
	cout << "����ǰ" << endl;
	PrintArray(myArr, 9);
	QuickSort(myArr, 0,8);
	cout << "�����" << endl;
	PrintArray(myArr, 9);

	cout << "�鲢" << endl;
	int* myArr1 = CreateArray();
	cout << "����ǰ" << endl;
	PrintArray(myArr1, MAX);
	//�����ռ�
	int* arrT = new int[MAX];
	MergeSort(myArr1, 0,MAX-1, arrT);
	cout << "�����" << endl;
	PrintArray(myArr1, MAX);
	//�ͷ�
	delete [] myArr1;
	delete [] arrT;

	cout << "������" << endl;
	cout << "����ǰ" << endl;
	int shuzu[] = { 4,2,8,0,5,7,1,3,9 };
	PrintArray(shuzu, 9);
	HeapSort(shuzu, 9);
	cout << "�����" << endl;
	PrintArray(shuzu, 9);

	return 0;
}