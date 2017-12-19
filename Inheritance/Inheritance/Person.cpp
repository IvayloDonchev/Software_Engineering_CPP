#include "Person.h"

Person::Person(const char *n, const char *a, int y)
{
	size_t len = strlen(n) + 1;
	name = new char[len];
	strcpy_s(name, len, n);
	len = strlen(a) + 1;
	address = new char[len];
	strcpy_s(address, len, a);
	year = y;
}

Person::Person(const Person &other)
{
	size_t len = strlen(other.name) + 1;
	name = new char[len];
	strcpy_s(name, len, other.name);
	len = strlen(other.address) + 1;
	address = new char[len];
	strcpy_s(address, len, other.address);
	year = other.year;
}

Person::~Person()
{
	if (name) delete[] name;
	if (address) delete[] address;
}

Person & Person::operator=(const Person &other)
{
	if (this == &other) return *this;	// self assignment
	size_t len = strlen(other.name) + 1;
	if (name) delete[] name;
	name = new char[len];
	strcpy_s(name, len, other.name);
	len = strlen(other.address) + 1;
	if (address) delete[] address;
	address = new char[len];
	strcpy_s(address, len, other.address);
	year = other.year;
	return *this;
}

Person::Person(Person &&other):
	name(std::move(other.name)),
	address(std::move(other.address)),
	year(std::move(other.year))
{
	other.name = nullptr;
	other.address = nullptr;
	other.year = 0;
}

Person & Person::operator=(Person &&other)
{
	if (this == &other) return *this;
	if (name) delete[] name;
	if (address) delete[] address;
	name = std::move(other.name);
	address = std::move(other.address);
	year = std::move(other.year);
	other.name = nullptr;
	other.address = nullptr;
	other.year = 0;
	return *this;
}

std::ostream & operator<<(std::ostream &out, const Person &p)
{
	out << p.name << ", " << p.address << ", " << p.year;
	return out;
}
