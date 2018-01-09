#include <iostream>
#include <initializer_list>
using namespace std;

template <typename T>
class Queue {
private:
	struct Node {
		T key;
		Node* next;
	public:
		Node() : key(), next(nullptr) {}
		Node(T x) : key(x), next(nullptr) {}
	};
	Node* top;
	Node* bottom;
public:
	//construction and destruction
	Queue() : top(nullptr), bottom(nullptr) {}
	Queue(T x) : top(x) { bottom = top; }
	Queue(initializer_list<T>);
	~Queue();
	//copy semantics
	Queue(const Queue&);
	Queue& operator = (const Queue&);
	//move semantics
	Queue(Queue&&);
	Queue& operator = (Queue&&);
	//operations
	bool put(T);
	bool get(T&);
	friend ostream& operator << (ostream& out, const Queue<T>& q)
	{
		for (auto p = q.top; p != nullptr; p = p->next)
			out << p->key << " ";
		return out;
	}
};

template <typename T>
Queue<T>::Queue(initializer_list<T> args)
{
	for (auto x : args)
		put(x);
}

template <typename T>
Queue<T>::~Queue()
{
	while (top)
	{
		Node* p = top;
		top = top->next;
		delete p;
	}
}

template <typename T>
Queue<T>::Queue(const Queue& other) : top(new Node(other.top->key)), bottom(top)
{
	for (auto p = other.top->next; p; p = p->next)
		put(p->key);
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	if (this == &other) return *this;
	this->~Queue();
	for (auto p = other.top; p; p = p->next)
		put(p->key);
	return *this;
}

template <typename T>
Queue<T>::Queue(Queue&& other) : top(move(other.top)), bottom(move(other.bottom))
{
	other.top = other.bottom = nullptr;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& other)
{
	if (this == &other) return *this;
	this->~Queue();
	top = move(other.top);
	bottom = move(other.bottom);
	other.top = other.bottom = nullptr;
	return *this;
}

template <typename T>
bool Queue<T>::put(T x)
{
	Node* p = new Node(x);
	if (!p) return false;
	if (!top)
		top = bottom = p;
	else
	{
		bottom->next = p;
		bottom = p;
	}
	return true;
}

template <typename T>
bool Queue<T>::get(T& x)
{
	if (!top) return false;
	Node* p = top;
	x = p->key;
	if (top == bottom)
		bottom = nullptr;
	top = top->next;
	delete p;
	return true;
}

int main()
{
	Queue<int> q;
	for (int i = 1; i <= 20; ++i)
		q.put(i);
	int k;
	Queue<int> q2{ q };	//copy construction
	q2.put(100);
	q = q2;		//copy assignment
	while (q.get(k))
		cout << k << " ";
	cout << endl;
	cout << q2 << endl;
	Queue<double> q3{ 1.25, 2.12, 12.34, 15.51 };
	q3.put(0.123);
	cout << q3 << endl;
	q2.put(200);
	q = move(q2);
	cout << q << endl;

	system("pause");
}