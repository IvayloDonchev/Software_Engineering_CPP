//�������������� �� move semantics ��� rvalue reference
#include <cstring>
#include <iostream>
using namespace std;

class mystring {
	char* buffer;
public:
	mystring():buffer(nullptr)	//default constructor;
	{
		cout << this << " default constructor...\n";
	}

	mystring(const char* b):buffer(new char[strlen(b)+1]) //constructor
	{
		strcpy_s(buffer, strlen(b)+1, b);
		cout << this << " constructor...\n";
	}

	~mystring()	//destructor
	{
		cout << this << " destructor...\n";
		if(buffer) delete [] buffer;
	}
		
	mystring(const mystring& other):
		buffer(const_cast<mystring&>(other).buffer) //move version of copy constructor
	{
		const_cast<mystring&>(other).buffer = nullptr;
		cout << this << " move constructor...\n";
	}

	mystring& operator=(const mystring& other) // move version of copy assignment
	{
		if(this == &other) return *this;
		if(buffer) delete [] buffer;
		buffer = const_cast<mystring&>(other).buffer;
		const_cast<mystring&>(other).buffer = nullptr;
		cout << this << " move operator = " << endl;
		return *this;
	}

	void disp() const {
		cout << buffer << endl;
	}
};

int main()
{
	mystring ms1("Ivan Ivanov"); //����������� � ���������
	ms1 = "Petar Petrov"; //������� �������� �����, ����� ����� ��������� �� ms1.
	ms1.disp();			  //������ "Petar Petrov" � �� ��� char*, � �� mystring!	
	cout << endl;

	mystring ms2(ms1);	//��������� �� ���������� �����������
	ms2.disp();

	ms1.disp();		//���! ms1 ���� �� ����

}
//���������� �� ���� ���������� �, �� ����� copy semantics