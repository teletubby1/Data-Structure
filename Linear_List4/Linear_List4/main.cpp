#include<iostream>
using namespace std;

#define MAXSIZE 1000 //���農̬�������󳤶�Ϊ1000
typedef int ElemType; //ElementType���Ϳ��Ը���ʵ��������ı�

typedef struct DNode {            //����˫����������
    ElemType data;               //������
    struct DNode* prior, * next;  //ǰ���ͺ��ָ��
}DNode, * DLinklist;

//��ʼ��˫����
bool InitDLinkList(DLinklist L) 
{
    L = (DNode*)malloc(sizeof(DNode));      //����һ��ͷ���
    if (L == NULL)                              //�ڴ治�㣬����ʧ��
        return false;

    L->prior = NULL;   //ͷ����priorָ����Զָ��NULL
    L->next = NULL;    //ͷ���֮����ʱ��û�н��
    return true;
}

void testDLinkList() {
    //��ʼ��˫����
    DLinklist L;         // ����ָ��ͷ����ָ��L
    InitDLinkList(L);    //����һƬ�ռ����ڴ��ͷ��㣬ָ��Lָ�����ͷ���
    //...
}

//�ж�˫�����Ƿ�Ϊ��
bool Empty(DLinklist L) {
    if (L->next == NULL)    //�ж�ͷ����nextָ���Ƿ�Ϊ��
        return true;
    else
        return false;
}

//����
bool InsertNextDNode(DNode* p, DNode* s) { //����� *s ���뵽��� *p֮��
    if (p == NULL || s == NULL) //�Ƿ�����
        return false;

    s->next = p->next;
    if (p->next != NULL)   //p�������һ�����=p�к�̽��  
        p->next->prior = s;
    s->prior = p;
    p->next = s;

    return true;
}

//ɾ��p���ĺ�̽��
bool DeletNextDNode(DNode* p) {
    if (p == NULL) return false;
    DNode* q = p->next;            //�ҵ�p�ĺ�̽��q
    if (q == NULL) return false;     //pû�к�̽��;
    p->next = q->next;
    if (q->next != NULL)           //q��㲻�����һ�����
        q->next->prior = p;
    free(q);

    return true;
}

//����һ��˫����
bool DestoryList(DLinklist& L) {
    //ѭ���ͷŸ������ݽ��
    while (L->next != NULL) {
        DeletNextDNode(L);  //ɾ��ͷ���ĺ�̽��
        free(L); //�ͷ�ͷ���
        L = NULL;  //ͷָ��ָ��NULL

    }
}



