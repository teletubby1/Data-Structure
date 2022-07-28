#include<iostream>
using namespace std;

#define MAXSIZE 20 //存储空间初始分配量
typedef int ElementType; //ElementType类型可以根据实际情况作改变

typedef struct LNode* List;
struct LNode {
	ElementType Data[MAXSIZE]; //数组存储的数据元素数量，最大值为MAXSIZE
	int Last; //线性表最后一个元素的下标
};
struct LNode L;
List PtrL;

List MakeEmpty()
{
	List PtrL;
	PtrL = (List)malloc(sizeof(struct LNode)); //开辟空间
	PtrL->Last = -1; //建立空的顺序表
	return PtrL;
}

int Find(ElementType X, List PtrL)
{
	int i = 0;
	while (i <= PtrL->Last && PtrL->Data[i] != X)
	{
		i++;
	}
	if (i > PtrL->Last) return -1; //若没有找到，返回-1
	else return i; //找到后返回存储的位置
}

void Insert(ElementType X, int i, List PtrL)
{
	int j;
	if (PtrL->Last == MAXSIZE - 1)
	{
		printf("线性表已装满"); //验证表空间
		return;
	}
	if (i<1 || i>PtrL->Last + 2)
	{
		printf("位置不合法"); //检查插入位置合法性
		return;
	}
	for (j = PtrL->Last; j >= i - 1; j--)
	{
		PtrL->Data[j + 1] = PtrL->Data[j]; //将ai-an倒序向后移动
		PtrL->Data[i - 1] = X; //插入新元素
		PtrL->Last++; //Last仍指向最后元素
		return;
	}
}

void Delete(int i, List PtrL)
{
	int j;
	if (i<1 || i>PtrL->Last + 1)
	{
		printf("不存在第%d个元素",i);
		return;
	}
	for (j = i; j <= PtrL->Last; j++)
	{
		PtrL->Data[j - 1] = PtrL->Data[j]; //将ai-an顺序向前移动
		PtrL->Last--; //Last仍指向最后元素
	}
}