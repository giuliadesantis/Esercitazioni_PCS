#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>


double map_values(double& x){
	int a = 1;
	int b = 5;
	int c = -1;
	int d = 2;
	return ((c-d)*x+a*d-b*c)/(a-b); // la formula per passare da [a,b] a [c,d] è: x' = [(c-d)*x+a*d-b*c]/(a-b)
}

int main()
{
	std::ifstream file("data.txt");
	if (file.fail()) // per controllare se il file di input si apre correttamente
	{
		std::cerr << "errore nell'apertura del file" << std::endl;
		return 1;
	}

	
	std::string fileOutput = "result.txt"; //crea il file di output
	std::ofstream ofs(fileOutput);
	if (!ofs) { // Controllo se il file di output si apre correttamente
        	std::cerr << "Errore nell'apertura del file result.txt" << std::endl;
        	return 1;
    	}

	double val; //creo variabile ausiliaria dove vado a memorizzare i valori letti dal file
	double mean = 0.0;
	unsigned int k = 1;
	double x = 0.0;
	ofs << "# N Mean" << std::endl;
	while (file >> val) { 
        x = map_values(val);
		mean = (mean * (k-1) + x)/k;
		ofs << k << " " << std::scientific << std::setprecision(16) << mean << std::endl;
				
		k++;
	}
	file.close();
	ofs.close();
    	return 0;
}