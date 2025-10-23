#pragma once

class Person {
public:
	ostream& showPerson() {
		return cout << "Person(" << m_A << "," << m_B << ")";
	}
	int static m_A;
	int m_B = 20;
};

int Person::m_A = 10;

class Student : public Person {
public:
	long long m_C = 30;
};

ostream& operator<<(ostream& cout, Person& p) {
	return p.showPerson();
}