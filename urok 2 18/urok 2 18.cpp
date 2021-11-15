#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <math.h>
#include <cassert>
using namespace std;
class Fraction
{
private:
	int numerator;
	int dernumerator;
	void nod()
	{
		int n = numerator;
		int d = dernumerator;
		while (n != 0 && d != 0)
		{
			if (n > d)
			{
				n %= d;
			}
			else
			{
				d %= n;
			}
		}
		numerator = numerator / (n + d);
		dernumerator = dernumerator / (n + d);
	}
public:

	Fraction(int numerator = 0, int dernumerator = 1)
	{
		this->numerator = numerator;
		if (dernumerator != 0)
		{
			this->dernumerator = dernumerator;
		}
		else
			this->dernumerator = 1;
		if (this->numerator > 0) 
		{
			nod();
		}
	}
	void setdernumerator(int dernumerator)
	{
		if (dernumerator != 0)
		{
			this->dernumerator = dernumerator;
		}
		else
			this->dernumerator = 1;
		nod();
	}
	void setnumerator(int numerator)
	{
		this->numerator = numerator;
		nod();
	}
	int getnumerator() { return numerator; }
	int getdernumerator() { return dernumerator; }
	void print()
	{
		cout << numerator << "/" << dernumerator << endl;
	}
	
	
	static Fraction add(const Fraction& fobj1, const Fraction& fobj2)
	{
		return Fraction(fobj1.numerator * fobj2.dernumerator + fobj2.numerator * fobj1.dernumerator, fobj1.dernumerator * fobj2.dernumerator);
	}
	static Fraction sub(const Fraction& fobj1, const Fraction& fobj2)
	{
		return Fraction(fobj1.numerator * fobj2.dernumerator - fobj2.numerator * fobj1.dernumerator, fobj1.dernumerator * fobj2.dernumerator);
	}
	static Fraction mult(const Fraction& fobj1, const Fraction& fobj2)
	{
		return Fraction(fobj1.numerator * fobj2.numerator , fobj1.dernumerator * fobj2.dernumerator);
	}
	static Fraction div(const Fraction& fobj1, const Fraction& fobj2)
	{
		return Fraction(fobj1.numerator * fobj2.dernumerator, fobj1.dernumerator * fobj2.numerator);
	}
	static Fraction dic(Fraction& fobj1)
	{
		fobj1.numerator = fobj1.numerator - fobj1.dernumerator;
		return fobj1;
	}
	static Fraction cre( Fraction& fobj1)
	{
		fobj1.numerator = fobj1.numerator + fobj1.dernumerator;
		return fobj1;
	}
	
	static Fraction pow1(Fraction& fobj1)
	{
		
		return Fraction(fobj1.numerator * fobj1.numerator, fobj1.dernumerator * fobj1.dernumerator);;
	}
	static Fraction sqrt(Fraction& fobj1)
	{

		return Fraction(fobj1.numerator %2, fobj1.dernumerator/ 2);
	}
	static bool isEqual1(const Fraction& fobj1, const Fraction& fobj2)
	{
		if ((fobj1.numerator * fobj2.dernumerator) == (fobj2.numerator * fobj1.dernumerator) && (fobj1.dernumerator * fobj2.dernumerator) == (fobj1.dernumerator * fobj2.dernumerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	static bool isEqual2(const Fraction& fobj1, const Fraction& fobj2)
	{
		if ((fobj1.numerator * fobj2.dernumerator) > (fobj2.numerator * fobj1.dernumerator) && (fobj1.dernumerator * fobj2.dernumerator) == (fobj1.dernumerator * fobj2.dernumerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	static bool isEqual3(const Fraction& fobj1, const Fraction& fobj2)
	{
		if ((fobj1.numerator * fobj2.dernumerator) < (fobj2.numerator * fobj1.dernumerator) && (fobj1.dernumerator * fobj2.dernumerator) == (fobj1.dernumerator * fobj2.dernumerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	static bool isEqual4(const Fraction& fobj1, const Fraction& fobj2)
	{
		if ((fobj1.numerator * fobj2.dernumerator) > (fobj2.numerator * fobj1.dernumerator)||(fobj1.numerator * fobj2.dernumerator) == (fobj2.numerator * fobj1.dernumerator) && (fobj1.dernumerator * fobj2.dernumerator) == (fobj1.dernumerator * fobj2.dernumerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	static bool isEqual5(const Fraction& fobj1, const Fraction& fobj2)
	{
		if ((fobj1.numerator * fobj2.dernumerator) < (fobj2.numerator * fobj1.dernumerator) || (fobj1.numerator * fobj2.dernumerator) == (fobj2.numerator * fobj1.dernumerator) && (fobj1.dernumerator * fobj2.dernumerator) == (fobj1.dernumerator * fobj2.dernumerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	friend Fraction operator+(const Fraction& point1, const Fraction& point2)
	{
		return add(point1, point2);
	}
	friend Fraction operator-(const Fraction& point1, const Fraction& point2)
	{
		return sub(point1, point2);
	}
	friend Fraction operator*(const Fraction& point1, const Fraction& point2)
	{
		return mult(point1, point2);
	}
	friend Fraction operator/(const Fraction& point1, const Fraction& point2)
	{
		return div(point1, point2);
	}
	friend Fraction operator--( Fraction& point1)
	{
		return dic(point1);
	}
	friend Fraction operator++( Fraction& point1)
	{
		return cre(point1);
	}
	friend Fraction pow(Fraction& point1)
	{
		return pow1(point1);
	}
	friend Fraction sqrt(Fraction& point1)
	{
		return sqrt(point1);
	}
	friend ostream& operator<<(ostream& output, const Fraction& point)
	{
		output << "(" << point.numerator << "/" << point.dernumerator << ")";
		return output;
	}
	friend bool operator==(const Fraction& point1, const Fraction& point2)
	{
		return isEqual1(point1, point2);
	}
	friend bool operator>(const Fraction& point1, const Fraction& point2)
	{
		return isEqual2(point1, point2);
	}
	friend bool operator<(const Fraction& point1, const Fraction& point2)
	{
		return isEqual3(point1, point2);
	}
	friend bool operator>=(const Fraction& point1, const Fraction& point2)
	{
		return isEqual4(point1, point2);
	}
	friend bool operator<=(const Fraction& point1, const Fraction& point2)
	{
		return isEqual5(point1, point2);
	}

};
int main()
{
	srand(time(NULL));
	Fraction drob1(1,16);
	Fraction drob2(1, 2);
	cout << drob1 + drob2;
	cout << drob1 - drob2;
	cout << drob1 * drob2;
	cout << drob1 / drob2;
	if (drob1 == drob2) 
	{
		cout << "\nRavni\n";
	}
	if (drob1 > drob2)
	{
		cout << "\ndrob1 bolshe\n";
	}
	if (drob1 < drob2)
	{
		cout << "\ndrob1 menshe\n";

	}
	if (drob1 >= drob2)
	{
		cout << "\ndrob1 bolshe ili ravna\n";
	}
	if (drob1 <= drob2)
	{
		cout << "\ndrob1 menshe ili ravna\n";
	}
	//cout << --drob1<<"\n";
	cout << pow(drob1);
	cout << sqrt(drob1);
	return 0;
}