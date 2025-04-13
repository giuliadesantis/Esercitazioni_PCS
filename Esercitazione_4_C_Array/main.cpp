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
        cerr<< "Something goes wrong with import"<< endl;
        return -1;
    }
    else{
	cout<< "Import successful" << endl;
	}

    double rateOfReturn = RateOfReturn(n, w, r);
	
	
	string outputFileName = "result.txt";
    if (!ExportResult(outputFileName, S, n, w, r, rateOfReturn))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    else{
        cout<< "Export successful"<< endl;
	}
	
	
	delete[] w;
    delete[] r;
    return 0;
}

