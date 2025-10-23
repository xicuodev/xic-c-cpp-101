#pragma once

// 主要知识：函数模板、冒泡排序、选择排序

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
void BubbleSort(T* ts, int len) { // 冒泡升序排序
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (ts[j] > ts[j + 1]) { // 把本轮的最大项换到后面去
				MySwap(ts[j], ts[j + 1]);
			}
		}
	}
}

template<class T>
void SelectionSort(T* ts, int len) { // 选择升序排序
	int minIndex;
	for (int i = 0; i < len; i++) {
		minIndex = i;
		for (int j = i + 1; j < len; j++) {
			if (ts[j] < ts[minIndex]) {
				minIndex = j; // 更新最小项
			}
		}
		if (minIndex != i) { // 若找到新的最小项，就把它换到前面来
			MySwap(ts[minIndex], ts[i]);
		}
	}
}