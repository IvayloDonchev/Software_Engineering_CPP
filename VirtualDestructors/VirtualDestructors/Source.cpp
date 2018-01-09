// Виртуални деструктори
#include <iostream>
using namespace std;

class Base {
public:
	Base() { cout << "Base default constructor\n"; }
	Base(int) { cout << "Base constructor\n"; }
	virtual ~Base() { cout << "Base destructor\n"; }
};

class Derived : public Base {
public:
	Derived() { cout << "Derived default constructor\n"; }
	Derived(int x) :Base(x) { cout << "Derived constructor\n"; }
	~Derived() { cout << "Derived destructor\n"; }
};

void foo(Base& br)
{
	return;
}

int main()
{
	Base* bp;
	bp = new Derived(5);
	delete bp;

	cout << endl;
	Derived d(5);
	foo(d);


}