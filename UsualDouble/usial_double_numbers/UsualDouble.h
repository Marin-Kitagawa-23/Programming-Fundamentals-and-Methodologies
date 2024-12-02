#pragma once
#include<iostream>
#include<regex>
using namespace std;
class UsualDouble {
	int num;
	int din;
public:
	UsualDouble();
	UsualDouble(int const& a, int const& b);
	UsualDouble(int const& a);
	friend double utov(const UsualDouble& a);
	friend void simplyfy(int& n, int& d);
	friend bool operator> (UsualDouble& a, UsualDouble& b);
	friend bool operator>= (UsualDouble& a, UsualDouble& b);
	friend bool operator< (UsualDouble& a, UsualDouble& b);
	friend bool operator<= (UsualDouble& a, UsualDouble& b);
	friend bool operator== (const UsualDouble& a, const UsualDouble& b);
	friend bool operator!= (const UsualDouble& a, const UsualDouble& b);
	friend UsualDouble operator- (UsualDouble &a);
	friend UsualDouble operator+ (const UsualDouble &a, const UsualDouble& b);
	friend UsualDouble operator+= (UsualDouble& a, const UsualDouble& b);
	friend UsualDouble operator- (const UsualDouble& a, const UsualDouble& b);
	friend UsualDouble operator-= (UsualDouble& a, const UsualDouble& b);
	friend UsualDouble operator* (const UsualDouble& a, const UsualDouble& b);
	friend UsualDouble operator*= (UsualDouble& a, const UsualDouble& b);
	friend UsualDouble operator/ (const UsualDouble& a, const UsualDouble& b);
	friend UsualDouble operator/= (UsualDouble& a, const UsualDouble& b);
	UsualDouble operator++ (int);
	UsualDouble &operator++ ();
	UsualDouble operator-- (int);
	UsualDouble &operator-- ();
	friend ostream& operator<< (ostream& os, const UsualDouble& a);
	friend istream& operator>> (istream& is, UsualDouble& a);
};
