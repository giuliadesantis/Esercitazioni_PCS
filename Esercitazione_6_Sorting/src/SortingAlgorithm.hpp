#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace SortLibrary {
	
template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};

//Bubble Sort

template<Sortable T>
void BubbleSort(vector<T>& v) 
{
	const unsigned int n = v.size();
	for (size_t i = 0; i < n - 1; i++) {
		for (size_t j = i+1; j < n; j++) {
			if (v[j] < v[i]) {	
				//swap:
				const T tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
}

//Heap Sort (implementato con funzioni relative agli heap, da documentazione online)

template<Sortable T>
void HeapSort(vector<T>& v) 
{
    const unsigned int n = v.size();

    make_heap(v.begin(), v.end());
	 /* trasforma v in un heap, dove il primo elemento v[0] è il più grande,
	 mentre gli altri elementi soddisfano la proprietà degli heap*/

    for (size_t i = 0; i < n; ++i) {
        pop_heap(v.begin(), v.end() - i); // dequeue
		/*
		sposto l'elemento massimo alla porzione v.end()-i-1, e riordino il resto del vettore affinché sia 
		mantenuta la proprietà di heap... iterando così, alla fine del ciclo ottengo il vettore v ordinato in modo crescente
		
		Non rimuovo l'elemento, ma lo sposto nel posto "corretto" per l'ordinamento, restringendo il renge dell'heap a ogni iterazione
		*/
    }
}

}


