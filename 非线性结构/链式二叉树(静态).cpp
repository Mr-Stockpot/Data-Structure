#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>

struct BTNode
{
	int data;
	struct BTNode * pLchild;//×óÖ¸Õë
	struct BTNode * pRchild;//ÓÒÖ¸Õë
};

struct BTNode* CreateBTree()
{
	struct BTNode* pA = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pB = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pC = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pD = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode* pE = (struct BTNode*)malloc(sizeof(struct BTNode));

	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';

	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = pE->pRchild = NULL;

	return pA;
}

void PreTraverseBTree(struct BTNode* pT)
{
	if (pT != NULL)
	{
		printf("%c\n", pT->data);

		if(NULL != pT->pLchild)
			PreTraverseBTree(pT->pLchild);
		if (NULL != pT->pRchild)
			PreTraverseBTree(pT->pRchild);
	}
}

void InTraverseBTree(struct BTNode* pT)
{
	if (pT != NULL)
	{
		if (NULL != pT->pLchild)
			InTraverseBTree(pT->pLchild);

		printf("%c\n", pT->data);

		if (NULL != pT->pRchild)
			InTraverseBTree(pT->pRchild);
	}
}

void PostTraverseBTree(struct BTNode* pT)
{
	if (pT != NULL)
	{
		if (NULL != pT->pLchild)
			PostTraverseBTree(pT->pLchild);
		if (NULL != pT->pRchild)
			PostTraverseBTree(pT->pRchild);

		printf("%c\n", pT->data);
	}
}

int main()
{
	struct BTNode* pT = CreateBTree();

	PreTraverseBTree(pT);
	printf("\n");
	InTraverseBTree(pT);
	printf("\n");
	PostTraverseBTree(pT);
	printf("\n");

	return 0;
}