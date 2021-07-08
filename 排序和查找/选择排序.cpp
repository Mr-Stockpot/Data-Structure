#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//自定义输出函数
void print(int a[], int n, int i)
{
	printf("%d:", i);
	for (int j = 0; j < 9; j++)
	{
		printf("%d ", a[j]);
	}
	printf("\n");
}

//选择排序函数
void SelectionSort(int a[], int n)
{
	for ( int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
		print(a, n, i+1);
	}
}

int main()
{
	int a[9] = {3,2,5,1,4,6,8,7,9};

	SelectionSort(a, 9);
	return 0;
}