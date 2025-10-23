#pragma once

// ��Ҫ֪ʶ������ģ�塢ð������ѡ������

template<class T>
void MySwap(T& t1, T& t2) {
	T temp = t1; t1 = t2; t2 = temp;
}

template<class T>
void MyShow(T* ts, int len) {
	for (int i = 0; i < len; i++) {
		cout << ts[i] << " ";
	}
	cout << ";" << endl;
}

template<class T>
void BubbleSort(T* ts, int len) { // ð����������
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (ts[j] > ts[j + 1]) { // �ѱ��ֵ�����������ȥ
				MySwap(ts[j], ts[j + 1]);
			}
		}
	}
}

template<class T>
void SelectionSort(T* ts, int len) { // ѡ����������
	int minIndex;
	for (int i = 0; i < len; i++) {
		minIndex = i;
		for (int j = i + 1; j < len; j++) {
			if (ts[j] < ts[minIndex]) {
				minIndex = j; // ������С��
			}
		}
		if (minIndex != i) { // ���ҵ��µ���С��Ͱ�������ǰ����
			MySwap(ts[minIndex], ts[i]);
		}
	}
}