#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <sstream>

class Rational {
private:
	static const char separator{ '/' };
	int64_t gcd(int64_t num, int64_t den) const { // НОД двух чисел (числителя и знаменателя)
		while (den != 0) {
			int64_t temp = den;
			den = num % den;
			num = temp;
		}
		return num;
	}

public:
	int64_t num_ = 0;
	int64_t den_ = 1;
	double doubl_ = 0;
	Rational() {}; // конструктор по умолчанию
	Rational(const Rational&) {}; // конструктор копирования
	~Rational() {}; // деструктор
	Rational& operator=(const Rational&) {}; // оператор присваивания
	void div_zero(int64_t denom) const { // обработка нуля в знаменателе
		if (denom == 0) {
			std::cerr << "Denominator can't be zero!" << "\n";
			throw std::invalid_argument("Denominator can't be zero!");
		}
	}
	Rational(int64_t num, int64_t denom) : num_(num), den_(denom) {
		div_zero(denom);
		reduce(num_, den_);
		to_double(num_, den_, doubl_);
	}
	Rational(int64_t num) : num_(num) {
		int64_t num_ = num;
		int64_t den_ = 1;
		to_double(num_, den_, doubl_);
	}


	// дробь должна быть несократимой
	void reduce(int64_t& num, int64_t& denom) {
		int64_t gcd_value = gcd(num, denom);
		num /= gcd_value;
		denom /= gcd_value;
	}

	// арифметика
	Rational operator+=(const Rational& rhs) {
		num_ = num_ * rhs.den_ + rhs.num_ * den_;
		den_ *= rhs.den_;
		reduce(num_, den_);
		return *this;
	}

	Rational operator-=(const Rational& rhs) {
		num_ = num_ * rhs.den_ - rhs.num_ * den_;
		den_ *= rhs.den_;
		reduce(num_, den_);
		return *this;
	}

	Rational operator*=(const Rational& rhs) {
		num_ *= rhs.num_;
		den_ *= rhs.den_;
		reduce(num_, den_);
		return *this;
	}

	Rational operator/=(const Rational& rhs) {
		num_ *= rhs.den_;
		den_ *= rhs.num_;
		reduce(num_, den_);
		return *this;
	}

	// сравнение
	bool operator==(const Rational& rhs) const {
		return (num_ * rhs.den_ == rhs.num_ * den_);
	}

	bool operator!=(const Rational& rhs) const {
		return !(*this == rhs);
	}

	bool operator<(const Rational& rhs) const {
		return (num_ * rhs.den_ < rhs.num_ * den_);
	}

	bool operator>(const Rational& rhs) const {
		return (num_ * rhs.den_ > rhs.num_ * den_);
	}

	bool operator<=(const Rational& rhs) const {
		return (num_ * rhs.den_ <= rhs.num_ * den_);
	}

	bool operator>=(const Rational& rhs) const {
		return (num_ * rhs.den_ >= rhs.num_ * den_);
	}

	// перевод дроби в double
	void to_double(int64_t& num, int64_t& den, double& doubl) const {
		doubl += static_cast<double>(num) / den;
	}

	// вывод числа
	void print() {
		std::cout << num_ << separator << den_ << "\n";
	}
	void print_double() {
		std::cout << doubl_ << "\n";
	}

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}


#endif