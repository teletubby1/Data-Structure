#include<iostream>
using namespace std;

#define MAXSIZE 1000 //假设静态链表的最大长度为1000
typedef int ElementType; //ElementType类型可以根据实际情况作改变

typedef struct
{
	ElementType data; //存放的数据
	int cur; //游标，为0时表示无指向
}Component,StaticLinkList[MAXSIZE];

void PrintOut(StaticLinkList L);

//初始化静态链表
void InitList(StaticLinkList space)
{
	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0; //目前静态链表为空，最后一个元素的cur为0
}

//获取长度
int ListLength(StaticLinkList L)
{
	int j = 0; //计数器
	int i = L[MAXSIZE - 1].cur;
	while (i) //当i！=0
	{
		i = L[i].cur;
		j++;
	}
	return j;
}

//结点申请
int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur; //当前数组第一个元素的cur存的值 目的是返回第一个备用空间的下标
	if (space[0].cur)
		space[0].cur = space[i].cur; //由于要拿出一个分量使用，所以要把下一个分量拿出来备用
	return i; //返回下标值，这个值是数组头元素的cur存的第一个空闲的下标
}

//插入
int ListInsert(StaticLinkList L, int i, ElementType e)
{
	int j, k, l;
	k = MAXSIZE - 1; //k是最后一个元素的下标
	if (i<1 || i>ListLength(L) + 1)
		return 0;
	j = Malloc_SLL(L); //获取空闲分量的下标
	if (j)
	{
		L[j].data = e; //将数据赋值给次分量的data
		for (l = 1; l <= i - 1; l++) //找到第i个元素之前的位置
			k = L[k].cur;
		L[j].cur = L[k].cur; //把第i个元素之前的cur赋值给新元素的cur
		L[k].cur = j; //把新元素的下标赋值给第i个元素之前元素的cur
		PrintOut(L);
		return 1;
	}
	return 0;
}

//结点释放
void Free_SSL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur; //把第一个元素的cur值赋给将要删除的分量cur
	space[0].cur = k; //把要删除的分量下标赋值给第一个元素的cur
}

//删除
int ListDelete(StaticLinkList L, int i)
{
	int j, k;
	if (i<1 || i>ListLength(L))
		return 0;
	k = MAXSIZE - 1;
	for (j = 1; j <= i - 1; j++)
		k = L[k].cur;
	j = L[k].cur;
	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SSL(L, j);
	return 1;
}

//打印
void PrintOut(StaticLinkList L)
{
	int i = L[MAXSIZE - 1].cur;
	while (i) //当i！=0
	{
		printf("%d,%d ", L[i].data,L[i].cur);
		i = L[i].cur;
	}
	printf("\n");
}

//给静态链表加入元素
void add(StaticLinkList L)
{
	printf("请输入你想添加的数据成员的数量：");
	int n;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("请输入第%d个数据成员：", i);
		scanf_s("%d", &L[i].data);
	}
	L[0].cur = n + 1;
	L[n].cur = 0;
	L[MAXSIZE - 1].cur = 1;
}
//向链表中插入数据,add表示插入元素的位置，num表示要插入的数据

 

int main()
{
	StaticLinkList L;
	InitList(L);
	add(L);
	PrintOut(L);
	ListInsert(L, 1, 1);
	PrintOut(L);
}
