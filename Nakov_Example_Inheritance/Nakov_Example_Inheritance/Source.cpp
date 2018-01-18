#include <iostream>
#include <string>
#include <algorithm>	//sort()
#include <functional>	//greater<>
using namespace std;

class Human {
private:
	unsigned long id;
	string name;
	string address;
public:
	Human() = default;
	Human(unsigned long i, string n, string a) :
		id(i), name(n), address(a)
	{}
	friend ostream& operator <<(ostream& out, const Human& h)
	{
		out << "id: " << h.id << endl;
		out << "name: " << h.name << endl;
		out << "address: " << h.address << endl;
		return out;
	}
	friend istream& operator >>(istream& i, Human& h)
	{
		cout << "Enter id: "; i >> h.id;
		cout << "Enter name: "; i >> h.name;
		cout << "Enter address: "; i >> h.address;
		return i;
	}
};

class Student : public Human {
private:
	double mark;
public:
	Student() = default;
	Student(unsigned long i, string n, string a, double m) : 
		Human(i, n, a),	mark(m)
	{}
	bool operator <(const Student& other) const
	{
		return mark < other.mark;
	}
	friend ostream& operator <<(ostream& out, const Student& s)
	{
		out << (const Human&)s;
		out << "mark: " << s.mark << endl;
		return out;
	}
	friend istream& operator >>(istream& i, Student& s)
	{
		i >> (Human&)s;
		cout << "Enter mark: ";
		i >> s.mark;
		return i;
	}
};

class Worker : public Human
{
private:
	double wage;
	int hours;
public:
	Worker() = default;
	constexpr double calculateHourlyWadge() const {
		return wage * hours;
	}
	Worker(unsigned long i, string n, string a, double w, int h) :
		Human(i, n, a), wage(w), hours(h)
	{}
	bool operator <(const Worker& other) const {
		return calculateHourlyWadge() < other.calculateHourlyWadge();
	}
	bool operator >(const Worker& other) const {
		return calculateHourlyWadge() > other.calculateHourlyWadge();
	}
	friend istream& operator >>(istream& i, Worker& w)
	{
		i >> (Human&)w;
		cout << "Wage: "; i >> w.wage;
		cout << "Hours: "; i >> w.hours;
		return i;
	}
	friend ostream& operator <<(ostream& out, const Worker& w)
	{
		out << (const Human&)w;
		out << "wage: " << w.wage << endl;
		out << "hours: " << w.hours << endl;
		out << "salary: " << w.calculateHourlyWadge() << endl;
		return out;
	}
};

int main() {
	const size_t N = 2;
	Student group[N];	//array of N students
	for (auto& s : group)
		cin >> s;
	sort(begin(group), end(group));
	for (auto s : group)
		cout << s << "--------------\n";

	cout << endl;
	Worker workers[N];
	for (auto& w : workers)
		cin >> w;
	sort(begin(workers), end(workers), greater<Worker>());
	for (auto w : workers)
		cout << w << "-------------\n";
	cout << endl;

	system("pause");
}
