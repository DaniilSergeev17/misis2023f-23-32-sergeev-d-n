#include "complex.hpp"

Complex::Complex(const double real)
	: Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
	: re(real), im(imaginary)
{
}

Complex& Complex::operator+=(const Complex& rhs) {
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex& Complex::operator*=(const double rhs) {
	re *= rhs;
	im *= rhs;
	return *this;
}

// вычитание с присваиванием
Complex& Complex::operator-=(const Complex& rhs) {
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

// умножение комплексного на комплексное
Complex operator*(const Complex& lhs, const Complex& rhs) {
	double real = lhs.re * rhs.re - lhs.im * rhs.im;
	double imaginary = lhs.re * rhs.im + lhs.im * rhs.re;
	return Complex(real, imaginary);
}

// деление комплексного на комплексное
Complex operator/(const Complex& lhs, const Complex& rhs) {
	double real = (lhs.re * rhs.re + lhs.im * rhs.im) / (std::pow(rhs.re, 2) + std::pow(rhs.im, 2));
	double imaginary = (lhs.im * rhs.re - lhs.re * rhs.im) / (std::pow(rhs.re, 2) + std::pow(rhs.im, 2));
	return Complex(real, imaginary);
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaganary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
			&& (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaganary;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}