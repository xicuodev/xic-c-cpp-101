#pragma once
#include "main.h"

class Animal {
public:
	Animal() {
		cout << "Animal 类构造函数调用" << endl;
	}
	virtual ~Animal() = 0;
	void virtual speak() {
		cout << "动物" << endl;
	}
	int m_Age = 0;
};

Animal::~Animal() {
	cout << "Animal 类纯虚析构函数调用" << endl;
}

class Sheep :virtual public Animal {};
class Camel :virtual public Animal {};
class Cnm :public Sheep, public Camel {};

class Cat :public Animal {
public:
	Cat() {
		cout << "Cat 类无参构造函数调用" << endl;
		m_Meow = new string("Meow");
	}
	Cat(string meow) {
		cout << "Cat 类含参构造函数调用" << endl;
		m_Meow = new string(meow);
	}
	~Cat() {
		cout << "Cat 类析构函数调用" << endl;
		if (m_Meow != NULL) {
			delete m_Meow;
			m_Meow = NULL;
		}
	}
	void speak() {
		cout << "猫说：“" << *m_Meow << "。”" << endl;
	}
	string* m_Meow;
};

void doSpeak(Animal& ani) {
	ani.speak();
}