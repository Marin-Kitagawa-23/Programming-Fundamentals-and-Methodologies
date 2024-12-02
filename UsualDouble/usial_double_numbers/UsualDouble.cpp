#include "UsualDouble.h"
#include "regex"

void simplyfy(int& n, int& d) {
	int a = abs(n);
	int b = abs(d);
	while (a != b and a != 0) {
		if (a > b) {
			a -= b;
		}
		else {
			b -= a;
		}
	}
	if (a != 0) {
		if (d < 0) {
			n *= -1;
			d *= -1;
		}
		n /= b;
		d /= b;
	}
}
UsualDouble::UsualDouble() {
	num = 0;
	din = 1;
}
UsualDouble::UsualDouble(int const& a, int const& b) {
	num = a;
	din = b;
	simplyfy(num, din);
}
UsualDouble::UsualDouble(int const& a) {
	num = a;
	din = 1;
}

	UsualDouble operator- (UsualDouble &a) {
		return UsualDouble(a.din, a.num);
	}

UsualDouble operator+ (const UsualDouble &a, const UsualDouble& b) {
	UsualDouble d;
	d.num = a.num * b.din + b.num * a.din;
	d.din = a.din * b.din;
	simplyfy(d.num, d.din);
	return d;
}

double utov(const UsualDouble& a) {
	double d;
	d = a.num / (double)a.din;
	return d;
}


bool operator== (const UsualDouble &a, const UsualDouble& b) {
	if (a.num == b.num and a.din == b.din) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>= (UsualDouble& a, UsualDouble& b) {
	a.num *= b.din;
	b.num *= a.din;
	a.din *= b.din;
	b.din *= a.din;
	if (a.num >= b.num) {
		simplyfy(a.num, a.din);
		simplyfy(b.num, b.din);
		return true;
	}
	else {
		simplyfy(a.num, a.din);
		simplyfy(b.num, b.din);
		return false;
	}
}

bool operator> (UsualDouble& a, UsualDouble& b) {
	a.num *= b.din;
	b.num *= a.din;
	a.din *= b.din;
	b.din *= a.din;
	if (a.num > b.num) {
		simplyfy(a.num, a.din);
		simplyfy(b.num, b.din);
		return true;
	}
	else {
		simplyfy(a.num, a.din);
		simplyfy(b.num, b.din);
		return false;
	}
}

bool operator< (UsualDouble& a, UsualDouble& b) {
	a.num *= b.din;
	b.num *= a.din;
	a.din *= b.din;
	b.din *= a.din;
	if (a.num < b.num) {
		simplyfy(a.num, a.din);
		simplyfy(b.num, b.din);
		return true;
	}
	else {
		simplyfy(a.num, a.din);
		simplyfy(b.num, b.din);
		return false;
	}
}

bool operator<= ( UsualDouble& a, UsualDouble& b) {
	a.num *= b.din;
	b.num *= a.din;
	a.din *= b.din;
	b.din *= a.din;
	if (a.num <= b.num) {
		simplyfy(a.num, a.din);
		simplyfy(b.num, b.din);
		return true;
	}
	else {
		simplyfy(a.num,a.din);
		simplyfy(b.num, b.din);
		return false;
	}
}

bool operator!= (const UsualDouble& a, const UsualDouble& b) {
	if (a.num == b.num and a.din == b.din) {
		return false;
	}
	else {
		return true;
	}
}

UsualDouble operator+= (UsualDouble& a, const UsualDouble& b) {
	a.num *= b.din;
	a.num += b.num * a.din;
	a.din *= b.din;
	simplyfy(a.num, a.din);
	return UsualDouble(a.num, a.din);
}

UsualDouble operator- (const UsualDouble& a, const UsualDouble& b) {
	UsualDouble d;
	d.num = a.num * b.din - b.num * a.din;
	d.din = a.din * b.din;
	simplyfy(d.num, d.din);
	return d;
}
UsualDouble operator-= (UsualDouble& a, const UsualDouble& b) {
	a.num *= b.din;
	a.num -= b.num * a.din;
	a.din *= b.din;
	simplyfy(a.num, a.din);
	return UsualDouble(a.num, a.din);
}


UsualDouble operator* (const UsualDouble& a, const UsualDouble& b) {
	UsualDouble d;
	d.num = a.num * b.num;
	d.din = a.din * b.din;
	simplyfy(d.num, d.din);
	return d;
}

UsualDouble operator*= (UsualDouble& a, const UsualDouble& b) {
	a.num *= b.num;
	a.din *= b.din;
	return UsualDouble(a.num, a.din);
}

UsualDouble operator/ (const UsualDouble& a, const UsualDouble& b) {
	UsualDouble d;
	d.num = a.num * b.din;
	d.din = a.din * b.num;
	simplyfy(d.num, d.din);
	return d;
}

UsualDouble operator/= (UsualDouble& a, const UsualDouble& b) {
	a.num *= b.din;
	a.din *= b.num;
	return UsualDouble(a.num, a.din);
}

UsualDouble UsualDouble::operator++ (int) {
	num += din;
	return UsualDouble(num, din);
}

UsualDouble &UsualDouble::operator++ () {
	num += din;
	return *this;
}

UsualDouble UsualDouble::operator-- (int) {
	num -= din;
	return UsualDouble(num, din);
}

UsualDouble &UsualDouble::operator-- () {
	num -= din;
	return *this;
}

ostream& operator<< (ostream& os, const UsualDouble& a) {
	if (a.num == 0) {
		return os << a.num << " or " << a.num << "/" << a.din;
	}
	if (a.din == 1) {
		return os << a.num << " or " << a.num << "/" << a.din;
	}
	return os << a.num / a.din << " and " << a.num % a.din << "/" << a.din << " or " << a.num << "/" << a.din;
}

istream& operator>> (istream& is, UsualDouble& a) {
	string r;
	regex b("\-*\\d*\/\-*\\d+");
	regex b1("\-*\\d+");
	cmatch z;
	cmatch z1;
	while (true) {
		is >> r;
		regex_match(r.c_str(), z1, b1);
		for (const auto& x : z1) {
			if (x == r) {
				a.num = stoi(r);
				a.din = 1;
				return is;
			}
		}
		regex_match(r.c_str(), z, b);
		int index = r.find("/");
		for (auto x : z) {
			if (x == r) {
				if (r.substr(0, index) == "") {
					a.num = 0;
				}
				else {
					a.num = stoi(r.substr(0, index));
				}
				if (stoi(r.substr(index + 1, r.size() - index)) != 0)
					a.din = stoi(r.substr(index + 1, r.size() - index));
				else {
					continue;
				}
				int f = abs(a.num);
				int g = abs(a.din);
				while (f != g and f != 0) {
					if (f > g) {
						f -= g;
					}
					else {
						g -= f;
					}
				}
				if (f != 0) {
					if (a.din < 0) {
						a.num *= -1;
						a.din *= -1;
					}
					a.num /= g;
					a.din /= g;
				}
				return is;
			}
			else {
				cout << "Error input! Try again: " << endl;
				continue;
			}
		}
		cout << "Error input! Try again: " << endl;
		continue;
	}
}