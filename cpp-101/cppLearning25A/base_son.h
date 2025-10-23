#pragma once
class Base {
public:
	int static m_A;
};
int Base::m_A = 10;

class Son : public Base {
public:
	int static m_A;
};
int Son::m_A = 20;