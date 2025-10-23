#pragma once
// 中缀表达式转后缀表达式
#include "myStack.h"
#include "opToken.h"
#include <stdio.h>

char* postOf(char* mid) {
	char* post = (char*)malloc(sizeof(char) * MaxSize);
	if (!post) {
		printf("创建字符串时内存分配失败。\n");
		return NULL;
	}
	char op; int mIndex = 0; int pIndex = 0;
	MyStack* ops = initMyStack();
	OpType token = nextToken(mid, &mIndex, &op);
	push(ops, 0);
	while (token != EOS) {
		if (token == NUM) post[pIndex++] = op;
		else if (token == RIGHT_PARE) {
			while (topOf(ops) != LEFT_PARE)
				post[pIndex++] = opOf(pop(ops));
			pop(ops); // 弹出左括号
		}
		else {
			while (outerRatings[token] <= innerRatings[topOf(ops)])
				post[pIndex++] = opOf(pop(ops));
			push(ops, token); // 压入优先级大于栈顶元素优先级的 token
		}
		token = nextToken(mid, &mIndex, &op);
	}
	// 弹出剩余运算符
	while (ops->top > 0) {
		post[pIndex++] = opOf(pop(ops));
	}
	post[pIndex] = '\0'; // 终止字符串
	return post;
}