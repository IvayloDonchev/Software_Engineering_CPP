#include "Student.h"



Student::Student() : Person(), 
	program(nullptr), semester(0), fak_num(nullptr)
{}

Student::Student(const char *n, const char *a, int y, const char *p, int s, const char *f):
	Person(n,a,y)
{
	size_t len = strlen(p) + 1;
	program = new char[len];
	strcpy_s(program, len, p);
	semester = s;
	len = strlen(f) + 1;
	fak_num = new char[len];
	strcpy_s(fak_num, len, f);
}


Student::~Student()
{
	if (program) delete[] program;
	if (fak_num) delete[] fak_num;
}

std::ostream& operator << (std::ostream& out, const Student& s)
{
	out << static_cast<Person>(s) << std::endl;
	out << "Faculty number: " << std::endl;
	out << "Program: " << s.program << std::endl;
	out << "Semester: " << s.semester << std::endl;
	return out;
}