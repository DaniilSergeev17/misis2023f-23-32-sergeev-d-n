#include <iostream>
#include <sstream>
#include "complex/complex.hpp"

bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good()) {
		cout << "Read success: " << str << " -> " << z << endl;
	}
	else {
		cout << "Read error : " << str << " -> " << z << endl;
	}
	return istrm.good();
}

int main() {
	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9,9");
	// òåñòû îïåðàòîðîâ (+=, +, -, *, /)
	Complex z;
	Complex z2;
	std::cout << z << "\n";
	std::cout << z2 << "\n";
	z += Complex(8.0, 5);
	z2 += Complex(9.0, 6);
	std::cout << z << "  " << 'z' << "\n";
	std::cout << z2 << "  " << "z2" << "\n";
	std::cout << z - z2 << "  " << "z - z2" << "\n";
	std::cout << z * z2 << "  " << "z * z2" << "\n";
	std::cout << z / z2 << "  " << "z / z2" << "\n";
	z2 -= Complex(1.0, 1);
	std::cout << z2 << "  " << "z2 -= (1, 1)" << "\n";
}

