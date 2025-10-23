#pragma once
#include "main.h"

class CPU {
public:
	virtual ~CPU() {
		cout << "CPU ÐéÎö¹¹" << endl;
	}
	void virtual compute() = 0;
};

class DisplayCard {
public:
	virtual ~DisplayCard() {
		cout << "DisplayCard ÐéÎö¹¹" << endl;
	}
	void virtual display() = 0;
};

class Memory {
public:
	virtual ~Memory() {
		cout << "Memory ÐéÎö¹¹" << endl;
	}
	void virtual storage() = 0;
};

class Computer {
public:
	Computer(CPU* cpu, DisplayCard* dc, Memory* mem) {
		m_cpu = cpu;
		m_dc = dc;
		m_mem = mem;
	}
	~Computer() {
		cout << "Computer Îö¹¹" << endl;
		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_dc != NULL) {
			delete m_dc;
			m_dc = NULL;
		}
		if (m_mem != NULL) {
			delete m_mem;
			m_mem = NULL;
		}
	}
	void work() {
		m_cpu->compute();
		m_dc->display();
		m_mem->storage();
	}
private:
	CPU* m_cpu;
	DisplayCard* m_dc;
	Memory* m_mem;
};

class IntelCPU :public CPU {
public:
	~IntelCPU() {
		cout << "IntelCPU ÐéÎö¹¹" << endl;
	}
	void compute() {
		cout << "IntelCPU" << endl;
	}
};

class NvidiaDisplayCard :public DisplayCard {
public:
	~NvidiaDisplayCard() {
		cout << "NvidiaDisplayCard ÐéÎö¹¹" << endl;
	}
	void display() {
		cout << "NvidiaDisplayCard" << endl;
	}
};

class LenovoMemory :public Memory {
public:
	~LenovoMemory() {
		cout << "LenovoMemory ÐéÎö¹¹" << endl;
	}
	void storage() {
		cout << "LenovoMemory" << endl;
	}
};

void computer_test01() {
	CPU* cpuIntel = new IntelCPU;
	DisplayCard* dcNvidia = new NvidiaDisplayCard;
	Memory* memLenovo = new LenovoMemory;
	Computer* myPC = new Computer(cpuIntel, dcNvidia, memLenovo);
	myPC->work();
	delete myPC;
}