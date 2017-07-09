/****
 * 通过前序遍历和中序遍历得到二叉树*
 * */

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;


char preArray[]="ABDHECFG";
char midArray[] = "HDBEAFCG";

typedef struct BinaryTree BiTree;
struct BinaryTree
{
	char data;
	BiTree *LTree,*RTree;
};

void CreateBTree(BiTree **node,int mid_header,int mid_tail,int pre_header,int pre_tail)
{
	if(pre_header <= pre_tail || mid_header <= mid_tail)
	{
		BiTree* child;
		child =(BiTree*)malloc(sizeof(BiTree));
		child->data = preArray[pre_header];
		child->LTree = NULL;
		child->RTree = NULL;
		*node = child;
		int mid_num;
		for(mid_num = 0;preArray[pre_header]!=midArray[mid_num];mid_num++);//找到中序遍历中艮节点位置
		CreateBTree(&child->LTree,mid_header,mid_num-1,pre_header+1,pre_header+mid_num-mid_header);//创造左子树
		CreateBTree(&child->RTree,mid_num+1,mid_tail,pre_tail-mid_tail+mid_num+1,pre_tail);//创造右子树

	}
}

void ShowBTree(BiTree* p)
{
	if(p)
	{
		ShowBTree(p->LTree);
		ShowBTree(p->RTree);
		printf("%c",p->data);
	}
}
int main()
{
	BiTree* rootNode = NULL;
	rootNode = (BiTree*)malloc(sizeof(BiTree));
	rootNode->data = preArray[0];
	rootNode->LTree = NULL;
	rootNode->RTree = NULL;
	int mid_num = 0;
	for(mid_num = 0;preArray[0] !=midArray[mid_num];mid_num++);
	CreateBTree(&rootNode->LTree,0,mid_num-1,1,mid_num);
	CreateBTree(&rootNode->RTree,mid_num+1,strlen(midArray)-1,mid_num+1,strlen(preArray)-1);
	ShowBTree(rootNode);
	system("pause");
	return 0;
}
