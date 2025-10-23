#include "test01.h"

int gA = 1;
static int gsA = 1;
const int gcA = 1;
static const int gscA = 1;

void times9x9Sheet() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j <= i; j++) {
			cout << i + 1 << " * " << j + 1 << " = " << (i + 1) * (j + 1) << "\t";
		}
		cout << endl;
	}
}

void memory4Areas() {
	cout << "全局变量\tgA\t的地址为 " << (int)&gA << endl;
	cout << "全局静态变量\tgsA\t的地址为 " << (int)&gsA << endl;
	cout << "全局常量\tgcA\t的地址为 " << (int)&gcA << endl;
	cout << "全局静态常量\tgscA\t的地址为 " << (int)&gscA << endl;

	int lA = 1;
	static int lsA = 1;
	int const lcA = 1;
	int static const lscA = 1;

	cout << "局部变量\tlA\t的地址为 " << (int)&lA << endl;
	cout << "局部静态变量\tlsA\t的地址为 " << (int)&lsA << endl;
	cout << "局部常量\tlcA\t的地址为 " << (int)&lcA << endl;
	cout << "局部静态常量\tgscA\t的地址为 " << (int)&lscA << endl;

	int* lnP = new int(10);
	const int* lcnP = new const int(10);

	cout << "局部 new 出变量\t*lnP\t的地址为 " << (int)lnP << endl;
	cout << "局部 new 出常量\t*lcnP\t的地址为 " << (int)lcnP << endl;

	delete lnP, lcnP;
}

void mySwap(int& a, int& b) {
	int temp = a; a = b; b = temp;
}
