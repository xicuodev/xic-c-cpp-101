
#include "linked-list.h"

int main() {
	LinkedNode *head = NULL; // 构造一个空链表
	
	printf("输入在开头插入链表的整数：（-1 退出）\n");
	int input;
	while (1) {
		scanf("%d", &input);
		if (input == -1) break;
		head = InsertHead(input, head); // 将输入值插入链表开头，再更新开头
		PrintAll(head);
	}
	
	printf("输入在末尾插入链表的整数：（-1 退出）\n");
	while (1) {
		scanf("%d", &input);
		if (input == -1) break;
		InsertEnd(input, head);
		PrintAll(head);
	}
	
	int n;
	printf("输入在指定位置插入链表的整数：（-1 退出）\n");
	while (1) {
		scanf("%d", &input);
		if (input == -1) break;
		printf("你想把它作为第几项插入？");
		scanf("%d", &n);
		InsertAt(n, input, &head);
		PrintAll(head);
	}
	
	printf("输入指定删除的项序数：（-1 退出）\n");
	while (1) {
		scanf("%d", &n);
		if (n == -1) break;
		DeleteAt(n, &head);
		PrintAll(head);
	}
	
	return 0;
}