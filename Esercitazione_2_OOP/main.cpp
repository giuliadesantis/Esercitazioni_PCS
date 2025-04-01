#include <iostream>
#include "complex.hpp"

int main() {
	complex_number<double> c0; //costruttore di default
	std::cout << "c0: " << c0 << std::endl;
		
    complex_number<double> c1(3.0, 4.0); 
	std::cout << "c1: " << c1 << std::endl;
	
    complex_number<double> c2(1.5, -2.5);
	std::cout << "c2: " << c2 << std::endl;
	
    complex_number<double> c3(-3.2, 1.4);
	std::cout << "c3: " << c3 << std::endl;
	
    complex_number<double> c4(1.9, -0.7);
	std::cout << "c4: " << c4 << std::endl;
	
	std::cout << "Coniugato di c1: " << c1.conjugate() << std::endl;
	std::cout << "Coniugato di c2: " << c2.conjugate() << std::endl;
	
	std::cout << "Parte reale di c1: Re(c1) = " << c1.real_part() << std::endl;
	std::cout << "Parte immaginaria di c1: Im(c1) = " << c1.imag_part() << std::endl;
	
	
    complex_number<double> c5 = c1 + c2;
	std::cout << "c1 + c2: " << c5 << " (somma tra due numeri complessi con operatore +)" << std::endl; 
    complex_number<double> c6 = c3 * c4;
    std::cout << "c3 * c4: " << c6 << " (prodotto tra due numeri complessi con operatore *)" <<std::endl;
    
	c1 += c2;
	std::cout << "c1 += c2: " << c1 << " (somma tra due numeri complessi con operatore +=)" << std::endl; 
    c3 *= c4;
    std::cout << "c3 *= c4: " << c3 << " (prodotto tra due numeri complessi con operatore *=)" <<std::endl;
   	
	double k = 2;
    complex_number<double> c(2.5, 4.3); 
		
	std::cout << "k: " << k << std::endl;
	std::cout << "c: " << c << std::endl;
	
	
	complex_number<double> c7 = c + k;
	std::cout << "c + k: " << c7 << " (somma tra un numero complesso e uno scalare k con operatore +)" << std::endl;
    complex_number<double> c8 = c * k;
    std::cout << "c * k: " << c8 << " (prodotto tra un numero complesso e uno scalare k con operatore *)" <<std::endl;
	
	complex_number<double> c9 = k + c;
	std::cout << "k + c: " << c9 << " (somma tra uno scalare k e un numero complesso con operatore +)" << std::endl;
    complex_number<double> c10 = k * c;
    std::cout << "k * c: " << c10 << " (prodotto tra uno scalare k e un numero complesso con operatore *)" <<std::endl;
	
    return 0;
}
