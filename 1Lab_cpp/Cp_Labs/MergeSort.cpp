#include "MergeSort.h"
#include "vector"

using namespace std;

void MergeSort::Sort(vector<int> &data) {
	int DataLenght = data.size();
	int DataSeparator;
	if (DataLenght > 1) {
		DataSeparator = DataLenght / 2;
		// Разделяем коллекцию на две части
		std::vector<int> dataLeft(data.begin(), data.begin() + DataSeparator); // Левая

		std::vector<int> dataRight(data.begin() + DataSeparator, data.end()); // Правая

		Sort(dataLeft);
		Sort(dataRight);
		Merge(data, dataLeft, dataRight);
	}
}

void MergeSort::Merge(vector<int>& data, vector<int>& left, vector<int>& right) {
	int LPointer = 0;
	int RPointer = 0;

	int lenL = left.size();
	int lenR = right.size();

	while (LPointer < lenL || RPointer < lenR) {
		if (LPointer < lenL & RPointer < lenR) {
			if (left[LPointer] <= right[RPointer]) {
				data[LPointer + RPointer] = left[LPointer];
				LPointer++;
			}
			else {
				data[LPointer + RPointer] = right[RPointer];
				RPointer++;
			}
		}
		else if (LPointer < lenL) {
			data[LPointer + RPointer] = left[LPointer];
			LPointer++;
		}
		else if (RPointer < lenR) {
			data[LPointer + RPointer] = right[RPointer];
			RPointer++;
		}
	}
}