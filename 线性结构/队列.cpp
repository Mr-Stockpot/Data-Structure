#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//����
//���壺
//     һ�ֿ���ʵ�֡��Ƚ��ȳ��������ݽṹ
//���ࣺ
//     ��ʽ���� - ������ʵ��
//     ��̬���� - ������ʵ��	
// 
//         ��̬���б�����ѭ������
//         1.��̬����Ϊʲô������ѭ������
//           ���ʹ�������ڴ�ռ�
//         2.ѭ��������Ҫ����������ȷ��
//           ��Ҫ��������Front��Rear��������������ͬ���ϲ�ͬ����
//         3.ѭ�����и��������ĺ���
//           1�����г�ʼ�� - front��rear��Ϊ0
//           2���ӷǿ� - front������Ƕ��еĵ�һ��Ԫ�أ�
//                       rear������Ƕ��е����һ����ЧԪ�ص���һ��Ԫ��
//           3�����п� - front��rear��ֵ��ͬ������һ��Ϊ0
//         4.ѭ��������ӡ�����
//           ��ӣ���ֵ����rear�������λ�� -> r=��r+1��%����ĳ���
//           ���ӣ�f=��f+1��%����ĳ���
//         5.����ж�ѭ�������Ƿ�Ϊ��
//           front��rear��ֵ��ͬ
//         6.����ж�ѭ�������Ƿ�Ϊ��
//           ���ַ�ʽ
//           1��������һ����ʶ����
//           2������һ������ռ䣬��rear��һ����front�������������ͨ��ֻ�õڶ��֣�
//�㷨��
//     1.��ӣ�2.����
//����Ӧ�ã�
//         ���к�ʱ���йصĲ�����������й�



typedef struct Queue
{
	int* pBase;
	int front;
	int rear;
}QUEUE;

//��������
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
		printf("���ӳɹ������г��ӵ�Ԫ���ǣ�%d\n", val);
	}
	else
	{
		printf("����ʧ��!\n");
	}

	traverse_queue(&Q);
	return 0;
}