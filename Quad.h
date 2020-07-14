#ifndef QUAD_H_
#define QUAD_H_
#endif // !QUAD_H_

#include<array>
using namespace std;
/*
class Quad represents an ADT representing set of values of the form (x1/x2) +(x3/x4)sqrt(2)
All unary and compound operators are member functions
All Arithematic and Relational operators are free functions(friend).
*/
class Quad
{
	array<long long int, 4> values;
	public:
	Quad(long long int x1 = 0, long long int x2 = 1, long long int x3 = 0, long long int x4 = 1);
	void standardize();
	Quad inverse() const;
	bool isSimilar(const Quad& q2);
	const double norm() const;
	Quad conjugate();
	const double absoluteValue();
	void normalize();
	void reduce();
	Quad operator++();
	Quad operator--();
	Quad operator++( int);
	Quad operator--( int);
	Quad & operator+();
	Quad & operator-();
	Quad operator+=(Quad q1);
	Quad operator+=(long long int i);
	Quad operator-=(Quad q1);
	Quad operator-=(long long int y);
	Quad operator*=(Quad q1);
	Quad operator*=(long long int y);
	Quad operator/=(Quad q1);
	Quad operator/=(long long int y);
	double operator()();
	Quad operator^(int k);
	long long int& operator[](long long int i);
	friend ostream& operator<<(ostream& os, const Quad& q);
	friend Quad operator+(const Quad&, const Quad&);
	friend Quad operator-(const Quad&, const Quad&);
	friend Quad operator*(const Quad&, const Quad&);
	friend Quad operator+(const Quad, const long long int);
	friend Quad operator+(const long long int, const Quad);
	friend Quad operator-(const Quad, const long long int);
	friend Quad operator-(const long long int, const Quad);
	friend Quad operator*(const Quad, const long long int);
	friend Quad operator*(const long long int, const Quad);
	friend Quad operator/(const Quad&,const Quad&);
	friend Quad operator/(const Quad, const long long int);
	friend Quad operator/(const long long int, const Quad);
	friend bool operator==(const Quad&, const Quad&);
	friend bool operator!=(const Quad&, const Quad&);
	friend istream& operator>>(istream& in, Quad& q1);
	friend bool operator<(const Quad& q1, const Quad& q2);
	friend bool operator>(const Quad& q1, const Quad& q2);
	friend bool operator>=(const Quad& q1, const Quad& q2);
	friend bool operator<=(const Quad& q1, const Quad& q2);
	friend bool operator<(const long long int i2, const Quad& q1);
	friend bool operator>(const long long int i2, const Quad& q1);
	friend bool operator<=(const long long int i2, const Quad& q1);
	friend bool operator>=(const long long int i2, const Quad& q1);
	friend bool operator<(const Quad& q1, const long long int i2);
	friend bool operator<=(const Quad& q1, const long long int i2);
	friend bool operator>(const Quad& q1, const long long int i2);
	friend bool operator>=(const Quad& q1, const long long int i2);
	friend bool operator==(const Quad& q1, const long long int i2);
	friend bool operator!=(const Quad& q1, const long long int i2);
	friend bool operator!=(const long long int i2, const Quad& q2);
	friend bool operator==(const long long int i2, const Quad& q1);
	
};