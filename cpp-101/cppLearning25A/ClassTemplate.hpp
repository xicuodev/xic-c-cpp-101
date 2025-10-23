#pragma once

// ��Ҫ֪ʶ����ģ�塢����ģ�塢��Ԫ

template<class A, class N>
class Person;

template<class A, class N>
void MyPrint(Person<A, N>& p) {
	cout << "name: " << p.m_Name << "; age: " << p.m_Age << endl;
}

template<class A, class N>
class Person {
	friend void MyPrint<>(Person<A, N>& p);
public:
	Person(A age, N name) {
		m_Age = age;
		m_Name = name;
	}
private:
	A m_Age;
	N m_Name;
};

//void test01() {
//	Person<int, string> p(18, "����");
//	MyPrint(p);
//}