#include<iostream>
using namespace std;

typedef int ElemType; //ElementType类型可以根据实际情况作改变

typedef struct LNode {
    ElemType data;
    struct LNode* next;
}DNode, * LinkList;

// 初始化一个循环单链表
bool InitList(LinkList L) {
    L = (LNode*)malloc(sizeof(LNode)); //分配一个头结点
    if (L == NULL)             //内存不足，分配失败
        return false;
    L->next = L;            //头结点next指针指向头结点
    return true;
}

//判断循环单链表是否为空（终止条件为p或p->next是否等于头指针）
bool Empty(LinkList L) {
    if (L->next == L)
        return true;    //为空
    else
        return false;
}

//判断结点p是否为循环单链表的表尾结点
bool isTail(LinkList L, LNode* p) {
    if (p->next == L)
        return true;
    else
        return false;
}

typedef struct DNode {
    ElemType data;
    struct DNode* prior, * next;
}DNode, * DLinklist;

//初始化空的循环双链表
bool InitDLinkList(DLinklist& L) {
    L = (DNode*)malloc(sizeof(DNode));    //分配一个头结点
    if (L == NULL)            //内存不足，分配失败
        return false;
    L->prior = L;          //头结点的prior指向头结点
    L->next = L;           //头结点的next指向头结点
}

void testDLinkList() {
    //初始化循环单链表
    DLinklist L;
    InitDLinkList(L);
    //...
}

//判断循环双链表是否为空
bool Empty(DLinklist L) {
    if (L->next == L)
        return true;
    else
        return false;
}

//判断结点p是否为循环双链表的表尾结点
bool isTail(DLinklist L, DNode* p) {
    if (p->next == L)
        return true;
    else
        return false;
}


