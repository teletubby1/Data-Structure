#include<iostream>
using namespace std;

typedef int ElemType; //ElementType���Ϳ��Ը���ʵ��������ı�

typedef struct LNode {
    ElemType data;
    struct LNode* next;
}DNode, * LinkList;

// ��ʼ��һ��ѭ��������
bool InitList(LinkList L) {
    L = (LNode*)malloc(sizeof(LNode)); //����һ��ͷ���
    if (L == NULL)             //�ڴ治�㣬����ʧ��
        return false;
    L->next = L;            //ͷ���nextָ��ָ��ͷ���
    return true;
}

//�ж�ѭ���������Ƿ�Ϊ�գ���ֹ����Ϊp��p->next�Ƿ����ͷָ�룩
bool Empty(LinkList L) {
    if (L->next == L)
        return true;    //Ϊ��
    else
        return false;
}

//�жϽ��p�Ƿ�Ϊѭ��������ı�β���
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

//��ʼ���յ�ѭ��˫����
bool InitDLinkList(DLinklist& L) {
    L = (DNode*)malloc(sizeof(DNode));    //����һ��ͷ���
    if (L == NULL)            //�ڴ治�㣬����ʧ��
        return false;
    L->prior = L;          //ͷ����priorָ��ͷ���
    L->next = L;           //ͷ����nextָ��ͷ���
}

void testDLinkList() {
    //��ʼ��ѭ��������
    DLinklist L;
    InitDLinkList(L);
    //...
}

//�ж�ѭ��˫�����Ƿ�Ϊ��
bool Empty(DLinklist L) {
    if (L->next == L)
        return true;
    else
        return false;
}

//�жϽ��p�Ƿ�Ϊѭ��˫����ı�β���
bool isTail(DLinklist L, DNode* p) {
    if (p->next == L)
        return true;
    else
        return false;
}


