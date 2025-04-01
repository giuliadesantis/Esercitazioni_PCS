#pragma once

// Classe per numeri complessi con template
template <typename T> requires std::floating_point<T> 
class complex_number 
{//privati
    T real;
    T imag; 

public:
    // definisco il costruttore di default
    complex_number() 
		: real(0), imag(0)
	{} 
	
	explicit complex_number(T r)
		: real(r), imag(0) 
		{}
		
    // Costruttore user-defined per inizializzare la parte reale e immaginaria
    complex_number(T r, T i) 
		: real(r), imag(i) 
		{} 

    //restituisce la parte reale senza modificarla(restituisce un valore di tipo T)
    T real_part() const { 
		return real; 
		}

    // restituisce la parte immaginaria
    T imag_part() const { 
		return imag; 
		}

    // restituisce il coniugato 
    complex_number conjugate() const {
        return 	complex_number(real, -imag);
    }

	// overload per peratore di somma +=
	complex_number& operator+=(const complex_number& other) {
		real = real + other.real;
		imag = imag + other.imag;
			return *this;
		}
	
	// overload peratore di somma +
	complex_number operator+(const complex_number& other) const {
		complex_number comp = *this;
		comp += other;
			return comp;
    }

	// overload operatore di moltiplicazione *=
    complex_number& operator*=(const complex_number& other) {
		T newReal = real * other.real - imag * other.imag;
        T newImag = real * other.imag + imag * other.real;
        real = newReal;
        imag = newImag;
		return *this; 
    }

	// overload operatore di moltiplicazione *
    complex_number operator*(const complex_number& other) const {
        return complex_number(real * other.real - imag * other.imag,real * other.imag + imag * other.real);
    }
	
	// commutatività
	
	// overload operatore di moltiplicazione += con numero T a destra 
	complex_number& operator+=(const T& other) { 
		real += other;
        return *this;
	}
		
	// overload operatore di moltiplicazione *= con numero T a destra
    complex_number& operator*=(const T& other) {
        real = real * other;
        imag = imag * other;
        return *this; 
    }

	// overload peratore di somma + con T a destra
	complex_number operator+(const T& other) const {
		complex_number comp = *this;
		comp += other;
			return comp;
    }
	
	// overload operatore di moltiplicazione * con T a destra
    complex_number operator*(const T& other) const {
        return complex_number(real * other,imag * other);
    }
};


//overload peratore di somma + con T a sinistra
template<typename T>
complex_number<T> 
operator+(const T& other, const complex_number<T>& comp) 
{
    return comp + other; 
}	
	
//overload peratore di somma * con T a sinistra
template<typename T>
complex_number<T> 
operator*(const T& other, const complex_number<T>& comp) 
{
    return comp * other; 
}
	
//overload dell'operatore << per stampare un numero complesso 
template<typename T>
std::ostream& operator<<(std::ostream& os, const complex_number<T>& c) {
	os << c.real_part();
	if (c.imag_part() >= 0)
		os << "+"; 
	os << c.imag_part() << "i";
	return os;
}
