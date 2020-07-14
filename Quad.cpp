
#include"Quad.h"
#include<iostream>
#include<ostream>
#include<math.h>

using namespace std;

/*
Constructor takes 4 values as long int or uses default values to initialize
*/

Quad::Quad(long long int x1, long long int x2, long long int x3, long long int x4)
{
	values = { x1,x2,x3,x4 };
	normalize();
	reduce();
}

/*
local function that finds the gcd of two integers
*/
long long int gcd(long long int i, long long int j)
{
	if (i < 0)
		i = -i;
	if (j < 0)
		j = -j;
	if (i == 0 || j == 0)
		return i + j;
	if (i == j)
		return i;
	if (i < j)
		return gcd(i, j - i);
	else
		return gcd(i - j, j);
}

/*
prefix increment operation on Quad
*/
Quad Quad::operator++()
{
	*this = *this + 1;
	return *this;
}
/*
prefix decrement operation on Quad
*/
Quad Quad::operator--()
{
	*this = *this - 1;
	return *this;
}
/*
postfix increment operation on Quad
*/

Quad Quad::operator++(int y)
{
	Quad temp(*this);
	*this = *this + 1;
	return temp;
}

/*
postfix decrement operation on Quad
*/
Quad Quad::operator--(int y)
{
	Quad temp(*this);
	*this = *this - 1;
	return temp;
}

/*
operator + prefix Quad
*/
Quad& Quad::operator+()
{
	return *this;
}

/*
operator - prefix Quad, returns the negation of Quad
*/
Quad& Quad::operator-()
{
	this->values[0] = -(this->values[0]);
	this->values[2] = -(this->values[2]);
	return *this;
}
/*
operator += on 2 Quads, adds and assigns the value to the lhs operand
*/

Quad Quad::operator+=(Quad q1)
{
	*this = *this + q1;
	return *this;
}

/*
operator += on Quad and int, adds and assigns the value to the lhs operand
*/
Quad Quad::operator+=(long long int y)
{
	Quad temp(*this);
	*this = *this + 1;
	return temp;
}

/*
operator -= on 2 Quads, subtracts and assigns the value to the lhs operand
*/
Quad Quad::operator-=(Quad q1)
{
	*this = *this - q1;
	return *this;
}

/*
operator -= on Quad and int, subtracts and assigns the value to the lhs operand
*/
Quad Quad::operator-=(long long int y)
{
	Quad temp(*this);
	*this = *this - 1;
	return temp;
}

/*
operator *= on 2 Quads, multiplies and assigns the value to the lhs operand
*/
Quad Quad::operator*=(Quad q1)
{
	*this = *this * q1;
	return *this;
}
/*
operator *= on Quad and int, multiplies and assigns the value to the lhs operand
*/
Quad Quad::operator*=(long long int y)
{
	Quad temp(*this);
	*this = *this * 1;
	return temp;
}
/*
operator /= on 2 Quads, adds and assigns the value to the lhs operand
*/

Quad Quad::operator/=(Quad q1)
{
	*this = *this / q1;
	return *this;
}
/*
operator /= on Quad and int, adds and assigns the value to the lhs operand
*/
Quad Quad::operator/=(long long int y)
{
	Quad temp(*this);
	*this = *this / 1;
	return temp;
}

/*
operator()- returns the absolute value of the Quad
*/
double Quad::operator()()
{
	return this->absoluteValue();
}

/*
overloaded operator<< - outputs the Quad
*/
ostream& operator<<(ostream & os,const Quad& q)
{
	os << "[";
	for (int i = 0; i < q.values.size(); i++)
	{
		os << q.values[i];
		if(i!=q.values.size()-1)
		{
			os << ", ";
		}
	}
	os << "]";
	return os;
}
/*
overloaded  == compares two Quads for equality
*/

bool operator==(const Quad& q1, const Quad& q2)
{
	for (int i = 0; i < q1.values.size(); i++)
	{
		if (q1.values[i] != q2.values[i])
		{
			return false;
		}
	}
	return true;
}

/*
overloaded  != compares two Quads unequality

*/
bool operator!=(const Quad& q1, const Quad& q2)
{
	for (int i = 0; i < q1.values.size(); i++)
	{
		if (q1.values[i] == q2.values[i])
		{
			return false;
		}
	}
	return true;
}

/*
performs addition of two Quads and returns the resultant
*/

Quad operator+(const Quad& q1, const Quad& q2)
{
	long long int v1=q1.values[0]* q2.values[1]+q1.values[1] * q2.values[0];
	long long int v2 = q1.values[1] * q2.values[1];
	long long int v3 = q1.values[2] * q2.values[3] + q1.values[3] * q2.values[2];
	long long int v4 = q1.values[3] * q2.values[3];
	 return Quad(v1, v2, v3, v4);
}

/*
performs substraction of two Quads and returns the resultant
*/
Quad operator-(const Quad& q1, const Quad& q2)
{
	long long int v1 = q1.values[0] * q2.values[1] - q1.values[1] * q2.values[0];
	long long int v2 = q1.values[1] * q2.values[1];
	long long int v3 = q1.values[2] * q2.values[3] - q1.values[3] * q2.values[2];
	long long int v4 = q1.values[3] * q2.values[3];
	return Quad(v1, v2, v3, v4);
}

/*
performs multiplication of two Quads and returns the resultant
*/
Quad operator*(const Quad& q1, const Quad& q2)
{
	long long int v1 = q1.values[0] * q2.values[0]* q1.values[3] * q2.values[3] +2* q1.values[2] * q2.values[2] * q1.values[1] * q2.values[1];
	long long int v2 = q1.values[1] * q2.values[1] * q1.values[3] * q2.values[3];
	long long int v3 = q1.values[0] * q2.values[2] * q1.values[3] * q2.values[1] + q2.values[0] * q1.values[2] * q2.values[3] * q1.values[1];
	long long int v4 = q1.values[1] * q2.values[1] * q1.values[3] * q2.values[3];
	return Quad(v1, v2, v3, v4);
}

/*
performs division of two Quads and returns the resultant
*/

Quad operator/(const Quad& q1,const Quad& q2)
{
	return q1*q2.inverse();
}

/*
performs division of Quad and Integer represented as Quad, returns the resultant
*/

Quad operator/(Quad q1, const long long int i2)
{
	long long int temp1 = i2 * q1.values[1];
	long long int temp2 = i2 * q1.values[3];
	return Quad(q1.values[0], temp1, q1.values[2], temp2);
}
/*
performs division of Quad and Integer represented as Quad, returns the resultant
*/

Quad operator/(const long long int i2, Quad q1)
{
	long long int temp1 = i2 * q1.values[1];
	long long int temp2 = i2 * q1.values[3];
	return Quad(q1.values[0], temp1, q1.values[2], temp2);
}
/*
performs addition of Quad and Integer represented as Quad, returns the resultant
*/
Quad operator+(const Quad q1, const long long int i2) 
{
	long long int temp = q1.values[0] + i2 * q1.values[1];
	return Quad(temp,q1.values[1], q1.values[2], q1.values[3]);
}
/*
performs addition of Quad and Integer represented as Quad, returns the resultant
*/
Quad operator+(const long long int i2, const Quad q1)
{
	long long int temp = q1.values[0] + i2 * q1.values[1];
	return Quad(temp, q1.values[1], q1.values[2], q1.values[3]);
}

/*
performs substraction of Quad and Integer represented as Quad, returns the resultant
*/
Quad operator-(const Quad q1, const long long int i2)
{
	long long int temp = q1.values[0] - i2 * q1.values[1];
	return Quad(temp, q1.values[1], q1.values[2], q1.values[3]);
}
/*
performs substraction of Quad and Integer represented as Quad, returns the resultant
*/

Quad operator-(const long long int i2, const Quad q1)
{
	long long int temp = q1.values[0] - i2 * q1.values[1];
	return Quad(temp, q1.values[1], q1.values[2], q1.values[3]);
}
/*
performs multiplication of Quad and Integer represented as Quad, returns the resultant
*/

Quad operator*(const Quad q1, const long long int i2)
{
	long long int temp1= i2 * q1.values[0];
	long long int temp2 = i2 * q1.values[2];
	return Quad(temp1, q1.values[1], temp2, q1.values[3]);
}
/*
performs multiplication of Quad and Integer represented as Quad, returns the resultant
*/
Quad operator*(const long long int i2, const Quad q1)
{
	long long int temp1 = i2 * q1.values[0];
	long long int temp2 = i2 * q1.values[2];
	return Quad(temp1, q1.values[1], temp2, q1.values[3]);
}
/*
raises the Quad to the integer power and returns the resultant
*/

Quad Quad::operator^(int k)
{
	if (k > 0)
	{
		int l = 1;
		Quad temp{ *this };
		if (k == 1)
			return temp;
		while (l < k)
		{
			temp *= *this;
			l++;
		}
		return temp;
	}
	else if(k<0)
	{
		Quad temp{ this->inverse() };
		int j = -1;
		if (k == -1)
		{
			return temp;
		}
		while (k<j)
		{
			temp *= this->inverse();
			j--;
		}
		return temp;
	}
}

/*
takes input from console and assign values to the Quad;
*/

istream& operator>>(istream& in, Quad& q1)
{
	in >> q1.values[0] >> q1.values[1] >> q1.values[2] >> q1.values[3];
	return in;
}
/*
compares two Quads
*/

bool operator<(const Quad& q1, const Quad& q2)
{
	if (q1.norm() < q2.norm())
		return true;
	return false;
}
/*
compares two Quads
*/

bool operator<=(const Quad& q1, const Quad& q2)
{
	if (q1.norm() <= q2.norm())
		return true;
	return false;
}
/*
compares two Quads
*/
bool operator>(const Quad& q1, const Quad& q2)
{
	if (q1.norm() > q2.norm())
		return true;
	return false;
}
/*
compares two Quads 
*/
bool operator>=(const Quad& q1, const Quad& q2)
{
	if (q1.norm() >= q2.norm())
		return true;
	return false;
}
/*
compares Quad and Integer for <
*/
bool operator<(const Quad& q1, const long long int i2)
{
	Quad q2(i2, 1, 0, 1);
	if (q1.norm() < q2.norm())
		return true;
	return false;
}
/*
compares Quad and Integer for <
*/
bool operator<=(const Quad& q1,const long long int i2)
{
	Quad q2(i2, 1, 0, 1);
	if (q1.norm() <= q2.norm())
		return true;
	return false;
}
/*
compares Quad and Integer for >
*/

bool operator>(const Quad& q1, const long long int i2)
{
	Quad q2(i2, 1, 0, 1);
	if (q1.norm() > q2.norm())
		return true;
	return false;
}
/*
compares Quad and Integer for >=
*/
bool operator>=(const Quad& q1, const long long int i2)
{
	Quad q2(i2, 1, 0, 1);
	if (q1.norm() >= q2.norm())
		return true;
	return false;
}

/*
compares Quad and Integer for <
*/
bool operator<(const long long int i2, const Quad& q1)
{
	Quad q2(i2, 1, 0, 1);
	if (q1.norm() < q2.norm())
		return true;
	return false;
}
/*
compares Quad and Integer for <=
*/
bool operator<=(const long long int i2, const Quad& q1)
{
	Quad q2(i2, 1, 0, 1);
	if (q1.norm() <= q2.norm())
		return true;
	return false;
}
/*
compares Quad and Integer for >
*/
bool operator>(const long long int i2, const Quad& q1)
{
	Quad q2(i2, 1, 0, 1);
	if (q1.norm() > q2.norm())
		return true;
	return false;
}
/*
compares Quad and Integer for >=
*/

bool operator>=(const long long int i2, const Quad& q1)
{
	Quad q2(i2, 1, 0, 1);
	if (q1.norm() >= q2.norm())
		return true;
	return false;
}
/*
compares Quad and Integer for equality
*/
bool operator==(const Quad& q1, const long long int i2)
{
	Quad q2(i2, 1, 0, 1);
	for (int i = 0; i < q1.values.size(); i++)
	{
		if (q1.values[i] != q2.values[i])
		{
			return false;
		}
	}
	return true;
}
/*
compares Quad and Integer for equality
*/
bool operator==( const long long int i2, const Quad& q1)
{
	Quad q2(i2, 1, 0, 1);
	for (int i = 0; i < q1.values.size(); i++)
	{
		if (q1.values[i] != q2.values[i])
		{
			return false;
		}
	}
	return true;
}
/*
compares Quad and Integer for inequality
*/
bool operator!=(const long long int i2, const Quad& q1)
{
	Quad q2(i2, 1, 0, 1);
	for (int i = 0; i < q1.values.size(); i++)
	{
		if (q1.values[i] == q2.values[i])
		{
			return false;
		}
	}
	return true;
}
/*
compares Quad and Integer for inequality
*/
bool operator!=(const Quad& q1, const long long int i2)
{
	Quad q2(i2, 1, 0, 1);
	for (int i = 0; i < q1.values.size(); i++)
	{
		if (q1.values[i] == q2.values[i])
		{
			return false;
		}
	}
	return true;
}

//named member functions



/*
Normalizes and reduces the Quad
*/
void Quad::standardize()
{
	this->normalize();
	this->reduce();
}
/*
returns the inverse of the calling Quad
throws exception if x2=0
*/

Quad Quad::inverse() const
{
	try {
		long long int v2 = ((this->values[0] * this->values[0]) *(this->values[3] * this->values[3])) - 2 * ((this->values[1] * this->values[1]) *(this->values[2] * this->values[2]));
		if (v2 != 0)
		{
			long long int v1 = this->values[0] * this->values[1] * (this->values[3] * this->values[3]);
			long long int v3 = -((this->values[1] * this->values[1]) * this->values[2] * this->values[3]);
			long long int v4 = v2;
			return Quad(v1, v2, v3, v4);
		}
		else
		{
			throw "Invalid operation in inversion()";
		}
	}
	catch (const char* msg)
	{
		cerr << "msg" << endl;
	}

}
/*
normalizes the Quad
*/

void Quad::normalize()
{
	if (this->values[1] < 0 && this->values[3] < 0)
	{
		this->values[0] = -(this->values[0]);
		this->values[1] = -(this->values[1]);
		this->values[2] = -(this->values[2]);
		this->values[3] = -(this->values[3]);
	}
	else if (this->values[1] < 0)
	{
		this->values[0] = -(this->values[0]);
		this->values[1] = -(this->values[1]);
	}
	else if (this->values[3] < 0)
	{
		this->values[2] = -(this->values[2]);
		this->values[3] = -(this->values[3]);
	}
}

/*

Reduces the Quad by using GCD of x1,x2 and x3,x4
*/

void Quad::reduce()
{
	long long int a = gcd(this->values[0], this->values[1]);
	long long int b = gcd(this->values[2], this->values[3]);
	if (a > 1)
	{
		this->values[0] = this->values[0] / a;
		this->values[1] = this->values[1] / a;
	}
	if (b > 1)
	{
		this->values[2] = this->values[2] / b;
		this->values[3] = this->values[3] / b;
	}
}

/*
 checks for similarity in two Quads
*/
bool Quad::isSimilar(const Quad & q2)
{
	if ((this->values[0] * q2.values[1] == this->values[1] * q2.values[0]) && (this->values[2] * q2.values[3] == this->values[3] * q2.values[2]))
	{
		return true;
	}
	return false;
}

/*
overloaded operator []- reference to the subscript value of Quad
*/
long long int& Quad::operator[](long long int i)
{

		if (i < 1 || i > 4)
			throw invalid_argument("index out of bounds");
		return this->values[i - 1];
	
}
/*
returns the norm value of the Quad
*/

const double Quad::norm() const
{
	double t1 = (double) this->values[0] / (double) this->values[1];
	double t2 = (double)this->values[2] / (double)this->values[3];
	return t1 * t1 + t2 * t2;
	//*(this->values[0] / this->values[1]);
	//double temp = static_cast<double> (() + ((this->values[2] / this->values[3])*(this->values[2] / this->values[3])));
}

/*
returns the conjugate of the Quad
*/
Quad Quad::conjugate()
{
		if (this->values[1] != 0 && this->values[3] != 0)
		{
			long long int v1 = -(this->values[2]);
			return Quad(this->values[0], this->values[1], v1, this->values[3]);
		}
		else
		{
			throw "Invalid conjugate operation";
		}
	
}
/*
returns the absolute value of the Quad
*/
const double Quad::absoluteValue()
{
	return sqrt(this->norm());
}
