// º¯ÊýÖ¸Õë
#include <stdio.h>

typedef int(*Calc)(int, int);

int Add(int, int);
int Sub(int, int);
void CalcWithoutFuncPtr();
void CalcWithFuncPtr();

int main() {
	//CalcWithoutFuncPtr();
	CalcWithFuncPtr();
	return 0;
}

int Add(int a, int b) {
	return a + b;
}

int Sub(int a, int b) {
	return a - b;
}

void CalcWithoutFuncPtr() {
	int x = 10; int y = 7; int z = 0;
	
	z = Add(x, y);
	printf("%d+%d=%d\n", x, y, z);
	
	z = Sub(x, y);
	printf("%d-%d=%d\n", x, y, z);
}

void CalcWithFuncPtr() {
	int x = 10; int y = 7; int z = 0;

	Calc FuncPtr1 = Add;
	Calc FuncPtr2 = Sub;

	z = FuncPtr1(x, y);
	printf("%d+%d=%d\n", x, y, z);
	
	z = FuncPtr2(x, y);
	printf("%d-%d=%d\n", x, y, z);
}