#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct node {
	ElemType data;
	struct node *next;
} LinkedNode;

// 代表链表的变量本质是一个链表节点
typedef LinkedNode LinkedList;

// 1. 初始化单链表
LinkedList *init();
// 2. 释放单链表
bool myFree(LinkedList *);
// 4. 增：在第 i 个位置插入节点
bool insert(LinkedList *, int, ElemType);
// 5. 删：删除第 i 个节点
bool delete(LinkedList *, int);


void InsertEnd(ElemType newData, LinkedNode *head) { // 在末尾插入节点
	// 1. 构造一个节点（作为新的末尾节点）
	LinkedNode *newEnd = (LinkedNode *) malloc(sizeof(LinkedNode));
	newEnd->data = newData;
	newEnd->next = NULL;
	
	// 2. 在结尾插入该节点
	LinkedNode *goOldEnd = head;
		// 不能随意修改 head 的值，它指向链表的开头节点，用于定位链表
	while (goOldEnd->next != NULL) {
		goOldEnd = goOldEnd->next;
	} // 定位到末尾节点
	goOldEnd->next = newEnd; // 让旧的末尾节点接上 newEnd 所指节点
}

LinkedNode * InsertHead(int newData, LinkedNode *head) { // 在开头插入节点
	LinkedNode *newHead = (LinkedNode *) malloc(sizeof(LinkedNode));
	newHead->data = newData;
	newHead->next = head; // 接上旧的开头节点
	return newHead;
		// 因为开头改变了，而主函数并不知道这一点，所以需要返回新的开头
		// 或者可以使用指针的指针（二级指针）追踪修改主函数中的 head（见 5 InsertAt 函数）
}

void InsertAt(int n, int newData, LinkedNode **head) {
	LinkedNode *newNode = (LinkedNode *) malloc(sizeof(LinkedNode));
	newNode->data = newData;
	newNode->next = NULL;
	
	if (n == 1) { // 若为头节点，则直接连接并更新头节点即可
		newNode->next = *head;
		*head = newNode;
		return; // 结束 void 返回值的函数
	}
	
	LinkedNode *goIns = *head;
	for (int i = 0; i < n - 2; i++) {
		// 循环 n-2 次即可到达插入位置，即第 n-1 项（i = 0 会做一次）
		goIns = goIns->next;
	} // 定位到第 n-1 项，即目标节点的前一项
	
	// 接线
	newNode->next = goIns->next; // newNode 接前一项所接项（含 NULL）
	goIns->next = newNode; // 前一项换接 newNode
}

void DeleteAt(int n, LinkedNode **head) {
	LinkedNode *goDel = *head;
	
	if (n == 1) { // 若为头节点，则直接换接线并释放内存即可
		*head = goDel->next; // 头指针 head 换接新的头节点
		free(goDel); // 释放目标节点
		return;
	}
	
	for (int i = 0; i < n-2; i++) {
		goDel = goDel->next;
	} // 定位到第 n-1 项，即目标节点的前一项
	LinkedNode *Del = goDel->next; // 定位目标节点
	
	// 换接线
	goDel->next = Del->next; // 前一项换接目标节点所接项（含 NULL）
	free(Del); // 释放目标节点
}

void PrintAll(LinkedNode *head) { // 打印所有链表数据
	LinkedNode *curNode = head;
	printf("当前列表为：");
	while (curNode != NULL) {
		printf(" %d", curNode->data); // 打印当前节点数据
		curNode = curNode->next; // 步进 1 个节点
	}
	printf("\n");
}