#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//定义了一个数据类型，类型名字叫struct Arr，该数据类型含有三个结构体成员
struct Arr
{
	int* pBase;//存储的是数组第一个元素的地址
	int len;//数组所能容纳的最大元素的个数
	int cnt;//当前数组有效元素的个数
	//int increment;//自动增长因子
};

void init_arr(struct Arr* pArr, int length);//初始化
bool append_arr(struct Arr* pArr, int val);//追加
bool insert_arr(struct Arr* pArr, int pos, int val);//插入, pos从1开始
bool delete_arr(struct Arr* pArr, int pos, int * pVal);//删除
int get();
bool is_empty(struct Arr* pArr);
bool is_full(struct Arr* pArr);
void sort_arr(struct Arr* pArr);
void show_arr(struct Arr* pArr);
void inversion_arr(struct Arr* pArr);

int main()
{
	struct Arr arr;
	int val;

	init_arr(&arr, 6);
	show_arr(&arr);

	append_arr(&arr, 1);
	append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4);
	append_arr(&arr, 5);
	insert_arr(&arr, 1, 99);
	if (delete_arr(&arr, 1, &val))
	{
		printf("删除成功！\n");
		printf("您删除的元素是：%d\n", val);
	}
	else
	{
		printf("删除失败！\n");
	}
	inversion_arr(&arr);
	sort_arr(&arr);
	show_arr(&arr);

	return 0;
}

void init_arr(struct Arr* pArr, int length)
{
	pArr->pBase = (int*)malloc(sizeof(int)*length);
	if (NULL == pArr->pBase)
	{
		printf("内存分配失败！\n");
		exit(-1);
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
}

bool append_arr(struct Arr* pArr, int val)
{
	// 满时返回false
	if (is_full(pArr))
		return false;
	
	// 不满时追加
	pArr->pBase[pArr->cnt] = val;
	(pArr->cnt)++;
	return true;
}

bool insert_arr(struct Arr* pArr, int pos, int val)
{
	if (is_full(pArr))
		return false;

	else if (pos < 1 || pos>pArr->cnt + 1)
		return false;

	int i = 0;
	for  (i = pArr->cnt-1; i >= pos-1 ; --i)
	{
		pArr->pBase[i+1] = pArr->pBase[i];
	}
	pArr->pBase[pos-1] = val;
	pArr->cnt++;

	return true;
}

bool delete_arr(struct Arr* pArr, int pos, int* pVal)
{
	if (is_empty(pArr))
		return false;
	if (pos <1 || pos > pArr->cnt)
		return false;
	*pVal = pArr->pBase[pos-1];
	int i = 0;
	for  (i = pos; i < pArr->cnt; ++i)
	{
		pArr->pBase[i - 1] = pArr->pBase[i];
	}
	pArr->cnt--;
	return true;
}

bool is_empty(struct Arr* pArr)
{
	if (0 == pArr->cnt)
		return true;
	else
		return false;
}

bool is_full(struct Arr* pArr)
{
	if (pArr->cnt == pArr->len)
		return true;
	else
		return false;
}

void sort_arr(struct Arr* pArr)
{
	int i = 0;
	int j = 0;
	int t = 0;

	for (i = 0; i < pArr->cnt; i++)
	{
		for (j = i+1; j < pArr->cnt; j++)
		{
			if (pArr->pBase[i] > pArr->pBase[j])
			{
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
}

void show_arr(struct Arr* pArr)
{
	if (is_empty(pArr))
		printf("数组为空！\n");
	else
	{
		int i = 0;
		for (i = 0; i < pArr->cnt; ++i)
			printf("%d ", pArr->pBase[i]);
		printf("\n");
	}
}

void inversion_arr(struct Arr* pArr)
{
	int i = 0;
	int j = pArr->cnt - 1;
	int t;

	while (i < j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		++i;
		--j;
	}
	return;
}