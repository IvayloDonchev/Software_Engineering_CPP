#include <iostream>
#include <array>
#include <algorithm>	//for_each
using namespace std;

int main()
{
	int mas[]{ 1,2,3,4,5 };
	size_t n{ sizeof(mas) / sizeof(mas[0]) };	//���� �� ���������� �� ������

	//��������� ���� ������
	for (size_t i = 0; i < n; i++)
		cout << mas[i] << " ";
	cout << endl;
	
	//��������� � range-based �������� �� �����
	for (auto x : mas)
		cout << x << " ";
	cout << endl;

	//��������� � ��������
	for (auto i = begin(mas); i != end(mas); ++i)
		cout << *i << " ";
	cout << endl;

	//��������� � ���������� for_each � ��������� �� ����� ������� � ������
	for_each(begin(mas), end(mas), [](auto x) {
		cout << x << " "; });
	cout << endl;

	//������, �� � �������� �������� �� �������� � ����
	for_each(mas, mas+n, [](auto x) {
		cout << x << " "; });
	cout << endl;

	
	
	
	double *dp = reinterpret_cast<double*>(&n);
	cout << *(int*)dp << endl;


	auto Length = [](int m[])->size_t {
		return sizeof(m)/sizeof(m[0]); };


	cout << Length(mas) << endl;  // ������ � 1
	system("pause");
}