#include <iostream>
#include "rational.hpp"

int main() {
	//Rational r1(1, 0); // проверка на ноль в знаменателе
	Rational r2(2, 1);
	Rational r3(0, 1);
	Rational r4(6, 8); // должно быть 3/4
	Rational r5(32, 8); // 4/1
	Rational r6 = r2 + r4; // 11/4
	Rational r7 = r2 + r3; // 2/1
	Rational a(1, 9);
	Rational b(2, 7);
	Rational r8 = a - b; // -11/63
	Rational r9 = a * b; // 2/63
	Rational c(1, 9);
	Rational d(2, 7);
	Rational r10 = c / d; // 7/18
	Rational e; // конструктор по умолчанию
	Rational r11(4); // 4/1
	Rational r12(2, 3); // перевод в double --> 0.666...667
	Rational r13(2, 6);
	r13 += r12; // 1/1
	Rational r14(5, 6);
	r14 -= r13; // -1/6
	Rational r15(5, 2);
	r15 *= r14; // -5/12
	Rational r16(2, 12);
	r16 /= r15; // -2/5

	r2.print();
	r3.print();
	r4.print();
	r5.print();
	r6.print();
	r7.print();
	r8.print();
	r9.print();
	r10.print();
	e.print();
	r11.print();
	r12.print_double();
	r13.print();
	r14.print();
	r15.print();
	r16.print();
}