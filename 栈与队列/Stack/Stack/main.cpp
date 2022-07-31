#include<iostream>
using namespace std;

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status; //Status 为函数类型，表示函数状态
typedef int SElemType; //SElemType类型根据实际情况而定，这里假设为int

typedef struct
{
	SElemType data[MAXSIZE];
	int top; //用于栈顶指针
}SqStack;

//初始化栈
Status InitStack(SqStack* S) {
	S->top = -1; //初始化栈顶指针
	return OK;
}

//进栈
Status Push(SqStack *S, SElemType e)
{
	if (S->top == MAXSIZE - 1) //栈已满
	{
		return ERROR;
	}
	S->top++; //栈顶指针加一
	S ->data[S->top] = e; //将新元素赋值给栈顶空间
	return OK;
}

//出栈
Status Pop(SqStack* S, SElemType* e)
{
	if (S->top == -1) //判断栈是否为空
		return ERROR;
	*e = S->data[S->top];
	S->top--;
	return OK;
}

//输出栈中元素
Status visit(SElemType c)
{
	printf("%d ", c);
	return OK;
}

//从栈底到栈顶依次对栈中每个元素显示
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

//清空栈
Status ClearStack(SqStack* S)
{
	S->top = -1;
	return OK;
}

//获得栈顶元素
Status GetTop(SqStack *S, SElemType* e)
{
	if (S->top == -1)
		return ERROR;
	else
		*e = S->data[S->top];
	return OK;
}
//获取栈的长度
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