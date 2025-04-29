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

    make_heap(v.begin(), v.end()); // trasforma v in un heap

    for (size_t i = 0; i < n; ++i) {
        pop_heap(v.begin(), v.end() - i); // dequeue
    }
}

}


