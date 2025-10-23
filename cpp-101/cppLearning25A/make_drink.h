#pragma once

class AbstractDrinking {
public:
	void virtual boil() = 0; // ��ˮ
	void virtual brew() = 0; // ����
	void virtual pour() = 0; // װ��
	void virtual put() = 0; // �Ӹ���
	void make() {
		boil(); brew(); pour(); put();
	}
};

class Coffee :public AbstractDrinking {
public:
	void virtual boil() { // ��ˮ
		cout << "��ũ��ɽȪ" << endl;
	}
	void virtual brew() { // ����
		cout << "���ݿ���" << endl;
	}
	void virtual pour() { // װ��
		cout << "���뿧�ȱ�" << endl;
	}
	void virtual put() { // �Ӹ���
		cout << "�����Ǻ�ţ��" << endl;
	}
};

class Tea :public AbstractDrinking {
public:
	void virtual boil() { // ��ˮ
		cout << "�����ɽ" << endl;
	}
	void virtual brew() { // ����
		cout << "���ݲ�Ҷ" << endl;
	}
	void virtual pour() { // װ��
		cout << "����豭" << endl;
	}
	void virtual put() { // �Ӹ���
		cout << "�������" << endl;
	}
};

void makeDrink(AbstractDrinking* absDrinking) {
	absDrinking->make();
	delete absDrinking;
}