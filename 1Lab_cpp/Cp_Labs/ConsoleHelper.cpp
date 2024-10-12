#include "ConsoleHelper.h"
#include "iostream"
#include "sstream"
#include "vector"

using namespace std;

std::vector<int> ConsoleHelper::InitializeVectorConsole() {

	ostringstream oss;

	string callback = "";

	std::vector<int> data;
	int DataLenght;

	cout << "Enter lenght of array." << endl;
	cin >> DataLenght;

	for (int i = 0; i < DataLenght; ++i)
	{
		int x;
		x = rand()%1000;
		data.push_back(x); // заполняем вектор
	}
	for (int i = 0; i < data.size(); ++i)
	{
		oss << data[i] << " ";
	}
	callback = oss.str();

	return data;
}
