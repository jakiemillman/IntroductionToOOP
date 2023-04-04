// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

//int NOD(int denominator1, int denominator2);
//int NOK(int denominator1, int denominator2);

class Fraction
{
	int numerator;
	int denominator;
	int integer;

public:
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;

	}
	int get_integer()const
	{
		return integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	//constructor
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "1ArgConstructor:\t" << this << endl;
		return *this;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		inverted.numerator ^= inverted.denominator;
		inverted.denominator ^= inverted.numerator;
		inverted.numerator ^= inverted.denominator;
		return inverted;

	}
	//Methods
	void Print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	int NOD(Fraction right)
	{
		Fraction Product = *this;
		while (true)
			{
			if (Product.denominator == right.denominator)
			{
				return Product.denominator;
			}
			if (Product.denominator > right.denominator)
			
				Product.set_denominator(abs(Product.denominator - right.denominator));
				
			else
				right.set_denominator(abs(Product.denominator - right.denominator));
			
			}
	}
	int NOK(Fraction right)
	{
		Fraction Product = *this;
		
		return Product.denominator * right.denominator / Product.NOD(right);
	}
};
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction product;
	product.set_numerator(left.get_numerator()* right.get_numerator());
	product.set_denominator(left.get_denominator() * right.get_denominator());*/
	/*Fraction product
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
	product.to_proper();
	return product;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();

}
//Fraction operator/(Fraction left, Fraction right)
//{
//	left.to_improper();
//	right.to_improper();
//	return Fraction
//	(
//		left.get_numerator() * right.get_denominator(),
//		left.get_denominator() * right.get_numerator()
//	).to_proper();
//}
Fraction operator/(Fraction left, Fraction right)
{
	return left * right.inverted();
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*product.set_numerator(left.get_numerator() * right.get_denominator() + left.get_denominator() * right.get_numerator());
	product.set_denominator(left.get_denominator() * right.get_denominator());
	return product.to_proper();*/
	return Fraction(left.get_numerator() * (left.NOK(right)/ left.get_denominator()) + right.get_numerator()* (left.NOK(right) / right.get_denominator()),
		left.NOK(right)).to_proper();
	
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*product.set_numerator(left.get_numerator() * right.get_denominator() + left.get_denominator() * right.get_numerator());
	product.set_denominator(left.get_denominator() * right.get_denominator());
	return product.to_proper();*/
	return Fraction(left.get_numerator() * (left.NOK(right) / left.get_denominator()) - right.get_numerator() * (left.NOK(right) / right.get_denominator()),
		left.NOK(right)).to_proper();

}

//#define constructors_check
int main()
{

	setlocale(LC_ALL, "rus");
#ifdef constructors_check
	Fraction A;
	A.Print();
	Fraction B = 3;
	B.Print();
	Fraction C(1, 2);
	C.Print();
	Fraction D(2, 3, 4);
	D.Print();
	Fraction E = C;
	E.Print();
	A = E;
	A.Print();
#endif
	Fraction A(8, 1, 8);
	A.Print();
	Fraction B(4, 1, 6);
	B.Print();
	Fraction C = A * B;
	C.Print();
	Fraction D = A / B;
	D.Print();
	Fraction M = A + B;
	M.Print();
	Fraction H = A - B;
	H.Print();
	//cout << endl << NOK(20, 30) << endl;
}

//int NOD(int denominator1, int denominator2)
//{
//	/*while (true)
//	{
//		if (denominator1 == denominator2)return denominator1;
//		if (denominator1>denominator2)
//			denominator1 = abs(denominator1 - denominator2);
//		else
//			denominator2 = abs(denominator1 - denominator2);
//		cout << denominator1 << " " << denominator2 << endl;
//	}*/
//	if (denominator1 < denominator2)swap(denominator1, denominator2);
//	return denominator2 ? NOD(denominator1 % denominator2, denominator2) : denominator1;
//}
//
//int NOK(int denominator1, int denominator2)
//{
//	return denominator1* denominator2/NOD(denominator1, denominator2);
//}
