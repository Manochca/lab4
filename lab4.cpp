#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

class Complex 
{
public:
	double re,im;
	Complex();
	Complex(double r)
	{
		re=r;
		im=0;
	}
	Complex(double r, double i)
	{
		re=r;
		im=i;
	}
    Complex operator +(Complex &);  // прибавить комплексное число
    Complex operator *(Complex &);  // умножить комплексное число
	friend ostream &operator<<(ostream &, Complex &);
	friend istream &operator>>(istream &, Complex &);
public:
	~Complex();
		
};

Complex::Complex()
{
}


Complex Complex::operator+(Complex &z)
{
	z.re = re + z.re;
	z.im = im + z.im;
	return z;
}

Complex Complex::operator*(Complex &z)
{
	double i, j;
	i = re * z.re - im * z.im;
	j = re * z.im + z.re * im;
	z.re = i;
	z.im = j;
	return z;
}

ostream &operator<<(ostream &fo, Complex &z)
{
	if (z.im < 0) 
		fo << z.re  << z.im <<"i" << "\n";
	else 
		fo << z.re << "+" << z.im <<"i"<< "\n";
	return fo;
}

istream &operator>>(istream &fi, Complex &z)
{
cout << "Введите действительную часть: ";
fi >> z.re;
cout << "Введите мнимую часть: ";
fi >> z.im;
return fi;
}

Complex::~Complex()
{
}

void main()
{
	setlocale(LC_ALL,"Russian");
	int n;
	Complex z1,z2,z3,z4;
	do
	{
		cout <<"1. Ввести и вывести комплексные числа \n";
		cout <<"2. Сложение комплексных чисел \n";
		cout <<"3. Умножение комплексных чисел \n";
		cout <<"4. Выход \n";
		cin >>n;
		switch(n)
		{
		case '1':
			cin >>z1;
			cin >>z2;
			cout <<"z1="<<z1;
			cout <<"z2="<<z2;
			break;
		case '2':
			z3=z1+z2;
			cout <<"сложение "<<z3;
			break;
		case '3':
			z4=z1*z2;
			cout <<"умножение "<<z4;
			break;
		case '4':
			break;
		default:
			cout << endl << "Ошибка" << endl; 
			break;
		}
	}
	while(n!='4');
	getch();
}