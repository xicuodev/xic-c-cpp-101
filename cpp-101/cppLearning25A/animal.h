#pragma once
#include "main.h"

class Animal {
public:
	Animal() {
		cout << "Animal �๹�캯������" << endl;
	}
	virtual ~Animal() = 0;
	void virtual speak() {
		cout << "����" << endl;
	}
	int m_Age = 0;
};

Animal::~Animal() {
	cout << "Animal �ി��������������" << endl;
}

class Sheep :virtual public Animal {};
class Camel :virtual public Animal {};
class Cnm :public Sheep, public Camel {};

class Cat :public Animal {
public:
	Cat() {
		cout << "Cat ���޲ι��캯������" << endl;
		m_Meow = new string("Meow");
	}
	Cat(string meow) {
		cout << "Cat �ຬ�ι��캯������" << endl;
		m_Meow = new string(meow);
	}
	~Cat() {
		cout << "Cat ��������������" << endl;
		if (m_Meow != NULL) {
			delete m_Meow;
			m_Meow = NULL;
		}
	}
	void speak() {
		cout << "è˵����" << *m_Meow << "����" << endl;
	}
	string* m_Meow;
};

void doSpeak(Animal& ani) {
	ani.speak();
}