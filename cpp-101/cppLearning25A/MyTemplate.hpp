#pragma once

template<typename T>
class MyTemplate {
public:
    void print(); // ֻ��������ʵ��
};

template<typename T>
void MyTemplate<T>::print() { // ʵ��ģ�庯��
	std::cout << "Template!" << std::endl;
}

//void test01() {
//	MyTemplate<int> obj; // ʵ����ģ����
//	obj.print(); // ���ú���
//}