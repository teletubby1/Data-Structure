#include<iostream>
using namespace std;

#define MAXSIZE 1000 //假设静态链表的最大长度为1000
typedef int ElemType; //ElementType类型可以根据实际情况作改变

typedef struct DNode {            //定义双链表结点类型
    ElemType data;               //数据域
    struct DNode* prior, * next;  //前驱和后继指针
}DNode, * DLinklist;

//初始化双链表
bool InitDLinkList(DLinklist L) 
{
    L = (DNode*)malloc(sizeof(DNode));      //分配一个头结点
    if (L == NULL)                              //内存不足，分配失败
        return false;

    L->prior = NULL;   //头结点的prior指针永远指向NULL
    L->next = NULL;    //头结点之后暂时还没有结点
    return true;
}

void testDLinkList() {
    //初始化双链表
    DLinklist L;         // 定义指向头结点的指针L
    InitDLinkList(L);    //申请一片空间用于存放头结点，指针L指向这个头结点
    //...
}

//判断双链表是否为空
bool Empty(DLinklist L) {
    if (L->next == NULL)    //判断头结点的next指针是否为空
        return true;
    else
        return false;
}

//插入
bool InsertNextDNode(DNode* p, DNode* s) { //将结点 *s 插入到结点 *p之后
    if (p == NULL || s == NULL) //非法参数
        return false;

    s->next = p->next;
    if (p->next != NULL)   //p不是最后一个结点=p有后继结点  
        p->next->prior = s;
    s->prior = p;
    p->next = s;

    return true;
}

//删除p结点的后继结点
bool DeletNextDNode(DNode* p) {
    if (p == NULL) return false;
    DNode* q = p->next;            //找到p的后继结点q
    if (q == NULL) return false;     //p没有后继结点;
    p->next = q->next;
    if (q->next != NULL)           //q结点不是最后一个结点
        q->next->prior = p;
    free(q);

    return true;
}

//销毁一个双链表
bool DestoryList(DLinklist& L) {
    //循环释放各个数据结点
    while (L->next != NULL) {
        DeletNextDNode(L);  //删除头结点的后继结点
        free(L); //释放头结点
        L = NULL;  //头指针指向NULL

    }
}



