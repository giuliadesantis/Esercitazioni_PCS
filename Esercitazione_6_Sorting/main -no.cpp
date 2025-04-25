#include <cmath> // contiene floor
#include <iostream>
#include <numeric> // contiene iota
#include <sstream>
#include <chrono> // https://en.cppreference.com/w/cpp/chrono

/*come si prende il tempo dell'algoritmo?
	si può calcolare il tempo medio che è impiegato dalle varie esecuzioni che provo
*/

/* gli orologi hanno un tempo 0 che è 1 gennaio 1970
esistono dei convertitori che dicono quanto tempo è passato da quella data
(è un riferimento temporale preso per convenzione)
*/
//cmake -S ./ -B Debug -DCMAKE_BUILD_TYPE=Debug
//cmake -S ./ -B Relase -DCMAKE_BUILD_TYPE=Relase ??

#include "SortingAlgorithm.hpp"
using namespace std;
/*
template<typename T>
string ArrayToString(const vector<T>& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (const T& e: v)
        toString << e << " ";
    toString << "]";

    return toString.str();
} //trasforma l'array in stringa */

int main(int argc, char *argv[]) //cos'è argc?argv?
{
	
	cout << "argc: " << argc << endl;
	for (int a = 0;a < argc;a++)
		cout << argv[a] << endl;

    size_t m = 10;

	istringstream st(argv[1]);
	st >> m;
	//voglio testare il codice con 3 vettori



	//caso 1) vettore già ordinato (caso migliore possibile)
    vector<int> v1(m);
	
	std::iota(v1.begin(),v1.end(),1); 
	/*iota in C++ è un algoritmo della libreria standard che viene utilizzato per 
	riempire un intervallo di elementi con valori crescenti, a partire da un valore 
	iniziale specificato. 
	-v1.begin():first: iteratore che punta all'inizio dell'intervallo da riempire.
	-v1.end(): iteratore che punta alla fine dell'intervallo (non incluso) da riempire.
	-"1": Il valore iniziale da cui partire per la sequenza di valori.
	*/

    cout << "v1: " << endl;
    for (int val : v1) {
		cout << val << " ";
    }
    cout << endl;


	//caso 2): vettore random
    vector<double> v2(m);
	for(unsigned int i = 0; i < m; i++)
		v2[i] = rand(); //restituisce un valore tra 0 e rand_max - è un numero intero, non un double
		//se voglio un valore tra 0 e 1: rand()/((double)rand_max)
    cout << "v2: " << endl;
    for (int val : v2) {
        cout << val << " ";
    }
    cout << endl;

    //caso 3): vettore ordinato nel verso opposto a quello cercato
	vector<int> v3(m);
	std::iota(v3.begin(),v3.end(),1);
	reverse(v3.begin(), v3.end());
		

    cout << "v3: " << endl;
    for (int val : v3) {
        cout << val << " ";
    }
    cout << endl;




	//ora calcolo il tempo impiegato
/*
    unsigned int num_experiment = 100;

    double time_elapsed_bubble_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v1 /= num_experiment;

    cout << "Bubble Sort - v1: " << time_elapsed_bubble_v1 << endl;

    double time_elapsed_bubble_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v2 /= num_experiment;

    cout << "Bubble Sort - v2: " << time_elapsed_bubble_v2 << endl;


    double time_elapsed_bubble_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v3 /= num_experiment;

    cout << "Bubble Sort - v3: " << time_elapsed_bubble_v3 << endl;
*/





    /*double time_elapsed_insertion_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::InsertionSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_insertion_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_insertion_v1 /= num_experiment;

    cout << "Insertion Sort - v1: " << time_elapsed_insertion_v1 << endl;

    double time_elapsed_insertion_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::InsertionSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_insertion_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_insertion_v2 /= num_experiment;

    cout << "Insertion Sort - v2: " << time_elapsed_insertion_v2 << endl;


    double time_elapsed_insertion_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::InsertionSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_insertion_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_insertion_v3 /= num_experiment;

    cout << "Insertion Sort - v3: " << time_elapsed_insertion_v3 << endl;
*/

    return 0;
}

