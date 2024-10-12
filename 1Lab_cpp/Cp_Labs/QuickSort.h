#pragma once
#include "vector"

class QuickSort
{

public:
	static void Sort(std::vector<int>& data);

private: 
	static void BuildData(std::vector<int>& data, std::vector<int>& left, std::vector<int>& right, int& separator);


};

