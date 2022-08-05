/* 树的双亲表示法结点结构定义 */
#define MAX_TREE_SIZE 100 //定义树的大小
typedef int TElemType; //树结点的数据类型，暂定为整型
typedef struct PTNode //结点结构
{
	TElemType data; //结点数据
	int parent; //双亲位置
}PTNode;
typedef struct //树结构
{
	PTNode nodes[MAX_TREE_SIZE]; //结点数组
	int t, n; //根的位置和结点数
};

/* 树的孩子表示法结构定义 */
typedef struct CTNode //孩子结点
{
	int child;
	struct CTNode* next;
}*ChildPtr;

typedef struct //表头结构
{
	TElemType data;
	ChildPtr firstchild;
}CTBox;

typedef struct //树结构
{
	CTBox nodes[MAX_TREE_SIZE]; //结点数组
	int r, n; //根的位置和结点数
};

/* 树的孩子兄弟表示法结构定义 */
typedef struct CSNode
{
	TElemType data;
	struct CSNode* firstchild, * rightsib;
}CSNode,*CSTree;