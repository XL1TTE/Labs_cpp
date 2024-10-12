#pragma once
#include "vector"

class MergeSort
{
public:
	static void Sort(std::vector<int>& data);
private:
	static void Merge(std::vector<int>& data, std::vector<int>& left, std::vector<int>& right);
};

