#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
using namespace std;

int main()
{
	//const int n = 10; //брой на оценките
	//double list[n];   //масив, който ще съдържа оценките
	//for (int i = 0; i < n; i++)
	//{
	//	do {
	//		cout << "Evaluation for student # " << i + 1 << ": ";
	//		cin >> list[i];
	//	} while (list[i]<2.0 || list[i]>6.0);

	//}
	//cout << endl << "---- Results ----\n";
	//cout.setf(ios::fixed | ios::showpoint);
	//cout.precision(2);
	//for (int i = 0; i < n; i++)
	//	cout << "Student # " << i + 1 << '\t'
	//	<< " evaluation: " << list[i] << endl;
	//cout << endl;
	//
	//int i = 20;
	//int *pi = &i;
	//cout << "*pi = " << *pi << endl;
	//*pi = 50;
	//cout << "i = " << i << endl;
	//i = 100;
	//cout << "*pi = " << *pi << endl;
	//cout << "pi = " << pi << endl;
	//cout << "&i = " << &i << endl;

	//char ch = 'A';
	//char* chp = &ch;
	//pi = reinterpret_cast<int*>(chp);


	//pi = reinterpret_cast<int*>(0x12FF60);  //OK, но не е добре да се прави

	//// Операция sizeof
	//cout << "size of char = " << sizeof(char) << endl;
	//cout << "size of int = " << sizeof(int) << endl;
	//cout << "size of double = " << sizeof(double) << endl;

	//cout << "sizeof 'A' = " << sizeof('A') << endl;
	//cout << "sizeof (3+20) = " << sizeof(3 + 20) << endl;
	//cout << "sizeof (3*2.5) = " << sizeof(3 * 2.5) << endl;
	//cout << "sizeof pi = " << sizeof(pi) << endl;
	//cout << "sizeof chp = " << sizeof(chp) << endl;

	/*char s[] = "Ivan Ivanov";
	char *p = s;
	char *q = s + 5;
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "q-p = " << q - p << endl;*/

	/*int mas[]{ 5,10,15,20,25,30,35,40,45,50 };
	int *p1, *p2;
	p1 = &mas[3];
	p2 = &mas[7];
	cout << "p1 = " << p1 << '\t' << "*p1 = " << *p1 << endl;
	cout << "p2 = " << p2 << '\t' << "*p2 = " << *p2 << endl;
	cout << "*(p1+1) = " << *(p1 + 1) << endl;
	cout << "*(p1-1) = " << *(p1 - 1) << endl;
	cout << "p2-p1 = " << p2 - p1 << endl;
	p2++;
	cout << "p2 = " << p2 << '\t' << "*p2 = " << *p2 << endl;
	p1 -= 2;
	cout << "p1 = " << p1 << '\t' << "*p1 = " << *p1 << endl;
*/

	//int i = 25;
	//double d = 2.5;
	//void *p;
	//p = &i;	// p сочи данни от тип int
	//cout << *(int*)p << endl;
	//p = &d; // p сочи данни от тип double
	//cout << *static_cast<double*>(p) << endl;

	//int mas[5] = { 6,3,5,1,2 };
	//cout << mas[0] << endl;	    // 6
	//cout << *mas << endl;		// 6
	//cout << mas[1] << endl;		// 3
	//cout << *(mas + 1) << endl;	// 3
	//int *p;
	//p = mas;
	//cout << *(p + 2) << endl;	// 5
	//cout << p[2] << endl;		// 5

	/*int *p;
	p = new int;
	*p = 10;
	int *q = new int(20);
	int n;
	cout << "n = "; cin >> n;
	double *dp = new double[n];
	*dp = 2.5;
	*(dp + 1) = 3.9;
	dp[2] = 4.0;
	double x = dp[1];
	for (int i = 0; i < n; i++)
		cout << dp[i];
*/

//
//double *p=nullptr; //0 или NULL
//
//p = new double;
//if(p!=nullptr){}
//if(p)
//
//*p = 3.5;
//cout << *p << endl;
//delete p;	//освобождава заделената с new памет


void *vp;
vp = new double;
cout << "Enter double number: ";
cin >> *static_cast<double*>(vp);
delete (double*) vp;
vp = new int[5];
cout << "Enter 5 integers: ";
for (int i = 0; i < 5; i++)
	cin >> *(static_cast<int*>(vp) + i);
for (int i = 0; i < 5; i++)
	cout << static_cast<int*>(vp)[i] << ' ';
cout << endl;
delete[](double*)vp;























	system("pause");
}