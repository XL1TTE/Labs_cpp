#include <iostream>
#include "List.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    {
        List<int> my_list = List<int>();
        my_list.PushBack(10);

        my_list[0] = 5;


        cout << my_list.GetByIndex(0) << endl;
        my_list.PushFront(19);
        cout << my_list.GetFirst() << endl;
        cout << my_list.GetLast() << endl;
        cout << my_list.Size() << endl;
        my_list.PushBack(10);
        cout << my_list.GetLast() << endl;
        my_list.RemoveLast();

        srand(time(0));
        for (int i = 0; i < 5; i++) {
            my_list.PushBack(rand() % 100);
        }
        cout << endl << "Iteration Testing" << endl;
        int index = 0;
        for (auto it = my_list.begin(); it != my_list.end(); ++it) {
            cout << index << ". " << *it << endl;
            index++;
        }

        my_list.Insert(100, 0);
        my_list.Insert(-100, 5);

        index = 0;
        cout << endl << "Insertion Testing" << endl;
        for (auto it = my_list.begin(); it != my_list.end(); ++it) {
            cout << index << ". " << *it << endl;
            index++;
        }
    } 

    _CrtDumpMemoryLeaks();
    
}
