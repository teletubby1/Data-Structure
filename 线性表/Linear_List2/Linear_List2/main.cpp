#include<iostream>
using namespace std;

typedef int ElementType; //ElementType���Ϳ��Ը���ʵ��������ı�

typedef struct LNode* List; //ListΪstruct LNode*����
struct LNode {
	ElementType Data; //����Ӧ������
	List Next; //������һ������
};
struct LNode L;
//List PtrL;

//ͷ�巨����������
List CreateListHead(int n)
{
	List p,PtrL;
	int i;
	srand(time(0)); //��ʼ�����������
	PtrL = (List)malloc(sizeof(LNode)); //�������Ա�
	PtrL->Next = NULL;
	for (i = 0; i < n; i++)
	{
		p= (List)malloc(sizeof(LNode)); //�����½��
		p->Data = rand() % 100 + 1; //�������100���ڵ�����
		p->Next = PtrL->Next; 
		PtrL->Next = p;
	}
	return PtrL;
}

//β�巨����������
List CreateListTail(int n)
{
	List p, r,PtrL;
	int i;
	srand(time(0)); //��ʼ�����������
	PtrL = (List)malloc(sizeof(LNode)); //�������Ա�
	r = PtrL; //rΪָ��β���Ľ��
	for (i = 0; i < n; i++)
	{
		p = (List)malloc(sizeof(LNode)); //�����½��
		p->Data = rand() % 100 + 1; //�������100���ڵ�����
		r->Next = p; //����β�ն˽���ָ��ָ���½ڵ�
		r=p; //����ǰ���½ڵ㶨��Ϊ��β�ն˽��
	}
	r->Next = NULL; //��ʾ��ǰ�������
	return PtrL;
}

//��ӡ����
void PrintOut(List PtrL)
{
	List p;
	p = PtrL->Next;
	while (p)
	{
		printf("%6d", p->Data);
		p = p->Next;
	}
	printf("\n");
}

//��ȡ������
int GetLength(List PtrL)
{
	List p = PtrL; //pָ���ĵ�һ�����
	int j = 0;
	while (p)
	{
		p = p->Next;
		j++;
	}
	return j;
}

//����Ų���
List FindKth(int K, List PtrL)
{
	List p = PtrL; //pָ��ͷ���
	int i = 0; //i��¼�����
	while (p != NULL && i < K) //������������
	{
		p=p->Next;
		i++;
	}
	if (i == K) return p; //�ҵ���K��������ָ�루��ַ����Ҫ��p->Data��������
	else return NULL; //���򷵻ؿ�
}

//��ֵ����
List Find(ElementType X, List PtrL)
{
	List p = PtrL;
	int cnt=0;
	while (p != NULL && p->Data != X) //��ͷ��ʼ��������
	{
		p = p->Next;
		cnt++;  //����������ֵ���ڵ�λ��
	}
	return p; //���ض�Ӧָ��
}

//�������
List Insert(ElementType X, int i, List PtrL)
{
	List p, s;
	if (i == 1)
	{
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = PtrL;
		return s;
	}
	p = FindKth(i - 1, PtrL);
	if (p == NULL)
	{
		printf("����i����");
		return NULL;
	}
	else
	{
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = p->Next;
		p->Next = s;
		return PtrL;
	}
}

//����ɾ��
List Delete(int i, List PtrL)
{
	List p, s;
	if (i == 1) //��Ҫɾ�����Ǳ�ĵ�һ����㣬��������
	{
		s = PtrL; //sָ���һ�����
		if (PtrL != NULL) PtrL = PtrL->Next; //��������ɾ��
		else return NULL;
		free(s); //�ͷű�ɾ���Ľ��
		return PtrL;
	}
	p = FindKth(i - 1, PtrL); //���ҵ�i-1�����
	if (p == NULL)
	{
		printf("��%d����㲻����", i - 1); return NULL;
	}
	else if (p->Next == NULL)
	{
		printf("��%d����㲻����", i); return NULL;
	}
	else
	{
		s = p->Next; //sָ���i�����
		p->Next = s->Next; //��������ɾ��
		free(s); //�ͷű�ɾ���Ľ��
		return PtrL;
	}
}

//����ɾ��
bool ClearList(List PtrL)
{
	List p, q;
	p = PtrL->Next; //pָ���һ�����
	while (p) //��p��û����βʱ
	{
		q = p->Next;
		free(p);
		p = q;
	}
	PtrL->Next = NULL; //ͷ���ָ����Ϊ��
	return true;
}

//��������
List Inverse(List L)
{
	List p, q;
	p = L->Next;     //pָ��ָ���һ�����
	L->Next = NULL;  //ͷ���ָ��NULL

	while (p != NULL) {
		q = p;
		p = p->Next;
		q->Next = L->Next;
		L->Next = q;
	}
	return L;
}

//����ϲ�
List Comb(List A, List B)
{
	List pa, pb, pc, C;
	pa = A->Next;
	pb = B->Next;
	C = A; pc = C; //Cʹ��ԭ������A��ͷ���
	while (pa && pb)
	{
		if (pa->Data <= pb->Data)
		{
			pc->Next = pa; pc = pa; pa = pa->Next;
		}
		else
		{
			pc->Next = pb; pc = pb; pb = pb->Next;
		}
	}
	if (pa) pc->Next = pa; //��A��ʣ���������ڱ�C֮��
	else pc->Next = pb; //��B��ʣ���������ڱ�C֮��

	free(B); //�ͷű�Bͷ���
	return (C); //����������Cͷ���
}



int main()
{
	List PtrL,s;
	PtrL=CreateListTail(7);
	int out = GetLength(PtrL);
	PrintOut(PtrL);
	cout <<"����ĳ���Ϊ��"<< out << endl;
	s = FindKth(2, PtrL);
	cout<<"����Ų��Ҷ���"<<s->Data<<endl;
	Insert(100, 2, PtrL);
	PrintOut(PtrL);
	Delete(3, PtrL);
	PrintOut(PtrL);
	Inverse(PtrL);
	PrintOut(PtrL);

	return 0;

}