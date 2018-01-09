#include <iostream>
#include <typeinfo>
using namespace std;

class Base {
public:
	virtual void message1() {
		cout << "Base::message1()\n";
	}
	virtual void message2() {
		cout << "Base::message2()\n";
	}
	void  message3() {
		cout << "Base::message3()\n";
	}
	virtual ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base {
public:
	virtual void message1() {
		cout << "Derived::message1()\n";
	}
	void message2(int x) /*override*/ {
		cout << "x= " << x << endl;
	}
	void message3() {
		cout << "Derived::message3()\n";
	}
	~Derived() { cout << "Derived destructor" << endl; }
};

void foo(Base& b)
{
	b.message1();
	b.message2();
	b.message3();
}

int main() {
	/*Base* bp;
	bp = new Derived();
	bp->message1();
	cout << "The type of bp is " << typeid(bp).name() << endl;
	delete bp;*/
	Derived obj1; //обект на производния клас
	Base obj2;	  //обект на базовия клас	
	Base* bp;     //указател към базовия клас
	bp = &obj1;   //сочи обект на производния
	cout << "The type of bp is " << typeid(bp).name() << endl;
	bp->message1(); //метода от производния клас
	bp->message2(); //метода на базовия клас
	bp->message3(); //метода на базовия клас

	bp = &obj2;		//сочи обект на базовия
	bp->message1();	//метода на базовия клас
	bp->message2();	//метода на базовия клас
	bp->message3();	//метода на базовия клас

	cout << endl;
	foo(obj1); // с обект на производния

	system("pause");
}
