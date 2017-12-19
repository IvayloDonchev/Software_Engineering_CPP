#include <iostream>
#include "Person.h"
#include "Student.h"
using namespace std;

int main()
{
	Person p1("Ivan", "V.T.", 1999);
	cout << p1 << endl;
	Person p2{ p1 };		// copy constructor
	cout << "p2: " << p2 << endl;
	Person p3;				// default constructor
	p3 = p1;				// copy assignment
	Person p4{ move(p1) };  // move constructor
	cout << "p4: " << p4 << endl;
	//cout << "p1: " << p1 << endl;  //error! p1 is deleted
	p4 = move(p2);	//move assignment
	cout << "p4: " << p4 << endl;

	Student s1{ "Ivan Ivanov", "Varna", 1990, "Informatics", 4, "18111" };
	cout << endl << s1 << endl;
	system("pause");

}