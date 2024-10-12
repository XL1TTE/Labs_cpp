#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "CountingSort.h"
#include "ConsoleHelper.h"
#include "SortsTester.h"
#include <iostream>
#include "vector"
#include <random>
#include "fstream"

int main()
{

    srand(time(0));


    std::ofstream fcout("output.txt");

#pragma region BubbleSort
    SortsTester::Test(1000000);
#pragma endregion




}
