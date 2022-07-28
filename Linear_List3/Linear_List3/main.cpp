#include<iostream>
using namespace std;

#define MAXSIZE 1000 //���農̬�������󳤶�Ϊ1000
typedef int ElementType; //ElementType���Ϳ��Ը���ʵ��������ı�

typedef struct
{
	ElementType data; //��ŵ�����
	int cur; //�α꣬Ϊ0ʱ��ʾ��ָ��
}Component,StaticLinkList[MAXSIZE];

void PrintOut(StaticLinkList L);

//��ʼ����̬����
void InitList(StaticLinkList space)
{
	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0; //Ŀǰ��̬����Ϊ�գ����һ��Ԫ�ص�curΪ0
}

//��ȡ����
int ListLength(StaticLinkList L)
{
	int j = 0; //������
	int i = L[MAXSIZE - 1].cur;
	while (i) //��i��=0
	{
		i = L[i].cur;
		j++;
	}
	return j;
}

//�������
int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur; //��ǰ�����һ��Ԫ�ص�cur���ֵ Ŀ���Ƿ��ص�һ�����ÿռ���±�
	if (space[0].cur)
		space[0].cur = space[i].cur; //����Ҫ�ó�һ������ʹ�ã�����Ҫ����һ�������ó�������
	return i; //�����±�ֵ�����ֵ������ͷԪ�ص�cur��ĵ�һ�����е��±�
}

//����
int ListInsert(StaticLinkList L, int i, ElementType e)
{
	int j, k, l;
	k = MAXSIZE - 1; //k�����һ��Ԫ�ص��±�
	if (i<1 || i>ListLength(L) + 1)
		return 0;
	j = Malloc_SLL(L); //��ȡ���з������±�
	if (j)
	{
		L[j].data = e; //�����ݸ�ֵ���η�����data
		for (l = 1; l <= i - 1; l++) //�ҵ���i��Ԫ��֮ǰ��λ��
			k = L[k].cur;
		L[j].cur = L[k].cur; //�ѵ�i��Ԫ��֮ǰ��cur��ֵ����Ԫ�ص�cur
		L[k].cur = j; //����Ԫ�ص��±긳ֵ����i��Ԫ��֮ǰԪ�ص�cur
		PrintOut(L);
		return 1;
	}
	return 0;
}

//����ͷ�
void Free_SSL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur; //�ѵ�һ��Ԫ�ص�curֵ������Ҫɾ���ķ���cur
	space[0].cur = k; //��Ҫɾ���ķ����±긳ֵ����һ��Ԫ�ص�cur
}

//ɾ��
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

//��ӡ
void PrintOut(StaticLinkList L)
{
	int i = L[MAXSIZE - 1].cur;
	while (i) //��i��=0
	{
		printf("%d,%d ", L[i].data,L[i].cur);
		i = L[i].cur;
	}
	printf("\n");
}

//����̬�������Ԫ��
void add(StaticLinkList L)
{
	printf("������������ӵ����ݳ�Ա��������");
	int n;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("�������%d�����ݳ�Ա��", i);
		scanf_s("%d", &L[i].data);
	}
	L[0].cur = n + 1;
	L[n].cur = 0;
	L[MAXSIZE - 1].cur = 1;
}
//�������в�������,add��ʾ����Ԫ�ص�λ�ã�num��ʾҪ���������

 

int main()
{
	StaticLinkList L;
	InitList(L);
	add(L);
	PrintOut(L);
	ListInsert(L, 1, 1);
	PrintOut(L);
}
