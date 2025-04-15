#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "string"
#include "iomanip"

using namespace std;

//importo i vettori leggendoli dal file fornito 
bool ImportVectors(const string& inputFilePath,
                   double& S,
                   size_t& n,
                   double*& w,
                   double*& r,
				   string& nome1,
				   string& nome2,
				   string& nome3, 
				   string& nome4)
{
    ifstream file; //Apro il file
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr<< "Errore nell'apertura del file"<< endl;
        return false;
    }
	
	//Leggo la somma iniziale investita S
	string line;
	getline(file, line);//leggo la prima riga del file
	stringstream ss1(line);
	//string nome1;
	
	getline(ss1, nome1, ';'); // legge fino a ';'
	ss1 >> S;
	
	// Leggo il numero di elementi
	getline(file, line);//leggo la seconda riga del file
	stringstream ss2(line);
	//string nome2;
	getline(ss2, nome2, ';'); //il primo carattere della stringa viene assegnato a nome
	ss2 >> n;
	
	// Leggo il nome dei vettori dal file
	//string nome3;
	//string nome4;
	getline(file, line);
	stringstream ss3(line);
	getline(ss3, nome3, ';'); //il primo carattere della stringa viene assegnato a nome
	ss3 >> nome4;
	
	//creo i vettori w e r, di dimensione name
	
	w = new double[n];
	r = new double[n];
	
	for (size_t k = 0; k < n && getline(file, line); ++k) {
    stringstream ssi(line);
    ssi >> w[k];
    ssi.ignore();
    ssi >> r[k];
	}
	
	
	file.close();

    return true;
}

double RateOfReturn(const size_t& n,
                    const double* const& w,
                    const double* const& r)
{
    double rateOfReturn = 0.0;
    for (unsigned int i = 0; i < n; i++)
	{		
        rateOfReturn += w[i]* r[i];
	}
    return rateOfReturn;
}

bool ExportResult(const string& outputFilePath,
                  const double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& rateOfReturn,
				  const string& nome1,
				  const string& nome2,
				  const string& nome3, 
				  const string& nome4)
{
    // apro file output
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "errore nell'apertura del file"<< endl;
        return false;
    }

    file << fixed << setprecision(2) << nome1 << " = "<< S << ", " << nome2 << " = " << n << endl; 

    file<< nome3 << " = [" << " ";
    for (unsigned int i = 0; i < n; i++)
        file << (i != 0 ? " " : "") << w[i] << " ";
    file << "] " << endl;

    file<< nome4 << " = ["<< " ";
    for (unsigned int i = 0; i < n; i++)
        file<< (i != 0 ? " " : "")<< r[i] << " ";
    file << "]"<< endl;

    file << setprecision(4) << fixed << "Rate of return of the portfolio: " << rateOfReturn << endl;
    file << setprecision(2) << fixed << "V: " << S*(1 + rateOfReturn) << endl;

    file.close();

    return true;
}
