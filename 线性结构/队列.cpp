#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//队列
//定义：
//     一种可以实现“先进先出”的数据结构
//分类：
//     链式队列 - 用链表实现
//     静态队列 - 用数组实现	
// 
//         静态队列必须是循环队列
//         1.静态队列为什么必须是循环队列
//           充分使用数组内存空间
//         2.循环队列需要几个参数来确定
//           需要两个参数Front、Rear，这两个参数不同场合不同含义
//         3.循环队列各个参数的含义
//           1）队列初始化 - front、rear都为0
//           2）队非空 - front代表的是队列的第一个元素，
//                       rear代表的是队列的最后一个有效元素的下一个元素
//           3）队列空 - front和rear的值相同，但不一定为0
//         4.循环队列入队、出队
//           入队：将值存入rear所代表的位置 -> r=（r+1）%数组的长度
//           出队：f=（f+1）%数组的长度
//         5.如何判断循环队列是否为空
//           front和rear的值相同
//         6.如何判断循环队列是否为满
//           两种方式
//           1）多增加一个标识参数
//           2）少用一个数组空间，若rear下一个是front，则队列已满（通常只用第二种）
//算法：
//     1.入队；2.出队
//具体应用：
//         所有和时间有关的操作都与队列有关



typedef struct Queue
{
	int* pBase;
	int front;
	int rear;
}QUEUE;

//函数声明
void init(QUEUE* pQ);
bool en_queue(QUEUE* pQ, int val);
bool out_queue(QUEUE* pQ, int* pVal);
void traverse_queue(QUEUE* pQ);
bool full_queue(QUEUE* pQ);
bool empty_queue(QUEUE* pQ);

void init(QUEUE* pQ)
{
	pQ->pBase = (int*)malloc(sizeof(int ) * 6);
	pQ->front = 0;
	pQ->rear = 0;
}

bool en_queue(QUEUE* pQ, int val)
{
	if (full_queue(pQ))
	{
		return false;
	}
	else
	{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear+1) % 6;

		return true;
	}
}

bool out_queue(QUEUE* pQ, int* pVal)
{
	if (empty_queue(pQ))
		return false;
	else
	{
		*pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front + 1) % 6;
		return true;
	}
}

bool full_queue(QUEUE* pQ)
{
	if ((pQ->rear + 1) % 6 == pQ->front)
		return true;
	else
		return false;
}

bool empty_queue(QUEUE* pQ)
{
	if (pQ->front == pQ->rear)
		return true;
	else
		return false;
}

void traverse_queue(QUEUE* pQ)
{
	int i = pQ->front;

	while (i != pQ->rear)
	{
		printf("%d ", pQ->pBase[i]);
		i = (i + 1) % 6;
	}
	printf("\n");

	return;
}

int main()
{
	QUEUE Q;
	int val;

	init(&Q);
	en_queue(&Q, 1);
	en_queue(&Q, 2);
	en_queue(&Q, 3);
	en_queue(&Q, 4);
	en_queue(&Q, 5);
	en_queue(&Q, 6);

	traverse_queue(&Q);

	if (out_queue(&Q, &val))
	{
		printf("出队成功，队列出队的元素是：%d\n", val);
	}
	else
	{
		printf("出队失败!\n");
	}

	traverse_queue(&Q);
	return 0;
}