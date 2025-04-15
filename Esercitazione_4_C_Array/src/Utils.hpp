#pragma once

#include <iostream>

using namespace std;
/* 
	ImportVectors legge il file in input dove sono scritti i vettori 
	utili alla risoluzione del problema
	- inputFilePath: path name del file input
	- S: valore iniziale investito
	- n: dimensione del vettore
	- w: frazione di S investita
	- r: "rate of return" di ogni investimento */
bool ImportVectors(const string& inputFilePath,
                   double& S,
                   size_t& n,
                   double*& w,
                   double*& r,
				   string& nome1,
				   string& nome2,
				   string& nome3, 
				   string& nome4);
				   
/*
	RateOfReturn calcola il tasso di rendimento a partire dai dati forniti
	- n: dimensione del vettore
	- S: valore iniziale investito
	- w: frazione di S investita
	- r: "rate of return" di ogni investimento
	
*/
double RateOfReturn(const size_t& n,
                    const double* const& w,
                    const double* const& r);

/*
	ExportResult esporta i risultati richiesti in un file di outputFilePath
	- outputFilePath: path name del file in output
	- S: valore iniziale investito
	- n: dimensione del vettore
	- w: frazione di S investita
	- r: "rate of return" di ogni investimento
	- rateOfReturn: tasso di rendimento calcolato
	
*/
bool ExportResult(const string& outputFilePath,
                  const double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& rateOfReturn,
				  const string& nome1,
				  const string& nome2,
				  const string& nome3, 
				  const string& nome4);	
						
						