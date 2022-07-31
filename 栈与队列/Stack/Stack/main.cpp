#include<iostream>
using namespace std;

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status; //Status Ϊ�������ͣ���ʾ����״̬
typedef int SElemType; //SElemType���͸���ʵ������������������Ϊint

typedef struct
{
	SElemType data[MAXSIZE];
	int top; //����ջ��ָ��
}SqStack;

//��ʼ��ջ
Status InitStack(SqStack* S) {
	S->top = -1; //��ʼ��ջ��ָ��
	return OK;
}

//��ջ
Status Push(SqStack *S, SElemType e)
{
	if (S->top == MAXSIZE - 1) //ջ����
	{
		return ERROR;
	}
	S->top++; //ջ��ָ���һ
	S ->data[S->top] = e; //����Ԫ�ظ�ֵ��ջ���ռ�
	return OK;
}

//��ջ
Status Pop(SqStack* S, SElemType* e)
{
	if (S->top == -1) //�ж�ջ�Ƿ�Ϊ��
		return ERROR;
	*e = S->data[S->top];
	S->top--;
	return OK;
}

//���ջ��Ԫ��
Status visit(SElemType c)
{
	printf("%d ", c);
	return OK;
}

//��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ����ʾ
Status StackTraverse(SqStack* S)
{
	int i;
	i = 0;
	while (i <= S->top)
	{
		visit(S->data[i++]);
	}
	printf("\n");
	return OK;
}

//���ջ
Status ClearStack(SqStack* S)
{
	S->top = -1;
	return OK;
}

//���ջ��Ԫ��
Status GetTop(SqStack *S, SElemType* e)
{
	if (S->top == -1)
		return ERROR;
	else
		*e = S->data[S->top];
	return OK;
}
//��ȡջ�ĳ���
int StackLength(SqStack *S)
{
	return S->top + 1;
}

int main()
{
	SqStack *S;
	S = (SqStack*)malloc(MAXSIZE * sizeof(SqStack));
	InitStack(S);
	Push(S,3);
	Push(S, 2);
	StackTraverse(S);
	cout<<StackLength(S);

}