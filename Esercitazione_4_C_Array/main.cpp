#include <iostream>
#include <fstream>
#include <sstream>
#include "src/Utils.hpp"

using namespace std;

int main()
{
	string inputFileName = "data.txt";
	size_t n = 0;
	double S = 0.0;
    double* w = nullptr;
    double* r = nullptr;
		
	
	if (!ImportVectors(inputFileName, S, n, w, r))
    {
        cerr<< "Errore nell'importazione dei dati da file"<< endl;
        return -1;
    }
    else{
	cout<< "Dati importati correttamente" << endl;
	}

    double rateOfReturn = RateOfReturn(n, w, r);
		
	string outputFileName = "result.txt";
    if (!ExportResult(outputFileName, S, n, w, r, rateOfReturn))
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

