//注:元素默认为字符
//输入样例:
// 4
// F
// CE
// ADHG
// ##B###M#

#include <stdio.h>
#include <stdlib.h>
typedef struct BTreeNode{
	char data;//char
	struct BTreeNode* Lchild;
	struct BTreeNode* Rchild;
	//struct BTreeNode* parent;
}Node;
void linkBTree(Node* root,char* str,int i,int n)
{
	root->data = str[i];

	if (i * 2 <= n && str[i * 2] != '#') {
		root->Lchild = (Node*)malloc(sizeof(Node));
		linkBTree(root->Lchild, str, i * 2, n);
	}
	else
		root->Lchild = NULL;

	if (i * 2 + 1 <= n && str[i * 2 + 1] != '#') {
		root->Rchild = (Node*)malloc(sizeof(Node));
		linkBTree(root->Rchild, str, i * 2 + 1, n);
	}
	else
		root->Rchild = NULL;
	return;
}
Node* initBTree()
{
	Node* root= (Node*)malloc(sizeof(Node));
	char* str = (char*)malloc(sizeof(char) * 10);
	//char str[100];
	char c;
	int n=1,len=10;
	int height;
	printf("请输入树的高度:");
	scanf("%d", &height);
	getchar();
	for (int i = 1; i <= height; ++i) {
		printf("请输入第%d行的元素:\n",i);
		while ((c = getchar()) != '\n') {
			if (n >= len) {
				str = (char*)realloc(str, sizeof(char) * (len + 10));
				len += 10;
			}
			str[n++] = c;
		}
	}
	linkBTree(root,str, 1,n-1);
	printf("init done\n");
	return root;
}
//前序遍历(preorder traversal)
//中序遍历(inorder traversal)
//后序遍历(postorder traversal)
void preorderTraversal(Node* root)
{
	if (root == NULL)
		return;
	putchar(root->data);//char
	preorderTraversal(root->Lchild);
	preorderTraversal(root->Rchild);
	return;
}
void inorderTraversal(Node* root)
{
	if (root == NULL)
		return;
	inorderTraversal(root->Lchild);
	putchar(root->data);//char
	inorderTraversal(root->Rchild);
	return;
}
void postorderTraversal(Node* root)
{
	if (root == NULL)
		return;
	postorderTraversal(root->Lchild);
	postorderTraversal(root->Rchild);
	putchar(root->data);//char
	return;
}
//层次遍历---缺陷->非动态,数据较大时可能越界
void levelOrderTraversal(Node* root)
{
    //Node** queue = (Node**)malloc(sizeof(Node) * 100);
    Node* queue[100];
    int head = 0, tail = 0;
    queue[tail] = root;
    tail++;
    while (head!=tail) {
        putchar(queue[head]->data);
        if (NULL != queue[head]->Lchild) {
            queue[tail] = queue[head]->Lchild;
            tail++;
        }
        if (NULL != queue[head]->Rchild) {
            queue[tail] = queue[head]->Rchild;
            tail++;
        }
        head++;
    }
    return;
}
int main()
{
	Node* root = NULL;
	root = initBTree();
	if (root == NULL) {
		printf("error\n");
		exit(-1);
	}
	printf("preorderTraversal:\n");	
	preorderTraversal(root);
	putchar('\n');
	printf("inorderTraversal:\n");
	inorderTraversal(root);
	putchar('\n');
	printf("postorderTraversal:\n");
	postorderTraversal(root);
	putchar('\n');
	printf("levelOrderTraversal:\n");
	levelOrderTraversal(root);
	putchar('\n');
	return 0;
}
