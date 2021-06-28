#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


//��ɢ���� - ����
//���壺n���ڵ���ɢ���䣬
//      �˴�ͨ��ָ��������
//      ÿ���ڵ�ֻ��һ��ǰ���ڵ㣬һ�������ڵ�
//      �׽ڵ�ûǰ����㣬β�ڵ�û�к������
 
//      רҵ����׽ڵ㣺��һ����Ч�ڵ�
//                β�ڵ㣺���һ����Ч�ڵ�
//                ͷ��㣺��һ����Ч�ڵ�֮ǰ���ĸ��ڵ�
//                        ͷ�ڵ㲢�������Ч����
//                        Ŀ����Ҫ��Ϊ�˷��������Ĳ���
//                ͷָ�룺ָ��ͷ����ָ�����
//                βָ�룺ָ��β�ڵ��ָ��
//      ȷ��һ��������Ҫ����������ֻ��ҪҪһ��ͷָ��
 
//���ࣺ
//     ������
//     ˫����ÿһ���ڵ�������ָ����
//     ѭ��������ͨ���κ�һ���ڵ��ҵ��������нڵ�
//     ��ѭ������
 
//�㷨��
//     ����
//     ����
//     ���
//     ����
//     �󳤶�
//     ����
//     ɾ���ڵ�
//     ����ڵ�

//��ȱ�㣺
//       �ռ�û������
//       ���롢ɾ��Ԫ�غܿ�
//       ��ȡ���ٶ���
//


typedef struct node
{
	int data; // ������ݱ��� - ������
	struct node* pNext; //ָ����
}NODE, *PNODE;

//��������
struct node* CreateList(void);
bool TraverseList(struct node* pH);
bool is_empty(struct node* pH);
int length_list(struct node* pH);
bool insert_list(struct node* pH, int pos, int val);
bool delete_list(struct node* pH, int pos, int* pVal);
void sort_list(struct node* pH);

struct node* CreateList(void)
{
	struct node* pH = NULL;
	int len; //��Ž��ĸ���
	int i;
	int temp; //����û���ʱ����Ľ���ֵ���ֵ
	struct node* pNew = NULL; //�����ʱ����õĽ�㱾�������
	struct node* pTail = NULL; //pTail��Զָ�������β�ڵ�

	//����һ��ͷ���
	pH = (struct node*)malloc(sizeof(struct node));
	if (NULL == pH)
	{
		puts("��̬�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	pH->pNext = NULL;
	pTail = pH;

	printf("��������ĸ�����len = ");
	scanf("%d", &len);
	for (i = 0; i < len; i++)
	{
		printf("�������%d������ֵ��", i+1);
		scanf("%d", &temp);

		//��ʱ����һ�����
		pNew = (struct node*)malloc(sizeof(struct node));
		if (NULL == pNew)
		{
			puts("��̬�ڴ����ʧ�ܣ�");
			exit(-1);
		}
			pNew->data = temp;
		pNew->pNext = NULL;

		//��pNew��ָ��Ľ��ҽӵ�pTail��ָ���ĩ���ĺ���
		pTail->pNext = pNew;
		pTail = pNew; //��pTail��Զָ��ĩ���
	}
	return pH;
}

bool TraverseList(struct node* pH)
{
	struct node* p = pH->pNext;

	while (NULL != p) //���pָ��Ľ�����
	{
		printf("%d ", p->data); //���p��ָ��Ľ���ֵ���ֵ
		p = p->pNext; //pָ��p����һ�����
	}
	printf("\n");

	return true;
}

bool is_empty(struct node* pH)
{
	if (NULL == pH->pNext)
		return true;
	else
		return false;
}

int length_list(struct node* pH)
{
	struct node* p = pH->pNext;
	int len = 0;
	while (NULL != p)
	{
		++len;
		p = p->pNext;
	}
	return len;
}

//��pH��ָ�������ĵ�pos���ڵ��ǰ�����һ���µĽڵ㣬�ýڵ��ֵΪval
bool insert_list(struct node* pH, int pos, int val)
{
	int i = 0;
	struct node* p = pH;

	while (NULL != p && i < pos -1)
	{
		p = p->pNext;
		++i;
	}
	if ((i > pos-1) || NULL == p)
		return false;

	struct node* pNew = (struct node*)malloc(sizeof(struct node));
	if (NULL == pNew)
	{
		puts("��̬�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	pNew->data = val;
	struct node* q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;

	return true;
}

bool delete_list(struct node* pH, int pos, int* pVal)
{
	int i = 0;
	struct node* p = pH;

	while (NULL != p->pNext && i < pos - 1)
	{
		p = p->pNext;
		++i;
	}
	if ((i > pos - 1) || NULL == p->pNext)
		return false;

	struct node* q = p->pNext;
	*pVal = q->data;
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;

	return true;
}

void sort_list(struct node* pH)
{
	int i = 0;
	int j = 0;
	int t = 0;
	int len = length_list(pH);
	struct node* p;
	struct node* q;
	for (i = 0, p = pH->pNext; i < len-1; i++, p = p->pNext)
	{
		for (j = i + 1, q = p->pNext; j < len; j++, q = q->pNext)
		{
			if (p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}

	}
	return;
}

int main(void)
{
	struct node* pH = NULL;
	int val;
	pH = CreateList(); //ͨ��CreateList()��������һ�����������������ͷ���ĵ�ַ����pH
	TraverseList(pH); //������������

	//if (is_empty(pH))
	//	printf("����Ϊ�գ�\n");
	//else
	//	printf("����Ϊ�գ�\n");

	int len = length_list(pH);
	printf("����ĳ����ǣ�%d\n", len);

	sort_list(pH);
	TraverseList(pH);

	insert_list(pH, 3, 5);
	TraverseList(pH);

	//if (delete_list(pH, 3, &val))
	//	printf("ɾ���ɹ���ɾ����Ԫ���ǣ�%d\n", val);
	//else
	//	printf("ɾ��ʧ�ܣ���ɾ����Ԫ�ز����ڣ�\n");
	//TraverseList(pH);

	return 0;
}