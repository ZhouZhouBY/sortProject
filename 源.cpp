#include <iostream>
using namespace std;

void quickSort(int a[], int, int);
void bubbleSort(int a[], int);
void insertSort(int a[], int);
void selectSort(int a[], int);
void mergeSort(int a[], int, int);
void merge(int a[], int, int, int);
void shellSort(int a[], int);

int main() {
	int index;
	cout << "please choose the sort type" << endl;
	cout << "1.quickSort" << endl;
	cout << "2.bubbleSort" << endl;
	cout << "3.insertSort" << endl;
	cout << "4.selectSort" << endl;
	cout << "5.mergeSort" << endl;
	cout << "6.shellSort" << endl;
	cin >> index;
	int array[] = { 34, 65, 12, 43, 67, 5, 78, 10, 3, 70 }, k;
	int len = sizeof(array) / sizeof(int);
	cout << "the original array are:" << endl;
	for (k = 0; k < len; ++k) {
		cout << array[k];
		if (k != len - 1) {
			cout << ",";
		}
	}
	cout << endl;
	switch (index)
	{
	case 1:
		quickSort(array, 0, len - 1);
		cout << "the result of quickSort are:" << endl;
		break;
	case 2:
		bubbleSort(array, len);
		cout << "the result of bubbleSort are:" << endl;
		break;
	case 3:
		insertSort(array, len);
		cout << "the result of insertSort are:" << endl;
		break;
	case 4:
		selectSort(array, len);
		cout << "the result of selectSort are:" << endl;
		break;
	case 5:
		mergeSort(array, 0, len - 1);
		cout << "the result of mergeSort are:" << endl;
		break;
	case 6:
		shellSort(array, len);
		cout << "the result of shellSort are:" << endl;
		break;
	default:
		break;
	}
	for (k = 0; k < len; ++k) {
		cout << array[k];
		if (k != len - 1) {
			cout << ",";
		}
	}
	cout << endl;
}

void quickSort(int array[], int l, int r) {
	if (l < r) {
		int i = l, j = r, temp = array[l];
		while (i < j) {
			while (i < j && temp < array[j]) {
				--j;
			}
			if (i < j) {
				array[i++] = array[j];
			}
			while (i < j && temp > array[i]) {
				++i;
			}
			if (i < j) {
				array[j--] = array[i];
			}
		}
		array[i] = temp;
		quickSort(array, l, i - 1);
		quickSort(array, i + 1, r);
	}
}

void bubbleSort(int array[], int len) {
	for (int i = 0; i < len - 1; ++i) {
		for (int j = 0; j < len - i - 1; ++j) {
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
			}
		}
	}
}

void insertSort(int array[], int len) {
	for (int i = 1; i < len; ++i) {
		int temp = array[i];
		int tag = 0;
		for (int j = i - 1; j >= 0; --j) {
			if (temp < array[j]) {
				array[j + 1] = array[j];
			}
			else {
				tag = 1;
				array[j + 1] = temp;
				break;
			}
		}
		if (tag == 0) {
			array[0] = temp;
		}
	}
}

void selectSort(int array[], int len) {
	for (int i = 0; i < len; ++i) {
		int Max = array[0];
		int index = 0;
		for (int j = 0; j < len - i; ++j) {
			if (array[j] > Max) {
				Max = array[j];
				index = j;
			}
		}
		swap(array[index], array[len - i - 1]);
	}
}

void merge(int array[], int l, int m, int r) {
	int i = l, j = m + 1, k = 0;
	int* temp = new int[r - l + 1];
	while (i <= m && j <= r) {
		if (array[i] <= array[j]) {
			temp[k++] = array[i++];
		}
		else {
			temp[k++] = array[j++];
		}
	}
	while (i <= m) {
		temp[k++] = array[i++];
	}
	while (j <= r) {
		temp[k++] = array[j++];
	}
	for (i = l, k = 0; i <= r; ++i, ++k) {
		array[i] = temp[k];
	}
	delete[] temp;
}

void mergeSort(int array[], int l, int r) {
	if (l >= r) {
		return;
	}
	int mid = (l + r) / 2;
	mergeSort(array, l, mid);
	mergeSort(array, mid + 1, r);
	merge(array, l, mid, r);
}

void shellSort(int array[], int len) {
	for (int gap = len / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < len; ++i) {
			int j = i;
			while (j - gap >= 0 && array[j - gap] > array[j]) {
				array[j - gap] = array[j - gap] + array[j];
				array[j] = array[j - gap] - array[j];
				array[j - gap] = array[j - gap] - array[j];
				j -= gap;
			}
		}
	}
}
