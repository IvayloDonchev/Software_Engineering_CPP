#include <iostream>
#include <vector>
#include <algorithm>	//for_each
using namespace std;

int main()
{
	int mas[10]{ 1,2,3,4,5 };
	
	for (size_t i = 0; i < sizeof(mas)/sizeof(mas[0]); i++)
		cout << mas[i] << " ";
	cout << endl;
	
	for (auto x : mas)
		cout << x << " ";
	cout << endl;

	for (auto i = begin(mas); i != end(mas); ++i)
		cout << *i << " ";
	cout << endl;

	for_each(begin(mas), end(mas), [](auto x) {
		cout << x << " "; });
	cout << endl;

	system("pause");
}