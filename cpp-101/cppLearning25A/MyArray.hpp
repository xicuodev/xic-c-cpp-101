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

// Ϊ Person ������һ�������������ֻ����ȫ�ֺ������أ�
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
		m_Ts = new T[m_MaxSize]; // m_Ts ָ��������ٵ����� T[m_MaxSize]
	}

	// �������죬�����������ʱ��ǳ����
	MyArray(MyArray const& arr) {
		//cout << "MyArray �����������" << endl;
		m_MaxSize = arr.m_MaxSize;
		m_CurSize = arr.m_CurSize;
		m_Ts = new T[m_MaxSize];
		for (int i = 0; i < arr.m_CurSize; i++) {
			m_Ts[i] = arr.m_Ts[i];
		}
	}

	// ��ֵ��������أ��ܶ��رܿ���ֵʱ��ǳ����
	MyArray& operator=(MyArray const& arr) {
		//cout << "MyArray ���ظ�ֵ���������" << endl;
		m_MaxSize = arr.m_MaxSize;
		m_CurSize = arr.m_CurSize;
		if (m_Ts != nullptr) delete[] m_Ts;
		m_Ts = new T[m_MaxSize];
		for (int i = 0; i < arr.m_CurSize; i++) {
			m_Ts[i] = arr.m_Ts[i];
		}
		return *this;
	}

	// ������������
	int MaxSize() {
		return m_MaxSize;
	}

	// ������������
	int CurSize() {
		return m_CurSize;
	}

	// β�巨
	void PushBack(T const& tToPush) {
		// �߽���
		if (m_CurSize == m_MaxSize) return;
		m_Ts[m_CurSize] = tToPush; // m_CurSize ���ǵ�ǰĩβ�ĺ�һλ
		m_CurSize++;
	}

	// βɾ��
	void PopBack() {
		// �߽���
		if (!m_CurSize) return;
		// ���û����ʲ���ĩβԪ�أ��߼�βɾ����֮������ʱ����ɾ��
		m_CurSize--;
	}

	// ��*�����������������
	T& operator[](int index) {
		// �߽��飬���Խ���ֱ�ӷ�����/βԪ�أ�������Ϊ�վ�β��һ��Ԫ��������
		if (!m_CurSize) {
			T tToPush; PushBack(tToPush);
		}
		if (index >= m_CurSize) {
			// ֱ���޸� index ��ĩβԪ���±�
			index = m_CurSize - 1;
		}
		else if (index < 0) {
			// ֱ���޸� index ����ͷԪ���±�
			index = 0;
		}
		return m_Ts[index];
	}

	// ��ӡָ���±��Ԫ�ص�ֵ�͵�ַ
	void Show(int index) {
		cout << "ind: " << index
			 << "\tval: " << m_Ts[index]
			 << "\tadd: " << &m_Ts[index] << endl;
	}

	// ��ӡ������װ��Ԫ�ص�ֵ�͵�ַ
	void ShowAll() {
		if (!m_CurSize) {
			cout << "������װ�ز���Ϊ�ա�" << endl;
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
			delete[] m_Ts; // ɾ����������
			m_Ts = nullptr;
		}
	}

private:
	T* m_Ts; // ָ������ڴ��ָ�루���⣺ǳ������
	int m_MaxSize; // ���������������װ����Ԫ�أ�
	int m_CurSize; // ������������ǰװ�˶���Ԫ�أ�
};

//void test01() {
//	MyArray<int> arr1(5);
//	arr1[4] = 1017; // ʵ��β�� arr1[0] ��������ֵΪ 1017
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
//	Person p1("����", 18);
//	Person p2("����", 20);
//	Person p3("����", 22);
//	Person p4("����", 24);
//	Person p5("����", 26);
//	arr1.PushBack(p1);
//	arr1.PushBack(p2);
//	arr1.PushBack(p3);
//	arr1.PushBack(p4);
//	arr1.PushBack(p5);
//	arr1.ShowAll();
//}