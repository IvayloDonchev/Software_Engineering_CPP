#include <iostream>
using namespace std;

class C {
public:
	int data;
	C(int a) : data(a) {}
	C() :data(0) {}
	void disp() { cout << "C.data= " << data << endl; }
};

class B1 : virtual public C {
public:
	B1() :C() {}
	B1(int a) :C(a) {}
	void disp() { cout << "B1.data= " << data << endl; }
};

class B2 : virtual public C {
public:
	B2() :C() {}
	B2(int a) :C(a) {}
	void disp() { cout << "B2.data= " << data << endl; }
};

class D : public B1, public B2 {
public:
	D() : C(), B1(), B2() {}
	D(int a) : C(a), B1(a), B2(a) {}
	D(int a, int b) :B1(a), B2(b) {}
	void disp() {
		cout << "D.data= " << data << endl;

	}
};

int main()
{
	D d(10);
	d.disp();

	system("pause");
}


