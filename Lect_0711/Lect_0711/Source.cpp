#include <iostream>
#include <exception>
using namespace std;

class MyClass {
public:
	MyClass() = default;
	~MyClass() {
		cout << "MyClass destruction...\n";
	}
};

int main()
{
	/*int* p = new int[5];
	p[4] = 7;
	p[6] = 10;
	p[-3] = 15;*/
//--------------------------------------------------------------------------
	/*double *p{ new double(2.5) };
	cout << p << ", " << *p << endl;
	delete p;
	cout << p << endl;
	cout << *p << endl;	//null pointer dereferencing*/
//--------------------------------------------------------------------------
	//���������� �� void* �� ������ �� �������� ������ ������
/*	void* vp;
	vp = new double;
	cout << "Enter double: ";
	cin >> *static_cast<double*>(vp);
	cout << *(double*)vp << endl;
	delete (double*) vp;

	vp = new MyClass;
	// delete vp;	// ���������� ������������� �� �������
	delete (MyClass*)vp;	// �������� - �� �� ������� ������������ �� MyClass

	vp = new int[5];
	cout << "Enter 5 integers: ";
	for (int i = 0; i < 5; i++)
		cin >> *(static_cast<int*>(vp) + i);
	for (int i = 0; i < 5; i++)
		cout << static_cast<int*>(vp)[i] << ' ';
	cout << endl;
	delete [] (int*)vp;

	vp = new MyClass[10];
	//delete (MyClass*) vp;	// �� �������� ������� ���� �� ������ ����� (� ���� �� �����)
	delete[](MyClass*) vp;	// �������� - �� �������� ������� �� 10 ������
	MyClass* mp = new MyClass[5]; // ������ ���� �������� ��� �����
	cout << "--------------- MyClass pointer ---------------\n";
	delete[] mp;
	*/
//-----------------------------------------------------------------------
/*	// ����������
	int x = 10, y = 100;
	int &rx = x;
	cout << "x =  " << x << endl;
	x = 30;
	cout << "rx = " << rx << endl;
	//�������� �� ����� ���������� ��������
	cout << "&rx = " << &rx << endl;
	cout << "&x  = " << &x << endl;

	//rx = &y;	// ������ - ��������� �� ���� �� �� ������ � ����� ����������
	//int &ry;    // ������ - ����������� �� � �������������
	//reinterpret_cast<int*>(&rx) = &y; // ����� ������ ����
	const int& cr = 25;	//��������� �� ������ �������
	//cr = 30;	// ������ (����������� � ����������)
	const_cast<int&>(cr) = 30;  // ���� �����, �� ��� ��-��������� �����
	cout << "cr = " << cr << endl;

	//����� ����������
	int && rr = 20;	//����� ��������� �� �������� �������;
	cout << "rr = " << rr << endl;
	cout << "&rr = " << &rr << endl;
	rr = 30;
	cout << "rr = " << rr << endl;
	cout << "&rr = " << &rr << endl; //�� ������ �����, ������ ����� ���� ���� ��������� 20
	*/
//.................................................................................
/*	//������: ��������� ����� � ����������
	int *p{ new int[5] };
	int *q{ nullptr };
	int x{ 0 }, n{ 0 }, m{ 0 };
	//��������� �� �����, ������ �� ������ 0
	cout << ">> "; cin >> x;
	while (x != 0)
	{
		if (m <= 5)
		{
			m = 0;
			q = new int[n + 5];
			memmove(q, p, n * sizeof(int));
			delete[] p;
			p = q;
		}
		p[n++] = x;
		++m;
		cout << ">> "; cin >> x;
	}
	//��������� �� �������
	for (int i = 0; i < n; i++)
		cout << p[i] << ' ';
	cout << endl;
	delete[] p;
	*/
	system("pause");
}