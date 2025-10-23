#pragma once

class AbstractDrinking {
public:
	void virtual boil() = 0; // 煮水
	void virtual brew() = 0; // 冲泡
	void virtual pour() = 0; // 装杯
	void virtual put() = 0; // 加辅料
	void make() {
		boil(); brew(); pour(); put();
	}
};

class Coffee :public AbstractDrinking {
public:
	void virtual boil() { // 煮水
		cout << "煮农夫山泉" << endl;
	}
	void virtual brew() { // 冲泡
		cout << "冲泡咖啡" << endl;
	}
	void virtual pour() { // 装杯
		cout << "倒入咖啡杯" << endl;
	}
	void virtual put() { // 加辅料
		cout << "加入糖和牛奶" << endl;
	}
};

class Tea :public AbstractDrinking {
public:
	void virtual boil() { // 煮水
		cout << "煮百岁山" << endl;
	}
	void virtual brew() { // 冲泡
		cout << "冲泡茶叶" << endl;
	}
	void virtual pour() { // 装杯
		cout << "倒入茶杯" << endl;
	}
	void virtual put() { // 加辅料
		cout << "加入枸杞" << endl;
	}
};

void makeDrink(AbstractDrinking* absDrinking) {
	absDrinking->make();
	delete absDrinking;
}