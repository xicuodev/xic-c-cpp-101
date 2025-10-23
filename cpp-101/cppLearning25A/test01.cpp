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
	cout << "ȫ�ֱ���\tgA\t�ĵ�ַΪ " << (int)&gA << endl;
	cout << "ȫ�־�̬����\tgsA\t�ĵ�ַΪ " << (int)&gsA << endl;
	cout << "ȫ�ֳ���\tgcA\t�ĵ�ַΪ " << (int)&gcA << endl;
	cout << "ȫ�־�̬����\tgscA\t�ĵ�ַΪ " << (int)&gscA << endl;

	int lA = 1;
	static int lsA = 1;
	int const lcA = 1;
	int static const lscA = 1;

	cout << "�ֲ�����\tlA\t�ĵ�ַΪ " << (int)&lA << endl;
	cout << "�ֲ���̬����\tlsA\t�ĵ�ַΪ " << (int)&lsA << endl;
	cout << "�ֲ�����\tlcA\t�ĵ�ַΪ " << (int)&lcA << endl;
	cout << "�ֲ���̬����\tgscA\t�ĵ�ַΪ " << (int)&lscA << endl;

	int* lnP = new int(10);
	const int* lcnP = new const int(10);

	cout << "�ֲ� new ������\t*lnP\t�ĵ�ַΪ " << (int)lnP << endl;
	cout << "�ֲ� new ������\t*lcnP\t�ĵ�ַΪ " << (int)lcnP << endl;

	delete lnP, lcnP;
}

void mySwap(int& a, int& b) {
	int temp = a; a = b; b = temp;
}
