#pragma once
#include <malloc.h>
#include <stdio.h>

typedef struct ThreadNode {
	char data;
	struct ThreadNode* lchild, * rchild;
	int lthread, rthread;
} ThreadNode;

typedef ThreadNode* ThreadTree;

void strTreeInOrder(char* str, ThreadTree* cur, int* index) {
	char curChar = str[(*index)++];
	if (curChar == '#') *cur = NULL;
	else {
		*cur = (ThreadTree)malloc(sizeof(ThreadNode));
		if (!*cur) return; // 堆内存分配失败，取消建树
		(*cur)->data = curChar;
		(*cur)->lthread = 1;
		(*cur)->rthread = 1;
		// 建立左子树
		strTreeInOrder(str, &(*cur)->lchild, index);
		// 若有左子树，则打上左子树标志 lthread = 0
		if ((*cur)->lchild) (*cur)->lthread = 0;
		// 建立右子树
		strTreeInOrder(str, &(*cur)->rchild, index);
		// 若有右子树，则打上右子树标志 rthread = 0
		if ((*cur)->rchild) (*cur)->rthread = 0;
	}
}

void threading(ThreadTree cur, ThreadTree* prev) {
	if (!cur) return; // 当前子树不存在，归
	// 访问左子树
	threading(cur->lchild, prev);
	// 若当前子树没有左子树，则...
	if (!cur->lchild) {
		// 打上左线索标志 lthread = 1
		cur->lthread = 1;
		// 设左线索（前驱）为前驱子树
		cur->lchild = *prev;
	}
	// 若前驱子树没有右子树，则...
	if (!(*prev)->rchild) {
		// 打上右线索标志 rthread = 1
		(*prev)->rthread = 1;
		// 设右线索（后继）为当前子树
		(*prev)->rchild = cur;
	}
	// 更新前驱子树为当前子树
	*prev = cur;
	// 访问右子树
	threading(cur->rchild, prev);
} // 线索化操作夹在访问左右子树中间，为中序线索化

ThreadTree inOrderThreading(ThreadTree root) {
	// 引入头节点
	ThreadTree head = (ThreadTree)malloc(sizeof(ThreadNode));
	if (!head) return NULL;
	head->lthread = 0;
	head->rthread = 1;
	head->rchild = head; // 初始时自身成环
	// 空树
	if (!root) head->lchild = head;
	else {
		// 根为头节点的左子树
		head->lchild = root;
		// 初始化前驱子树为头节点
		ThreadTree prev = head;
		// 线索化树
		threading(root, &prev);
		// 处理最后一个节点
		prev->rthread = 1;
		prev->rchild = head;
		head->rchild = prev; // 成环
	}
	return head;
}

void inOrder(ThreadTree head) {
	ThreadTree cur = head->lchild;
	while (cur != head) {
		while (!cur->lthread)
			cur = cur->lchild;
		printf("%c ", cur->data);
		while (cur->rthread && cur->rchild != head) {
			cur = cur->rchild;
			printf("%c ", cur->data);
		}
		cur = cur->rchild;
	}
	printf("\n");
}