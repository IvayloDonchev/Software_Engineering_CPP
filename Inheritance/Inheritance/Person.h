#pragma once
#include <iostream>
class Person
{
public:
	Person() : name(nullptr), address(nullptr), year(0) {}
	Person(const char*, const char*, int);
	~Person();					// virtual destructor
	Person(const Person&);				// copy constructor
	Person& operator=(const Person&);	// copy assignment
	//move semantics
	Person(Person&&);					// move constructor
	Person& operator=(Person&&);		// move assignment
private:
	char *name;
	char *address;
	int year;
	friend std::ostream& operator <<(std::ostream&, const Person&);
};

