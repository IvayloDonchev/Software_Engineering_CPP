#pragma once
class Person
{
private:
	char* name;
	char* address;
	int year;
public:
	Person();
	Person(char*, char*, int);
	~Person();
	void Show();
};

