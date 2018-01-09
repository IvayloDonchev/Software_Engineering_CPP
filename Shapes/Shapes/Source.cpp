#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <exception>
using namespace std;

class Shape {     //abstract class
public:
	virtual double area() = 0; //pure virtual method
	virtual void disp() = 0;   //pure virtual method
};

class Triangle : public Shape {
	double a, b, c;
public:
	Triangle(double s1, double s2, double s3) :
		a(s1), b(s2), c(s3) {
		if ((a <= 0.0) || (b <= 0.0) || (c <= 0.0) ||
			(a + b <= c) || (a + c <= b) || (b + c <= a))
			throw out_of_range("false triangle");
	}
	double area() override {
		double p = (a + b + c) / 2.0;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}
	void disp() override {
		cout << "Triangle ";
		cout << "sides: " << a << ", " << b << ", " << c << endl;
		cout << "area= " << area() << endl;
	}
};

class Rectangle : public Shape {
	double a, b;
public:
	Rectangle(double s1, double s2) : a(s1), b(s2) {
		if ((a <= 0) || (b <= 0))
			throw out_of_range("false rectangle");
	}
	double area() override { return a * b; }
	void disp() override {
		cout << "Rectangle ";
		cout << "sides " << a << ", " << b << endl;
		cout << "area= " << area() << endl;
	}
};

class Circle : public Shape {
	double radius;
public:
	Circle(double r) :radius(r) {
		if (r <= 0) throw out_of_range("false circle");
	}
	double area() override { return M_PI * radius * radius; }
	void disp() override {
		cout << "Circle ";
		cout << "radius= " << radius << endl;
		cout << "area= " << area() << endl;
	}
};

void func(Shape& sh)
{
	sh.disp();
}

int main()
{
	//int i;
	//cout << "i= "; cin >> i;
	//const int n=i*5;		// !!! constant variable
	//cout << "n= " << n << endl;

	try {
		Triangle t(3, 4, 5);
		Rectangle s(2, 2);
		Circle c(1);
		func(t);
		func(s);
		func(c);

		cout << "------------------------------\n";
		Shape* sp = nullptr;
		sp = &t;
		cout << sp->area() << endl;
		sp = &s;
		cout << sp->area() << endl;
		sp = &c;
		cout << sp->area() << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return 0;
	}

	system("pause");
}


