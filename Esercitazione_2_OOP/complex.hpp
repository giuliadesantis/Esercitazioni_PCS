#pragma once

// Classe per numeri complessi con template
template <typename T> requires std::floating_point<T> // Garantisce che T sia float o double
class complex_number 
{//privati
    T real;
    T imag; 

public:
    // definisco il costruttore di default
    complex_number() 
		: real(0), imag(0) //inizializza il numero complesso a 0+0i
	{} 
	
	explicit complex_number(T r)// 'explicit' per evitare la conversione automatica
		: real(r), imag(0) 
		{}
		
    // Costruttore user-defined per inizializzare la parte reale e immaginaria
    complex_number(T r, T i) 
		: real(r), imag(i) 
		{} //Prende due parametri r e i, che rappresentano rispettivamente la parte reale e immaginaria, poi inizializza i membri real e imag con i valori assegnati

    //restituisce la parte reale senza modificarla(restituisce un valore di tipo T)
    T real_part() const { 
		return real; 
		}

    // restituisce la parte immaginaria
    T imag_part() const { 
		return imag; 
		}

    // restituisce il coniugato (restituisce un numero complesso)
    complex_number conjugate() const {
        return 	complex_number(real, -imag);
    }

	// overload per peratore di somma +=
	complex_number& operator+=(const complex_number& other) {
		real = real + other.real;
		imag = imag + other.imag;
			return *this; // utilizzando return *this modifica direttamente l'oggetto corrente (il primo indicato tra i due) e non ne crea uno nuovo 
		// ad esempio facendo c1 += c2, viene aggiornato direttamente il valore di c1, secondo l'operazione indicata con c2
		}
	
	/*alternativa più compatta
	complex_number& operator+=(const complex_number& other) {
			real += other.real;
			imag += other.imag;
			return *this;
			}
	*/
	// overload peratore di somma +
	complex_number operator+(const complex_number& other) const {
		complex_number comp = *this;
		comp += other;
			return comp;
    } // esegue la somma tra numeri complessi (somma delle parti reali e delle parti immaginarie)

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
	complex_number& operator+=(const T& other) { //other è un numero di tipo T (non complesso)... viene sommato alla sola parte reale del numero complesso
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
		complex_number comp = *this; // Crea una copia dell'numero complesso a sinistra
		comp += other;
			return comp;
    }
	/* alternativa
		complex_number operator+(const T& other) const {
			return complex_number(real + other, imag);  // Crea un nuovo numero complesso con la parte reale aggiornata
		}	
	*/
	
	// overload operatore di moltiplicazione * con T a destra
    complex_number operator*(const T& other) const {
        return complex_number(real * other,imag * other);
    }
};


//overload peratore di somma + con T a sinistra
template<typename T>
complex_number<T> //viene restituito un numero di tipo complesso
operator+(const T& other, const complex_number<T>& comp) //il primo membro è un numero di tipo T e il secondo è un numero complesso
{
    return comp + other; //inverte la somma tra i due membri, per ricondursi al caso "somma tra numero complesso e numero T"
}	
	
//overload peratore di somma * con T a sinistra
template<typename T>
complex_number<T> //viene restituito un numero di tipo complesso
operator*(const T& other, const complex_number<T>& comp) //il primo membro è un numero di tipo T e il secondo è un numero complesso
{
    return comp * other; //inverte la somma tra i due membri, per ricondursi al caso "somma tra numero complesso e numero T"
}
	
//overload dell'operatore << per stampare un numero complesso nel giusto formato
template<typename T>
std::ostream& operator<<(std::ostream& os, const complex_number<T>& c) {
	os << c.real_part(); // restituisce la parte reale
	if (c.imag_part() >= 0)
		os << "+"; //se la parte immaginaria è positiva aggiunge il più e formatta
	os << c.imag_part() << "i"; //aggiunge parte immaginaria e i
	return os;
}
