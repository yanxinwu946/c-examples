/*
单链表-实现建增删改查显毁
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int value;
	struct NODE*next;
} Node;

Node* sll_create() {//建
	Node *head, *current;
	int n, value;

	printf("input number if nodes:");
	scanf("%d", &n);
	printf("input %d values as node data:\n", n);

	head = (Node*)malloc(sizeof(Node));
	if (head == NULL) {
		printf("error");
		exit(-1);
	}
	current = head;
	for (int i = 0; i < n; ++i) {
		current->next = (Node*)malloc(sizeof(Node));
		if (current->next == NULL) {
			printf("error");
			exit(-1);
		}
		current = current->next;
		scanf("%d", &value);
		current->value = value;
	}
	current->next = NULL;
	//删除头结点以节省空间
	current = head->next;
	free(head);
	return current;
}

//需要传入头指针的指针
int sll_insert(Node **rootp, int idx, int value) {//增
	int i = 1;
	Node*pre = NULL, *current = *rootp, *new_node;
	while (i++ < idx && current != NULL) {
		pre = current;
		current = current->next;
	}
	if (current == NULL) {
		printf("error: incorrect insertion position\n");
		return 0;
	}
	new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("error");
		exit(-1);
	}

	new_node->value = value;
	new_node->next = current;
	if (pre == NULL)
		*rootp = new_node;
	else
		pre->next = new_node;
	return 1;
}
#if 0
//增-->改进
int sll_insert(Node **linkp, int idx, int value) {//增
	Node*current;
	Node*new_node;
	int i = 1;
	while ((current = *linkp) != NULL && i++ < idx) {
		linkp = &current->next;
	}

	new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("error");
		exit(-1);
	}
	new_node->value = value;
	new_node->next = current;
	*linkp=new_node;
	return 1;
}
#endif

//同样需要传入头指针的指针
int sll_delete(Node**rootp, int idx) {//删
	int i = 1;
	Node*pre = NULL, *current = *rootp;
	while (i++ < idx && current != NULL) {
		pre = current;
		current = current->next;
	}
	if (current == NULL) {
		printf("error: incorrect deletion position\n");
		return 0;
	}
	if (pre == NULL)
		*rootp = current->next;
	else
		pre->next = current->next;
	free(current);
	return 1;
}

int sll_rewrite(Node*current, int idx, int value) { //改
	int i = 1;
	while (i++ < idx && current != NULL)
		current = current->next;
	if (current == NULL) {
		printf("error: incorrect rewrite data location\n");
		return 0;
	}
	current->value = value;
	return 1;
}

int sll_search(Node*current, int idx) {//查
	int i = 1;
	while (i++ < idx && current != NULL)
		current = current->next;
	if (current == NULL) {
		printf("error: incorrect location\n");
		return 0;
	}
	printf("[%d]%d\n", idx, current->value);
	return 1;
}

void sll_print(Node*current) {//显
	int idx = 1;
	while (current != NULL) {
		printf("[%d]%d->", idx, current->value);
		current = current->next;
		idx++;
	}
	printf("NULL\n");
}

//需要传递头指针的指针
int sll_destory(Node**rootp) { //毁
	Node*current = *rootp;
	Node*next;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	return 1;
}

int main() {
	Node *head;
	head = sll_create();
	//sll_insert(&head, 1, 5); //第1个结点处插入数据为5的结点
	//sll_delete(&head, 1); //删除第1个结点
	//sll_rewrite(head,1,-1);//改写数据
	//sll_search(head,3);//查
	//sll_destory(&head);
	sll_print(head);
	return 0;
}