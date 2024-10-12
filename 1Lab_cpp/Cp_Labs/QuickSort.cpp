
#include "QuickSort.h"
#include "vector"

using namespace std;


int Partition(vector<int>& data, int left, int right) {

	int key = data[right];

	int InsertIndex = left - 1;

	for (int i = left; i <= right - 1; i++) {
		if (data[i] < key) {
			InsertIndex++;
			swap(data[i], data[InsertIndex]);
		}
	}
	swap(data[InsertIndex + 1], data[right]);
	return InsertIndex + 1;
}

void QuickSorting(vector<int>& data, int left, int right) {
	if (left < right) {

		int KeyPosition = Partition(data, left, right);

		QuickSorting(data, left, KeyPosition - 1); // Left part
		QuickSorting(data, KeyPosition + 1, right); //Right part

	}
}

void QuickSort::Sort(vector<int>& data) {
	if (data.size() <= 1) {
		return;
	}
	QuickSorting(data, 0, data.size() - 1);
}