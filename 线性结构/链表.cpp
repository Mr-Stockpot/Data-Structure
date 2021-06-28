#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


//离散储存 - 链表
//定义：n个节点离散分配，
//      彼此通过指针相连，
//      每个节点只有一个前驱节点，一个后续节点
//      首节点没前驱结点，尾节点没有后续结点
 
//      专业术语：首节点：第一个有效节点
//                尾节点：最后一个有效节点
//                头结点：第一个有效节点之前的哪个节点
//                        头节点并不存放有效数据
//                        目的主要是为了方便对链表的操作
//                头指针：指向头结点的指针变量
//                尾指针：指向尾节点的指针
//      确定一个链表需要几个参数：只需要要一个头指针
 
//分类：
//     单链表
//     双链表：每一个节点有两个指针域
//     循环链表：能通过任何一个节点找到其他所有节点
//     非循环链表
 
//算法：
//     遍历
//     查找
//     清空
//     销毁
//     求长度
//     排序
//     删除节点
//     插入节点

//优缺点：
//       空间没有限制
//       插入、删除元素很快
//       存取的速度慢
//


typedef struct node
{
	int data; // 存放数据本身 - 数据域
	struct node* pNext; //指针域
}NODE, *PNODE;

//函数声明
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
	int len; //存放结点的个数
	int i;
	int temp; //存放用户暂时存入的结点的值域的值
	struct node* pNew = NULL; //存放临时分配好的结点本身的内容
	struct node* pTail = NULL; //pTail永远指向链表的尾节点

	//创建一个头结点
	pH = (struct node*)malloc(sizeof(struct node));
	if (NULL == pH)
	{
		puts("动态内存分配失败！");
		exit(-1);
	}
	pH->pNext = NULL;
	pTail = pH;

	printf("请输入结点的个数：len = ");
	scanf("%d", &len);
	for (i = 0; i < len; i++)
	{
		printf("请输入第%d个结点的值：", i+1);
		scanf("%d", &temp);

		//临时构造一个结点
		pNew = (struct node*)malloc(sizeof(struct node));
		if (NULL == pNew)
		{
			puts("动态内存分配失败！");
			exit(-1);
		}
			pNew->data = temp;
		pNew->pNext = NULL;

		//将pNew所指向的结点挂接到pTail所指向的末结点的后面
		pTail->pNext = pNew;
		pTail = pNew; //令pTail永远指向末结点
	}
	return pH;
}

bool TraverseList(struct node* pH)
{
	struct node* p = pH->pNext;

	while (NULL != p) //如果p指向的结点存在
	{
		printf("%d ", p->data); //输出p所指向的结点的值域的值
		p = p->pNext; //p指向p的下一个结点
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

//在pH所指向的链表的第pos个节点的前面插入一个新的节点，该节点的值为val
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
		puts("动态内存分配失败！");
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
	pH = CreateList(); //通过CreateList()函数创建一个链表，并将该链表的头结点的地址赋给pH
	TraverseList(pH); //遍历整个链表

	//if (is_empty(pH))
	//	printf("链表为空！\n");
	//else
	//	printf("链表不为空！\n");

	int len = length_list(pH);
	printf("链表的长度是：%d\n", len);

	sort_list(pH);
	TraverseList(pH);

	insert_list(pH, 3, 5);
	TraverseList(pH);

	//if (delete_list(pH, 3, &val))
	//	printf("删除成功！删除的元素是：%d\n", val);
	//else
	//	printf("删除失败！您删除的元素不存在！\n");
	//TraverseList(pH);

	return 0;
}