#include <iostream>
#include <array>
#include <algorithm>	//for_each
using namespace std;

int main()
{
	int mas[]{ 5,10,15,20,25,30,35,40,45,50 };
	size_t n{ sizeof(mas) / sizeof(mas[0]) };	//брой на елементите на масива

	//обхождане чрез индекс
	for (size_t i = 0; i < n; i++)
		cout << mas[i] << " ";
	cout << endl;
	
	//обхождане с range-based оператор за цикъл
	for (auto x : mas)
		cout << x << " ";
	cout << endl;

	//обхождане с итератор
	for (auto i = begin(mas); i != end(mas); ++i)
		cout << *i << " ";
	cout << endl;

	//обхождане с алгоритъма for_each и обработка на всеки елемент с ламбда
	for_each(begin(mas), end(mas), [](auto x) {
		cout << x << " "; });
	cout << endl;

	//същото, но с директно задаване на началото и края
	for_each(mas, mas+n, [](auto x) {
		cout << x << " "; });
	cout << endl;

	int i{ 20 };
	int *ip = &i;
	//dereference operator
	*ip = 50;
	cout << " i = " << i << endl;
	i = 100;
	cout << "*ip = " << *ip << endl;
	cout << "&i = " << &i << endl;
	cout << "ip = " << ip << endl;

	cout << "size of char: " << sizeof(char) << endl;
	cout << "size of int: " << sizeof(int) << endl;
	cout << "size of double: " << sizeof(double) << endl;
	cout << "size of long double: " << sizeof(long double) << endl;
	cout << "size of 'A': " << sizeof('A') << endl;
	cout << "size of (3+20): " << sizeof(3+20) << endl;
	cout << "size of (3*2.5): " << sizeof(3*2.5) << endl;
	cout << "size of ip: " << sizeof(ip) << endl;
	cout << "size of int* " << sizeof(int*) << endl;
	cout << "size of double* " << sizeof(double*) << endl;
	
	int *p1, *p2;
	p1 = &mas[3];
	p2 = &mas[7];
	cout << "p1 = " << p1 << '\t' << "*p1 = " << *p1 << endl;
	cout << "p2 = " << p2 << '\t' << "*p2 = " << *p2 << endl;
	cout << "p1+1 = " << p1 + 1 << '\t' << "*(p1+1) = " << *(p1 + 1) << endl;
	cout << "p1-1 = " << p1 - 1 << '\t' << "*(p1-1) = " << *(p1 - 1) << endl;
	cout << "p2-p1 = " << p2 - p1 << endl;
	p2++;
	cout << "p2 = " << p2 << '\t' << "*p2 = " << *p2 << endl;
	p1 -= 2;
	cout << "p1 = " << p1 << '\t' << "*p1 = " << *p1 << endl;

	/*void *p;
	i = 25;
	double d = 2.5;
	p = &i;
	cout << *static_cast<int*>(p) << endl;
	p = &d;
	cout << *(double*)p << endl;*/

	//int a = 5, b = 7;
	//int* const p = &a;
	//cout << "*p = " << *p << endl;
	////p = &b;
	//*p = 77;
	//cout << "a = " << a << endl;
	//const_cast<int*>(p) = &b;
	//*p = 77;
	//cout << "b = " << b << endl;

	double *dp = reinterpret_cast<double*>(&n);
	cout << *(int*)dp << endl;
	
	auto Length = [](int m[])->size_t {
		return sizeof(m)/sizeof(m[0]); };

	cout << Length(mas) << endl;  // винаги е 1


	int arr[5]{ 6,3,5,1,2 };
	cout << arr[0] << endl;	//6
	cout << *arr << endl;   //6
	cout << arr[1] << endl; //3
	cout << *(arr + 1) << endl; //3 
	int *p;
	p = arr;
	cout << *(p + 2) << endl;	//5
	cout << p[2] << endl;		//5


	system("pause");
}