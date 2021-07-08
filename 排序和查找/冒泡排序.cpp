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

//冒泡排序函数
void BubbleSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (a[j] > a[j+1])
			{
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
		print(a, n, i);
	}

}

int main()
{
	int a[9] = { 3,2,5,1,4,6,8,9,7 };

	BubbleSort(a, 9);
	return 0;
}