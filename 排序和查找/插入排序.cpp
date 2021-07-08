#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//自定义输出函数
void print(int a[], int n, int i)
{
	printf("%d:", i);
	for (int j = 0; j < 8; j++)
	{
		printf("%d ", a[j]);
	}
	printf("\n");
}

//插入排序函数 - 升序
void InsertSort(int a[], int n)
{

	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i-1])//若第i个元素大于i-1元素则直接插入；反之需要找到适当的插入位置后插入
		{
			int j = i - 1;
			int x = a[i];
			while (j>-1 && x<a[j])//采用顺序查找方式找到插入的位置，在查找的同时，将数组中的元素进行后移操作，给插入元素腾出空间
			{
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = x;//插入到正确位置
		}
		print(a, n, i);
	}
}

int main()
{
	int a[8] = {3,1,7,5,2,4,9,6};
	InsertSort(a, 8);
	return 0;
}