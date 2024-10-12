#include "CountingSort.h"
#include "vector"

using namespace std;

void CountingSort::Sort(vector<int>& data) {
    int DataLenght = data.size();
    int Counter[1000] = { 0 };


    for (int i = 0; i < DataLenght; i++) {
        Counter[data[i]]++;
    }

    int pointer = 0;
    for (int i = 0; i < 1000; i++)
        while (Counter[i] != 0)
        {
            data[pointer] = i;
            pointer++;
            Counter[i]--;
        };
}