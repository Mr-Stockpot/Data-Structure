#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//栈
//定义：
//     一种可以实现“先进后出”的存储结构
//     栈类似于箱子
//分类：
//     静态栈
//     动态栈
//算法：
//     出栈
//     压栈
//应用：
//     函数调用
//     中断
//     表达式求值
//     内存分配
//     缓冲处理
//     迷宫


typedef struct Node 
{
	int data;
	struct Node* pNext;
}NODE, * PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK, * PSTACK;

//函数声明
void init(PSTACK pS);
void push(PSTACK pS, int val);
void traverse(PSTACK pS);
bool pop(PSTACK pS, int * pVal);

void init(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pTop)
	{
		printf("内存分配失败！\n");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL;
	}
	return;
}

void push(PSTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = pS->pTop;//pTop不能改成pBottom
	pS->pTop = pNew;
	return;
}

bool empty(PSTACK pS)
{
	if (pS->pTop == pS->pBottom)
		return true;
	else
		return false;
}

bool pop(PSTACK pS, int * pVal)
{
	if (empty(pS))
	{
		return false;
	}
	else
	{
		PNODE p = pS->pTop;
		*pVal = p->data;
		pS->pTop = pS->pTop->pNext;
		free(p);
		p = NULL;
	}
	return true;
}

void traverse(PSTACK pS)
{
	PNODE p = pS->pTop;

	while (p != pS->pBottom)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}

void clear(PSTACK pS)
{
	if (empty(pS))
		return;
	else
	{
		PNODE p = pS->pTop;
		PNODE q = NULL;

		while (p != pS->pBottom)
		{

			q = p->pNext;
			free(p);
			p = q;
		}
	}
	pS->pTop = pS->pBottom;
	return;
}

int main()
{
	STACK S;  //等价于struct Stack
	int val;

	init(&S);
	push(&S, 1);
	push(&S, 2);
	push(&S, 3);
	push(&S, 4);
	push(&S, 5);
	push(&S, 6);

	if (pop(&S, &val))
	{
		printf("出栈成功，出栈的元素是%d\n", val);
	}
	else
	{
		printf("出栈失败！\n");
	}
	traverse(&S);

	clear(&S);
	traverse(&S);

	return 0;
}