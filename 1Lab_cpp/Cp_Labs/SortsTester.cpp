#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "CountingSort.h"
#include "vector"
#include "iostream"
#include "string"
#include "chrono"
#include "SortsTester.h"

using namespace std;

vector<int> GenerateDataToTest(int dataSize) {
	std::vector<int> data = std::vector<int>();
	for (int i = 0; i < dataSize; ++i)
	{
		int x;
		x = rand() % 1000;
		data.push_back(x);
	}
    return data;
}

chrono::duration<double> MeasureSortingTime(void (*sortFunction)(vector<int>&), vector<int>& data) {
    auto start = chrono::high_resolution_clock::now();
    sortFunction(data);
    auto end = chrono::high_resolution_clock::now();

    return end - start;
}

void PrepareToTest(int dataSize, vector<int>& dataToTestHolder, vector<int>& expectedDataHolder) {
    vector<int> data = GenerateDataToTest(dataSize);
    dataToTestHolder = data;
    vector<int> expected = data;
    MergeSort::Sort(expected);
    expectedDataHolder = expected;
}


string Compare(vector<int>& expected, vector<int>& actual) {
    if (expected == actual) {
        return "Results are equal.";
    }
    else {
        return "Results are not equal.";
    }
}

void SortsTester::Test(int VectorSize) {
    vector<int> dataToTest;
    vector<int> expected;
    chrono::duration<double> duration;
    string compareResult = "";

/*#pragma region TestingBubbleSort
    PrepareToTest(VectorSize, dataToTest, expected);
    cout << "Testing Bubble Sorting Method." << endl;
    duration = MeasureSortingTime(BubbleSort::Sort, dataToTest);
    compareResult = Compare(expected, dataToTest);
    cout << "Sorting lasts " << duration.count() << " and " << compareResult << "\n\n";
#pragma endregion */

/*#pragma region TestingInsertionSort
    PrepareToTest(VectorSize, dataToTest, expected);
    cout << "Testing Insertion Sorting Method." << endl;
    duration = MeasureSortingTime(InsertionSort::Sort, dataToTest);
    compareResult = Compare(expected, dataToTest);
    cout << "Sorting lasts " << duration.count() << " and " << compareResult << "\n\n";
#pragma endregion */

/*#pragma region TestingSelectionSort
    PrepareToTest(VectorSize, dataToTest, expected);
    cout << "Testing Selection Sorting Method." << endl;
    duration = MeasureSortingTime(SelectionSort::Sort, dataToTest);
    compareResult = Compare(expected, dataToTest);
    cout << "Sorting lasts " << duration.count() << " and " << compareResult << "\n\n";
#pragma endregion */

#pragma region TestingQuickSort
    PrepareToTest(VectorSize, dataToTest, expected);
    cout << "Testing Quick Sorting Method." << endl;
    duration = MeasureSortingTime(QuickSort::Sort, dataToTest);
    compareResult = Compare(expected, dataToTest);
    cout << "Sorting lasts " << duration.count() << " and " << compareResult << "\n\n";
#pragma endregion

#pragma region TestingCountingSort
    PrepareToTest(1000, dataToTest, expected);
    cout << "Testing Counting Sorting Method." << endl;
    duration = MeasureSortingTime(CountingSort::Sort, dataToTest);
    compareResult = Compare(expected, dataToTest);
    cout << "Sorting lasts " << duration.count() << " and " << compareResult << "\n\n";
#pragma endregion

#pragma region TestingMergeSort
    PrepareToTest(VectorSize, dataToTest, expected);
    cout << "Testing Merge Sorting Method." << endl;
    duration = MeasureSortingTime(MergeSort::Sort, dataToTest);
    compareResult = Compare(expected, dataToTest);
    cout << "Sorting lasts " << duration.count() << " and " << compareResult << "\n\n";
#pragma endregion
}