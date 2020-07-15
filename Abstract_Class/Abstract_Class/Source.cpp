#include <iostream>
using namespace std;

class Pet {		//абстрактен клас
public:
	virtual void sound() const = 0; //чист виртуален метод
};

class Dog : public Pet {
public:
	void sound() const override {
		cout << "bowwow!\n";
	}
};

class Cat : public Pet {
public:
	void sound() const override {
		cout << "miaou!\n";
	}
};

void foo(Pet& p) //ф-я с параметър псевдоним на абстр. клас
{
	p.sound();
}


int main()
{
	const int n = 5;
	Pet* mas[n];		//масив от указатели към абстрактния клас
	mas[0] = new Cat;
	mas[1] = new Dog;
	mas[2] = new Dog;
	mas[3] = new Cat;
	mas[4] = new Dog;
	for (int i = 0; i<n; ++i)
		mas[i]->sound(); // тук се активира полиморфичното действие
	cout << endl << endl;
	foo(*mas[0]);
	Dog d;
	foo(d);

	system("pause");
}
