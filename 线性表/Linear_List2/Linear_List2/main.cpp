#include<iostream>
using namespace std;

typedef int ElementType; //ElementType类型可以根据实际情况作改变

typedef struct LNode* List; //List为struct LNode*别名
struct LNode {
	ElementType Data; //结点对应的数据
	List Next; //结点的下一个数据
};
struct LNode L;
//List PtrL;

//头插法创建单链表
List CreateListHead(int n)
{
	List p,PtrL;
	int i;
	srand(time(0)); //初始化随机数种子
	PtrL = (List)malloc(sizeof(LNode)); //整个线性表
	PtrL->Next = NULL;
	for (i = 0; i < n; i++)
	{
		p= (List)malloc(sizeof(LNode)); //生成新结点
		p->Data = rand() % 100 + 1; //随机生成100以内的数字
		p->Next = PtrL->Next; 
		PtrL->Next = p;
	}
	return PtrL;
}

//尾插法创建单链表
List CreateListTail(int n)
{
	List p, r,PtrL;
	int i;
	srand(time(0)); //初始化随机数种子
	PtrL = (List)malloc(sizeof(LNode)); //整个线性表
	r = PtrL; //r为指向尾部的结点
	for (i = 0; i < n; i++)
	{
		p = (List)malloc(sizeof(LNode)); //生成新结点
		p->Data = rand() % 100 + 1; //随机生成100以内的数字
		r->Next = p; //将表尾终端结点的指针指向新节点
		r=p; //将当前的新节点定义为表尾终端结点
	}
	r->Next = NULL; //表示当前链表结束
	return PtrL;
}

//打印链表
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

//获取链表长度
int GetLength(List PtrL)
{
	List p = PtrL; //p指向表的第一个结点
	int j = 0;
	while (p)
	{
		p = p->Next;
		j++;
	}
	return j;
}

//按序号查找
List FindKth(int K, List PtrL)
{
	List p = PtrL; //p指向头结点
	int i = 0; //i记录其序号
	while (p != NULL && i < K) //结束查找条件
	{
		p=p->Next;
		i++;
	}
	if (i == K) return p; //找到第K个，返回指针（地址），要用p->Data访问数据
	else return NULL; //否则返回空
}

//按值查找
List Find(ElementType X, List PtrL)
{
	List p = PtrL;
	int cnt=0;
	while (p != NULL && p->Data != X) //从头开始遍历链表
	{
		p = p->Next;
		cnt++;  //可用作返回值所在的位序
	}
	return p; //返回对应指针
}

//链表插入
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
		printf("参数i错误");
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

//链表删除
List Delete(int i, List PtrL)
{
	List p, s;
	if (i == 1) //若要删除的是表的第一个结点，单独讨论
	{
		s = PtrL; //s指向第一个结点
		if (PtrL != NULL) PtrL = PtrL->Next; //从链表中删除
		else return NULL;
		free(s); //释放被删除的结点
		return PtrL;
	}
	p = FindKth(i - 1, PtrL); //查找第i-1个结点
	if (p == NULL)
	{
		printf("第%d个结点不存在", i - 1); return NULL;
	}
	else if (p->Next == NULL)
	{
		printf("第%d个结点不存在", i); return NULL;
	}
	else
	{
		s = p->Next; //s指向第i个结点
		p->Next = s->Next; //从链表中删除
		free(s); //释放被删除的结点
		return PtrL;
	}
}

//整表删除
bool ClearList(List PtrL)
{
	List p, q;
	p = PtrL->Next; //p指向第一个结点
	while (p) //当p还没到表尾时
	{
		q = p->Next;
		free(p);
		p = q;
	}
	PtrL->Next = NULL; //头结点指针域为空
	return true;
}

//链表逆置
List Inverse(List L)
{
	List p, q;
	p = L->Next;     //p指针指向第一个结点
	L->Next = NULL;  //头结点指向NULL

	while (p != NULL) {
		q = p;
		p = p->Next;
		q->Next = L->Next;
		L->Next = q;
	}
	return L;
}

//链表合并
List Comb(List A, List B)
{
	List pa, pb, pc, C;
	pa = A->Next;
	pb = B->Next;
	C = A; pc = C; //C使用原单链表A的头结点
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
	if (pa) pc->Next = pa; //表A中剩余结点链接在表C之后
	else pc->Next = pb; //表B中剩余结点链接在表C之后

	free(B); //释放表B头结点
	return (C); //返回新链表C头结点
}



int main()
{
	List PtrL,s;
	PtrL=CreateListTail(7);
	int out = GetLength(PtrL);
	PrintOut(PtrL);
	cout <<"链表的长度为："<< out << endl;
	s = FindKth(2, PtrL);
	cout<<"按序号查找二号"<<s->Data<<endl;
	Insert(100, 2, PtrL);
	PrintOut(PtrL);
	Delete(3, PtrL);
	PrintOut(PtrL);
	Inverse(PtrL);
	PrintOut(PtrL);

	return 0;

}