#pragma once
// 获取表达式字符串中的每个字符，即 token
// op 是 operand 操作数或 operator 操作符
// mid 是中缀表达式
#include "myStack.h"

char ops[] = { '(',')','+','-','*','/','%','\0' };

typedef enum {
	LEFT_PARE, RIGHT_PARE, ADD, SUB, MUL, DIV, MOD, EOS, NUM
} OpType;

int innerRatings[] = { 0, 19,12,12,13,13,13,0 };
int outerRatings[] = { 20,19,12,12,13,13,13,0 };

OpType nextToken(char* mid, int* index, char* op) {
	*op = mid[(*index)++];
	switch (*op) {
	case '(':
		return LEFT_PARE;
	case ')':
		return RIGHT_PARE;
	case '+':
		return ADD;
	case '-':
		return SUB;
	case '*':
		return MUL;
	case '/':
		return DIV;
	case '%':
		return MOD;
	case '\0':
		return EOS;
	default:
		return NUM;
	}
}

char opOf(int opIndex) {
	return ops[opIndex];
}
