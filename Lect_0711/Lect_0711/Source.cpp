#include <iostream>
#include <exception>
#include <ctime>
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
	/*int *p;
	p = new int;
	*p = 10;
	int *q = new int(20);
	int n;
	cout << "n = "; cin >> n;
	double *dp = new double[n];
	dp[0] = 2.34;
	dp[1] = dp[0] * 2 + 1;*/


	/*int* p{ new int[5] };
	p[4] = 7;
	p[6] = 10;
	p[-3] = 15;

	int *p1 = new int[500];
	int *p2 = new int;
	p1[200] = 10;
	p1 = p2;
	int x = p1[200];
	cout << "x = " << x << endl;
	double *p=nullptr;  
	if(p)
		*p = 3.5;
	cout << *p << endl;
*/

//--------------------------------------------------------------------------
	//double *p{ new double(2.5) };
	//cout << p << ", " << *p << endl;
	//delete p;
	//cout << p << endl;
	//cout << *p << endl;	//null pointer dereferencing
//--------------------------------------------------------------------------
	////���������� �� void* �� ������ �� �������� ������ ������
	//void* vp;
	//vp = new double;
	//cout << "Enter double: ";
	//cin >> *static_cast<double*>(vp);
	//cout << *(double*)vp << endl;
	//delete (double*) vp;

	//vp = new MyClass;
	//// delete vp;	// ���������� ������������� �� �������
	//delete (MyClass*)vp;	// �������� - �� �� ������� ������������ �� MyClass

	//vp = new int[5];
	//cout << "Enter 5 integers: ";
	//for (int i = 0; i < 5; i++)
	//	cin >> *(static_cast<int*>(vp) + i);
	//for (int i = 0; i < 5; i++)
	//	cout << static_cast<int*>(vp)[i] << ' ';
	//cout << endl;
	//delete [] (int*)vp;

	//vp = new MyClass[10];
	////delete (MyClass*) vp;	// �� �������� ������� ���� �� ������ ����� (� ���� �� �����)
	//delete[](MyClass*) vp;	// �������� - �� �������� ������� �� 10 ������
	//MyClass* mp = new MyClass[5]; // ������ ���� �������� ��� �����
	//cout << "--------------- MyClass pointer ---------------\n";
	//delete[] mp;

//-----------------------------------------------------------------------
	//// ����������
	//int x = 10, y = 100;
	//int &rx = x;
	//cout << "x =  " << x << endl;
	//x = 30;
	//cout << "rx = " << rx << endl;
	////�������� �� ����� ���������� ��������
	//cout << "&rx = " << &rx << endl;
	//cout << "&x  = " << &x << endl;

	////rx = &y;	// ������ - ��������� �� ���� �� �� ������ � ����� ����������
	////int &ry;    // ������ - ����������� �� � �������������
	////reinterpret_cast<int*>(&rx) = &y; // ����� ������ ����
	//const int& cr = 25;	//��������� �� ������ �������
	////cr = 30;	// ������ (����������� � ����������)
	//const_cast<int&>(cr) = 30;  // ���� �����, �� ��� ��-��������� �����
	//cout << "cr = " << cr << endl;

	////����� ����������
	//int && rr = 20;	//����� ��������� �� �������� �������;
	//cout << "rr = " << rr << endl;
	//cout << "&rr = " << &rr << endl;
	//rr = 30;
	//cout << "rr = " << rr << endl;
	//cout << "&rr = " << &rr << endl; //�� ������ �����, ������ ����� ���� ���� ��������� 20
	
//.................................................................................
	////������: ��������� ����� � ����������
	//int *p{ new int[5] };
	//int *q{ nullptr };
	//int x{ 0 }, n{ 0 }, m{ 0 };
	////��������� �� �����, ������ �� ������ 0
	//cout << ">> "; cin >> x;
	//while (x != 0)
	//{
	//	if (m >= 5)
	//	{
	//		m = 0;
	//		q = new int[n + 5];
	//		memmove(q, p, n * sizeof(int));
	//		delete[] p;
	//		p = q;
	//	}
	//	p[n++] = x;
	//	++m;
	//	cout << ">> "; cin >> x;
	//}
	////��������� �� �������
	//for (int i = 0; i < n; i++)
	//	cout << p[i] << ' ';
	//cout << endl;
	//delete[] p;
	//
//----------------------------------------------------------------------------
	//�������� ����� ���� ����� ��������
	int m, n;
	int **matr;
	cout << "rows: "; cin >> m;
	cout << "columns: "; cin >> n;
	//�������� �� �����
	matr = new int*[m];
	for (int i = 0; i < m; i++)
		matr[i] = new int[n];
	//��������� ��� �������� �����
	srand((unsigned)time(0));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			matr[i][j] = rand() % 10; 
	//��������� ��� ��� �� �������
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matr[i][j] << '\t';
		cout << endl;
	}
	cout << endl;
	//���������� �� �� ����������� �������������� � �������
	int *p = reinterpret_cast<int*>(matr[0]);
	for (int i = 0; i < m*n; i++)
		cout << p[i] << ' ';
	cout << endl;
	for (int i = 0; i < m - 1; i++)
		cout << "matr[" << i + 1 << "] - matr[" << i << "] = "
		<< (matr[i + 1] - matr[i]) << endl;
	cout << "(must be " << n * sizeof(int) << ")\n";
	//������������� �� �������
	for (int i = 0; i < m; i++)
		delete [] matr[i];
	delete [] matr;

	system("pause");
}