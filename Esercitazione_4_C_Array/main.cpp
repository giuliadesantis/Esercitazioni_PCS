#include <iostream>
#include <fstream>
#include <sstream>
#include "src/Utils.hpp"

using namespace std;

int main()
{
	string inputFileName = "./data.txt";
	size_t n = 0;
	double S = 0.0;
    double* w = nullptr;
    double* r = nullptr;
	
	string nome1;
	string nome2;
	string nome3;
	string nome4;
		
	
	if (!ImportVectors(inputFileName, S, n, w, r, nome1, nome2, nome3, nome4))
    {
        cerr<< "Errore nell'importazione dei dati da file"<< endl;
        return -1;
    }
    else{
	cout<< "Dati importati correttamente" << endl;
	}

    double rateOfReturn = RateOfReturn(n, w, r);
		
	string outputFileName = "./result.txt";
    if (!ExportResult(outputFileName, S, n, w, r, rateOfReturn, nome1, nome2, nome3, nome4))
    {
        cerr<< "Errore nell'esportazione dei dati da file"<< endl;
        return -1;
    }
    else{
        cout<< "Dati esportati correttamente"<< endl;
	}
	
	
	delete[] w;
    delete[] r;
    return 0;
}

