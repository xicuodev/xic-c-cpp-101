#include "MyTemplate.h"
#include <iostream>

template<typename T>
void MyTemplate<T>::print() { // ʵ��ģ�庯��
	std::cout << "Template!" << std::endl;
}

//void test01() {
//	MyTemplate<int> obj; // ʵ����ģ����
//	obj.print(); // ���ú���
//}