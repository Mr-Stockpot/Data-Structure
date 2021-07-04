#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int FindPos(int * a, int low, int high)
{
	int val = a[low];

	while (low < high)
	{
		while (low < high && a[high] >= val)
			--high;
		a[low] = a[high];

		while (low < high && a[low] <= val)
			++low;
		a[high] = a[low];
	}
	a[low] = val;

	return high;
}

void QuickSort(int * a, int low, int high)
{
	int pos;

	if (low < high)
	{
		pos = FindPos(a, low, high);
		QuickSort(a, low, pos-1);
		QuickSort(a, pos+1, high);
	}
}

int main()
{
	int a[6] = {2,1,0,5,4,3};
	int i = 0;

	QuickSort(a, 0, 5);//第二个参数表示第一个元素的下标，第三个参数表示最后一个元素的下标

	for (i = 0; i < 6; ++i)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}