#include <iostream>
#include <exception>
using namespace std;

class MyClass {
public:
	MyClass() = default;
	~MyClass() {
		cout << "MyClass destruction...\n";
	}
};

int main()
{
	/*int* p = new int[5];
	p[4] = 7;
	p[6] = 10;
	p[-3] = 15;*/

	//double *p{ new double(2.5) };
	//cout << p << ", " << *p << endl;
	//delete p;
	//cout << p << endl;
	//cout << *p << endl;	//null pointer dereferencing

	void* vp;
	vp = new double;
	cout << "Enter double: ";
	cin >> *static_cast<double*>(vp);
	cout << *(double*)vp << endl;
	delete (double*) vp;

	vp = new MyClass;
	// delete vp;	// Неправилно освобождаване на паметта
	delete (MyClass*)vp;	// Коректно - ще се изпълни деструкторът на MyClass

	vp = new int[5];
	cout << "Enter 5 integers: ";
	for (int i = 0; i < 5; i++)
		cin >> *(static_cast<int*>(vp) + i);
	for (int i = 0; i < 5; i++)
		cout << static_cast<int*>(vp)[i] << ' ';
	cout << endl;
	delete [] (int*)vp;

	system("pause");
}