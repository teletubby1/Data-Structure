/* ����˫�ױ�ʾ�����ṹ���� */
#define MAX_TREE_SIZE 100 //�������Ĵ�С
typedef int TElemType; //�������������ͣ��ݶ�Ϊ����
typedef struct PTNode //���ṹ
{
	TElemType data; //�������
	int parent; //˫��λ��
}PTNode;
typedef struct //���ṹ
{
	PTNode nodes[MAX_TREE_SIZE]; //�������
	int t, n; //����λ�úͽ����
};

/* ���ĺ��ӱ�ʾ���ṹ���� */
typedef struct CTNode //���ӽ��
{
	int child;
	struct CTNode* next;
}*ChildPtr;

typedef struct //��ͷ�ṹ
{
	TElemType data;
	ChildPtr firstchild;
}CTBox;

typedef struct //���ṹ
{
	CTBox nodes[MAX_TREE_SIZE]; //�������
	int r, n; //����λ�úͽ����
};

/* ���ĺ����ֵܱ�ʾ���ṹ���� */
typedef struct CSNode
{
	TElemType data;
	struct CSNode* firstchild, * rightsib;
}CSNode,*CSTree;