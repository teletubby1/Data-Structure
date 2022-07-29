#include<iostream>
using namespace std;

#define MAXSIZE 20 //�洢�ռ��ʼ������
typedef int ElementType; //ElementType���Ϳ��Ը���ʵ��������ı�

typedef struct LNode* List;
struct LNode {
	ElementType Data[MAXSIZE]; //����洢������Ԫ�����������ֵΪMAXSIZE
	int Last; //���Ա����һ��Ԫ�ص��±�
};
struct LNode L;
List PtrL;

List MakeEmpty()
{
	List PtrL;
	PtrL = (List)malloc(sizeof(struct LNode)); //���ٿռ�
	PtrL->Last = -1; //�����յ�˳���
	return PtrL;
}

int Find(ElementType X, List PtrL)
{
	int i = 0;
	while (i <= PtrL->Last && PtrL->Data[i] != X)
	{
		i++;
	}
	if (i > PtrL->Last) return -1; //��û���ҵ�������-1
	else return i; //�ҵ��󷵻ش洢��λ��
}

void Insert(ElementType X, int i, List PtrL)
{
	int j;
	if (PtrL->Last == MAXSIZE - 1)
	{
		printf("���Ա���װ��"); //��֤��ռ�
		return;
	}
	if (i<1 || i>PtrL->Last + 2)
	{
		printf("λ�ò��Ϸ�"); //������λ�úϷ���
		return;
	}
	for (j = PtrL->Last; j >= i - 1; j--)
	{
		PtrL->Data[j + 1] = PtrL->Data[j]; //��ai-an��������ƶ�
		PtrL->Data[i - 1] = X; //������Ԫ��
		PtrL->Last++; //Last��ָ�����Ԫ��
		return;
	}
}

void Delete(int i, List PtrL)
{
	int j;
	if (i<1 || i>PtrL->Last + 1)
	{
		printf("�����ڵ�%d��Ԫ��",i);
		return;
	}
	for (j = i; j <= PtrL->Last; j++)
	{
		PtrL->Data[j - 1] = PtrL->Data[j]; //��ai-an˳����ǰ�ƶ�
		PtrL->Last--; //Last��ָ�����Ԫ��
	}
}