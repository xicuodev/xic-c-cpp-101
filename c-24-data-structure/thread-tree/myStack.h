#pragma once
#include <malloc.h>
#include <stdio.h>

// #define MAXSIZE 100
const int MaxSize = 100;

typedef struct {
	int* data;
	int top;
} MyStack;

MyStack* initMyStack() {
	MyStack* s = (MyStack*)malloc(sizeof(MyStack));
	if (!s) {
		printf("创建栈时内存分配失败。\n");
		return NULL;
	}
	s->data = (int*)malloc(sizeof(int) * MaxSize);
	s->top = -1;
	return s;
}

int isEmpty(MyStack* s) {
	return s->top <= -1;
}

int isFull(MyStack* s) {
	return s->top >= MaxSize - 1;
}

int topOf(MyStack* s) {
	return s->data[s->top];
}

int pop(MyStack* s) {
	s->top--;
	return s->data[s->top + 1];
}

void push(MyStack* s, int e) {
	s->data[++s->top] = e;
}