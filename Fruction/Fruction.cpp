


#include<iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);


class Fraction
{
	int integer;	//öåëàÿ ÷àñòü
	int numerator;	//÷èñëèòåëü
	int denominator;//çíàìåíàòåëü
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	int get_numerator_minus()
	{
		return this->numerator * (-1);
	}
	void set_numerator_minus()
	{
		this->numerator *= (-1);
	}
	void set_denominator_minus()
	{
		this->denominator *= (-1);
	}
	void set_integer(int integer)
	{
		this->integer = integer;
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
	

	//				Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
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
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Operator:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		/*int a = 2;
		int b = 3;
		a = a * b;*/
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	//				Increment/Decrement
	Fraction& operator++()	//Prifex increment
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)	//Postfix increment
	{
		Fraction old = *this;
		integer++;
		return old;
	}

	//				Methods:
	Fraction& to_improper()
	{
		if (integer < 0)
		{
			numerator -= integer * denominator;
			numerator *= (-1);
			integer = 0;
		}
		else
		{
			numerator += integer * denominator;
			integer = 0;
		}
		return *this;
	}
	Fraction& to_proper()
	{
			integer += numerator / denominator;
			numerator %= denominator;		
		return *this;
	}
	Fraction inverted()const
	{
		//Ìåòîä inverted() îáðàùàåò äðîáü:
		Fraction inverted = *this;
		inverted.to_improper();
		//https://legacy.cplusplus.com/doc/tutorial/operators/#:~:text=Bitwise%20operators%20(%20%26%2C%20%7C%2C%20%5E%2C%20~%2C%20%3C%3C%2C%20%3E%3E%20)
		//https://legacy.cplusplus.com/doc/tutorial/operators/#:~:text=Compound%20assignment%20(%2B%3D%2C%20%2D%3D%2C%20*%3D%2C%20/%3D%2C%20%25%3D%2C%20%3E%3E%3D%2C%20%3C%3C%3D%2C%20%26%3D%2C%20%5E%3D%2C%20%7C%3D)
		//RAID-5
		inverted.numerator ^= inverted.denominator;
		inverted.denominator ^= inverted.numerator;
		inverted.numerator ^= inverted.denominator;
		return inverted;
	}
	Fraction& reduce()
	{
		to_proper();
		int more, less, rest;
		if (numerator > denominator)more = numerator, less = denominator;
		else more = denominator, less = numerator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;	//GCD - Greatest Common Divisor
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	void print()const
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
};


Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction summ;
	if ((left.get_numerator() < 0 && right.get_numerator() >= 0) || (left.get_numerator() >= 0 && right.get_numerator() < 0))
	{
		if (right.get_denominator() < 0)
		{
			right.set_numerator_minus();
			right.set_denominator_minus();
		}
		summ.set_numerator(left.get_numerator() * right.get_numerator());
		summ.set_denominator(right.get_denominator() * left.get_denominator());
		summ.to_proper();
		if(summ.get_numerator()<0)summ.set_numerator_minus();
		return summ;
	}
	else 
	{
		if (right.get_denominator() < 0)
		{
			right.set_numerator_minus();
			right.set_denominator_minus();
			summ.set_numerator(left.get_numerator() * right.get_numerator());
			summ.set_denominator(right.get_denominator() * left.get_denominator());
			summ.to_proper();
			summ.set_numerator_minus();
			return summ;
		}
		
		return Fraction(left.get_numerator() * right.get_numerator(),
			right.get_denominator() * left.get_denominator()).to_proper();
	}
		
	
		
	
	
}
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
	/*if (left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator())
		return true;
	else
		return false;*/
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
	//return left > right || left == right;
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
	//return left < right || left == right;
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator()*right.get_denominator(),
		right.get_numerator()*left.get_denominator()
	).to_proper();*/
	return left * right.inverted();
}



Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	if (left < 0 && right < 0)
		return Fraction((left.get_numerator_minus() * right.get_denominator() + left.get_denominator() * right.get_numerator_minus()),
			right.get_denominator() * left.get_denominator()).to_proper();
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return is;

}


//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK

int main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 3;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();

	A = E;
	A.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	/*double a = 2.5;
	double b = 3.14;
	double c = a * b;
	Fraction C = A * B;
	C.print();
	Fraction D = A / B;
	D.print();
	A.print();
	B.print();*/

	A *= B;
	A.print();
	A /= B;
	A.print();

	for (double i = .75; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (Fraction i(3, 4); i.get_integer() < 10; i++)
	{
		i.print();
	}
#endif // ARITHMETICAL_OPERATORS_CHECK

	//cout << (Fraction(1, 2) >= Fraction(5, 11)) << endl;
	Fraction A(-1,2);
	cout << A<< endl;
	cout << A.to_improper() << endl;
	cout << A << endl;
	/*cout << A << endl;
	cin >> A;
	cout << A;*/
	Fraction B(-2,2,3);
	cout << B << endl;
	cout << B.to_improper() << endl;
	cout << B << endl;
	Fraction C = A * B;
	cout << C << endl;
}
