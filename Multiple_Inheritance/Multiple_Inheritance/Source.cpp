// Multiple inheritance.

#include <iostream>
using namespace std;

class Horse {		//кон
public:
	Horse() { cout << "Horse constructor... "; }
	virtual ~Horse() { cout << "Horse destructor... "; }	//виртуален деструктор
	virtual void Whinny() const { cout << "Whinny!... "; }	//леко цвилене
private:
	int itsAge;
};

class Bird {		//птица
public:
	Bird() { cout << "Bird constructor... "; }
	virtual ~Bird() { cout << "Bird destructor... "; }		//виртуален деструктор
	virtual void Chirp() const { cout << "Chirp... "; }	    //чурулика
	virtual void Fly() const {								//лети
		cout << "I can fly! I can fly! I can fly! ";
	}
private:
	int itsWeight;
};

class Pegasus : public Horse, public Bird {
public:
	void Chirp() const { Whinny(); }
	Pegasus() { cout << "Pegasus constructor... "; }
	~Pegasus() { cout << "Pegasus destructor...  "; }
};

const int MagicNumber = 2;

int main()
{
	Horse* Ranch[MagicNumber];	//ранчо
	Bird* Aviary[MagicNumber];	//птичарник
	Horse* pHorse;
	Bird* pBird;
	int choice, i;
	for (i = 0; i<MagicNumber; i++)
	{
		cout << "\n(1)Horse (2)Pegasus: ";
		cin >> choice;
		if (choice == 2)
			pHorse = new Pegasus;
		else
			pHorse = new Horse;
		Ranch[i] = pHorse;
	}
	for (i = 0; i<MagicNumber; i++)
	{
		cout << "\n(1)Bird (2)Pegasus: ";
		cin >> choice;
		if (choice == 2)
			pBird = new Pegasus;
		else
			pBird = new Bird;
		Aviary[i] = pBird;
	}

	cout << "\n";
	for (i = 0; i<MagicNumber; i++)
	{
		cout << "\nRanch[" << i << "]: ";
		Ranch[i]->Whinny();
		delete Ranch[i];
	}

	for (i = 0; i<MagicNumber; i++)
	{
		cout << "\nAviary[" << i << "]: ";
		Aviary[i]->Chirp();
		Aviary[i]->Fly();
		delete Aviary[i];
	}

	system("pause");

}
