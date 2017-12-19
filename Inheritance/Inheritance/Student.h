#pragma once
#include "Person.h"
class Student :
	public Person
{
public:
	Student();
	Student(const char*, const char*, int, const char*, int, const char*);
	virtual ~Student();
private:
	char *program;
	int semester;
	char *fak_num;
	friend std::ostream& operator << (std::ostream&, const Student&);
};

