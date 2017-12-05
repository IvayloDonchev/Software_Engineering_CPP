#include "Person.h"
#include <cstring>
#include <iostream>
using namespace std;



Person::Person() : name(nullptr), 
                   address(nullptr), 
	               year(0)
{}

Person::Person(char *n, char *a, int y)
{
	size_t len = strlen(n) + 1;
	name = new char[len];
	strcpy_s(name, len,n);
	len = strlen(a);
	address = new char[len];
	strcpy_s(address, len, a);
}


Person::~Person()
{
	if (name) delete[] name;
	if (address) delete[] address;
}

void Person::Show()
{
	cout << name << ", " << address << endl;
}
