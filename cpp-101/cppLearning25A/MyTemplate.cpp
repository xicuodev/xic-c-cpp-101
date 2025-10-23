#include "MyTemplate.h"
#include <iostream>

template<typename T>
void MyTemplate<T>::print() { // 实现模板函数
	std::cout << "Template!" << std::endl;
}

//void test01() {
//	MyTemplate<int> obj; // 实例化模板类
//	obj.print(); // 调用函数
//}