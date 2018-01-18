#include <initializer_list>
#include <iostream>
using namespace std;

class Container {
	int buf[100];
	size_t n;
public:
	Container() :n(0) {}
	Container(initializer_list<int> l) {
		size_t i = 0;
		/*for (initializer_list<int>::iterator x = l.begin(); x != l.end(); ++x)
		buf[i++] = *x;*/
		for (auto x : l) buf[i++] = x;
		n = i;
	}
	friend ostream& operator <<(ostream& out, const Container& c) {
		for (size_t i = 0; i < c.n; ++i)
			out << c.buf[i] << ' ';
		out << '(' << c.n << ")\n";
		return out;
	}
};


int main() {
	Container List{ 1, 3, 5, 6, 3, 2, 3 };
	cout << List << endl;
	Container l2{ 1,2,3 };

	system("pause");
}