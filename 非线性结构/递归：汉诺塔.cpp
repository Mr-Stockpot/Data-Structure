#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//递归
//定义：
//     一个函数直接或间接调用自己
//必须满足的三个条件：
//     1.递归必须得有一个明确中止的条件
//     2.该函数所处理的数据规模必须在递减
//     3.这个转化必须是可解的
//循环和递归    
//     递归：
//          易于理解
//          速度慢
//          存储空间大
//     循环：
//          不易理解
//          速度快
//          存储空间不大 
//举例：
//     1.汉诺塔
//     2.走迷宫
//

//汉诺塔
void Hanoi(int n, char x, char y, char z)
{
	//如果是1个盘子
	//	直接将A柱子上的盘子从A移到C
	//否则
	//	先将A柱子上的n-1个盘子借助C移到B
	//	直接将A柱子上的第n个盘子从A移到C
	//	最后将B柱子上的n-1个盘子借助A移到C
	
	if (1 == n)
	{
		printf("将编号为%d的盘子从%c柱子移到%c柱子\n", n, x, z);
	}
	else
	{
		Hanoi(n-1, x, z, y);
		printf("将编号为%d的盘子从%c柱子移到%c柱子\n", n, x, z);
		Hanoi(n-1, y, x, z);
	}
}

int main()
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n = 0;

	printf("请输入要移动盘子个数：");
	scanf("%d", &n);

	Hanoi(n, 'A', 'B', 'C');
	return 0;
}
