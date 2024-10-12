#include "InsertionSort.h"

#include "vector"

using namespace std;

 void InsertionSort::Sort(vector<int> &data) {
	 int DataLenght = data.size();
	 int key;
	 int PreffixIndex;
	 for (int i = 1; i < DataLenght; i++) {
		 PreffixIndex = i - 1;
		 key = data[i];
		 while (PreffixIndex >= 0 && data[PreffixIndex] > key){
			 data[PreffixIndex + 1] = data[PreffixIndex];
			 PreffixIndex--;
		 }
		 data[PreffixIndex + 1] = key;
	 }
}