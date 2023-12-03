#include "rational.hpp"

// арифметика
Rational operator+(const Rational& lhs, const Rational& rhs) {
	int64_t res_num = lhs.num_ * rhs.den_ + rhs.num_ * lhs.den_;
	int64_t res_denom = lhs.den_ * rhs.den_;
	return Rational(res_num, res_denom);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
	int64_t res_num = rhs.den_ * lhs.num_ - rhs.num_ * lhs.den_;
	int64_t res_denom = lhs.den_ * rhs.den_;
	return Rational(res_num, res_denom);
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
	int64_t res_num = lhs.num_ * rhs.num_;
	int64_t res_denom = lhs.den_ * rhs.den_;
	return Rational(res_num, res_denom);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	int64_t res_num = rhs.den_;
	int64_t res_denom = rhs.num_;
	Rational righths(res_num, res_denom);
	return operator*(lhs, righths);
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
	ostrm << num_ << separator << den_;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
	int64_t num(0);
	int64_t denom(1);
	char sep(0);
	istrm >> num >> sep >> denom;
	if (istrm.good()) {
		if (Rational::separator == sep) {
			num_ = num;
			den_ = denom;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}