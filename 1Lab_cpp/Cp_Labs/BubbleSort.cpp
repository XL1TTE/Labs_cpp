#include "BubbleSort.h"
#include "iostream"


using namespace std;


void BubbleSort::Sort(vector<int>& data) {

	int DataLenght = data.size();

	for (int i = 0; i < DataLenght; i++) {
		for (int j = (DataLenght - 1); j >= (i + 1); j--) {
			if (data[j] < data[j - 1]) {
				swap(data[j], data[j-1]);
			}
		}

	}
}

void BubbleSort::Sort(int data[], int DataLenght) {

	for (int i = 0; i < DataLenght; i++) {
		for (int j = (DataLenght - 1); j >= (i + 1); j--) {
			if (data[j] < data[j - 1]) {
				swap(data[j], data[j - 1]);
			}
		}

	}
}