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
	Derived obj1; //����� �� ����������� ����
	Base obj2;	  //����� �� ������� ����	
	Base* bp;     //�������� ��� ������� ����
	bp = &obj1;   //���� ����� �� �����������
	cout << "The type of bp is " << typeid(bp).name() << endl;
	bp->message1(); //������ �� ����������� ����
	bp->message2(); //������ �� ������� ����
	bp->message3(); //������ �� ������� ����

	bp = &obj2;		//���� ����� �� �������
	bp->message1();	//������ �� ������� ����
	bp->message2();	//������ �� ������� ����
	bp->message3();	//������ �� ������� ����

	cout << endl;
	foo(obj1); // � ����� �� �����������

	system("pause");
}
