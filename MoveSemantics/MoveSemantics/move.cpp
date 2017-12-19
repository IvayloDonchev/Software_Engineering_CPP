#include <iostream>
#include <cstring>
#include <array>
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
		
	mystring(const mystring& other):		//copy constructor
		buffer(new char[strlen(other.buffer)+1]) 
	{
		strcpy_s(buffer, strlen(other.buffer)+1, other.buffer);
		cout << this << " copy constructor...\n";
	}

	mystring& operator=(const mystring& other) // copy assignment
	{
		if (this == &other) return *this; //self-assignment
		if (buffer) delete[] buffer;
		size_t n = strlen(other.buffer) + 1;
		buffer = new char[n];
		strcpy_s(buffer, n, other.buffer);
		cout << this << " copy assignment...\n";
		return *this; //връща обекта вляво на знака =
	}

	mystring(mystring&& other):buffer(move(other.buffer)) //move constructor
	{
		other.buffer=nullptr;
		cout << this << " move constructor...\n";
	}
	
	mystring& operator=(mystring&& other) //move assignment
	{
		if(this == &other) return *this;
		if(buffer) delete [] buffer;
		buffer = move(other.buffer);
		other.buffer=nullptr;
		cout << this << " move assignment...\n";
		return *this;
	}

	operator char*()			//преобразува до char*
	{
		return buffer;
	}	

	void disp() const {
		cout << buffer << endl;
	}

	mystring& cat(const mystring& s2){	//конкатенация
		size_t len = strlen(buffer) + strlen(s2.buffer) + 1;
		char* tmp = new char[len];
		strcpy_s(tmp, strlen(buffer)+1, buffer);
		strcpy_s(tmp+strlen(buffer), strlen(s2.buffer)+1, s2.buffer);
		delete [] buffer;
		buffer = tmp;
		return *this;
	}

	mystring& operator +(const mystring& s2){	//конкатенация с операция +
		size_t len = strlen(buffer) + strlen(s2.buffer) + 1;
		char* tmp = new char[len];
		strcpy_s(tmp, strlen(buffer)+1, buffer);
		strcpy_s(tmp+strlen(buffer), strlen(s2.buffer)+1, s2.buffer);
		delete [] buffer;
		buffer = tmp;
		return *this;
	}

	friend ostream& operator <<(ostream& out, const mystring& s)	//това не е мотод на класа!
	{
		out << s.buffer;
		return out;
	}
};

void my_swap(mystring& a, mystring& b)
{
	mystring t = move(a);			//move constructor
	a = move(b);					//move assignment
	b = move(t);					//move assignment
}

int main()
{
	mystring c1{ "Ivan Ivanov" };		//constructor
	mystring c2{ "Peter Georgiev" };	//constructor
	//cout << c1.cat(c2) << endl;
	cout << c1 + ", " + c2 << endl;
	my_swap(c1,c2);
	cout << "c1= " << c1 << endl;
	cout << "c2= " << c2 << endl;

	mystring* pc=&c1;				//тук не се изпълнява никакъв конструктор!
	cout << "*pc= " << *pc << endl;

	mystring c3(c1);				//copy constructor;
	mystring c4(move(c1));			//move constructor;
	mystring c5=mystring("demo");	//constructor;
	c5 = c4;						//copy assignment;
	cout << "c5= " << c5 << endl;	//Peter Georgiev
	c5 = move(c2);					//move assignment. c2 вече го няма!
	cout << "c5= " << c5 << endl;	//Ivan Ivanov
	//cout << "c2= " << c2 << endl;	//Runtime error! Ресурсите на обекта c2 са прехвърлени на c5
	std::swap(c3,c4);				//библиотечната функция също използва предимствата на move semantics
	
	cout << "-------------------------\n";
	array<mystring, 3> v {mystring("one"), mystring("two"), mystring("three")}; //uniform initialization (още не работи с всички контейнери)
	for(auto& x:v)					//range based for loop
		cout << x << " ";
	cout << endl;

	char *cs;
	mystring ms = "Proba";
	cout << "ms= " << ms << endl;
	cs = ms;	//това работи благодарение на оператора за преобразуване до char*
	cout << "cs= " << cs << endl;

	system("pause");
}



