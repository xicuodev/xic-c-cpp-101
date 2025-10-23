#pragma once

class Person {
public:
	Person(string name, int age) {
		m_Name = name;
		m_Age = age;
	}
	string m_Name;
	int m_Age;
};

// 为 Person 类重载一个左移运算符（只能用全局函数重载）
ostream& operator<<(ostream& cout, Person& p) {
	return cout << "Person(name: " << p.m_Name
		<< "\tage: " << p.m_Age << ")";
}

template<class T>
class MyArray {
public:
	MyArray(int maxSize) {
		m_MaxSize = maxSize;
		m_CurSize = 0;
		m_Ts = new T[m_MaxSize]; // m_Ts 指向堆区开辟的数组 T[m_MaxSize]
	}

	// 拷贝构造，解决拷贝构造时的浅拷贝
	MyArray(MyArray const& arr) {
		//cout << "MyArray 拷贝构造调用" << endl;
		m_MaxSize = arr.m_MaxSize;
		m_CurSize = arr.m_CurSize;
		m_Ts = new T[m_MaxSize];
		for (int i = 0; i < arr.m_CurSize; i++) {
			m_Ts[i] = arr.m_Ts[i];
		}
	}

	// 赋值运算符重载，能动地避开赋值时的浅拷贝
	MyArray& operator=(MyArray const& arr) {
		//cout << "MyArray 重载赋值运算符调用" << endl;
		m_MaxSize = arr.m_MaxSize;
		m_CurSize = arr.m_CurSize;
		if (m_Ts != nullptr) delete[] m_Ts;
		m_Ts = new T[m_MaxSize];
		for (int i = 0; i < arr.m_CurSize; i++) {
			m_Ts[i] = arr.m_Ts[i];
		}
		return *this;
	}

	// 返回数组容量
	int MaxSize() {
		return m_MaxSize;
	}

	// 返回数组载量
	int CurSize() {
		return m_CurSize;
	}

	// 尾插法
	void PushBack(T const& tToPush) {
		// 边界检查
		if (m_CurSize == m_MaxSize) return;
		m_Ts[m_CurSize] = tToPush; // m_CurSize 就是当前末尾的后一位
		m_CurSize++;
	}

	// 尾删法
	void PopBack() {
		// 边界检查
		if (!m_CurSize) return;
		// 让用户访问不到末尾元素，逻辑尾删，等之后析构时集中删除
		m_CurSize--;
	}

	// （*）重载中括号运算符
	T& operator[](int index) {
		// 边界检查，如果越界就直接返回首/尾元素，若数组为空就尾插一个元素来返回
		if (!m_CurSize) {
			T tToPush; PushBack(tToPush);
		}
		if (index >= m_CurSize) {
			// 直接修改 index 到末尾元素下标
			index = m_CurSize - 1;
		}
		else if (index < 0) {
			// 直接修改 index 到开头元素下标
			index = 0;
		}
		return m_Ts[index];
	}

	// 打印指定下标的元素的值和地址
	void Show(int index) {
		cout << "ind: " << index
			 << "\tval: " << m_Ts[index]
			 << "\tadd: " << &m_Ts[index] << endl;
	}

	// 打印所有已装载元素的值和地址
	void ShowAll() {
		if (!m_CurSize) {
			cout << "数组已装载部分为空。" << endl;
			return;
		}
		for (int i = 0; i < m_CurSize; i++) {
			Show(i);
		}
		cout << "max: " << m_MaxSize
			 << "\tcur: " << m_CurSize << endl << endl;
	}

	~MyArray() {
		if (m_Ts != nullptr) {
			delete[] m_Ts; // 删除整个数组
			m_Ts = nullptr;
		}
	}

private:
	T* m_Ts; // 指向堆区内存的指针（问题：浅拷贝）
	int m_MaxSize; // 数组容量（最多能装多少元素）
	int m_CurSize; // 数组载量（当前装了多少元素）
};

//void test01() {
//	MyArray<int> arr1(5);
//	arr1[4] = 1017; // 实则尾插 arr1[0] 并给它赋值为 1017
//	arr1.Show(4); // ind: 4  val: -842150451 add: 000002D2CE8A5A00
//	arr1.Show(0); // ind: 0  val: 1017       add: 000002D2CE8A59F0
//}

//void test01() {
//	MyArray<int> arr1(5);
//	for (int i = 0; i < 5; i++) {
//		arr1.PushBack(i);
//	}
//	arr1.ShowAll(); // max: 5  cur: 5
//	arr1.PopBack();
//	arr1.ShowAll(); // max: 5  cur: 4
//}

//void test01() {
//	MyArray<Person> arr1(5);
//	Person p1("张三", 18);
//	Person p2("李四", 20);
//	Person p3("王五", 22);
//	Person p4("赵六", 24);
//	Person p5("刘七", 26);
//	arr1.PushBack(p1);
//	arr1.PushBack(p2);
//	arr1.PushBack(p3);
//	arr1.PushBack(p4);
//	arr1.PushBack(p5);
//	arr1.ShowAll();
//}