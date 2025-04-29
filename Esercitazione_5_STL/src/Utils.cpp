#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

namespace PolygonalLibrary{
	
bool ImportMesh(PolygonalMesh& mesh)
{
	if(!ImportCell0Ds(mesh)){
		return false;
	}
	else {
		cout << "Cell0D marker:" << endl;
		if (mesh.Cell0DsMarker.size() != 0){
			for(auto it = mesh.Cell0DsMarker.begin(); it != mesh.Cell0DsMarker.end(); it++)
			{
				cout << "marker id:\t" << it -> first << "\t valori:";
				for(const unsigned int id : it -> second)
					cout << id << "\t" ;

				cout << endl;
			}
		}
		else{
			cout << "Nessun marker non nullo trovato" << endl;
		}
	}
	
	if(!ImportCell1Ds(mesh)){
		return false;
	}
	else {
		cout << "Cell1D marker:" << endl;
		if (mesh.Cell1DsMarker.size() != 0){
			for(auto it = mesh.Cell1DsMarker.begin(); it != mesh.Cell1DsMarker.end(); it++)
			{
				cout << "marker id:\t" << it -> first << "\t valori:";
				for(const unsigned int id : it -> second)
					cout << id << "\t";

				cout << endl;
			}
		}
		else{
			cout << "Nessun marker non nullo trovato" << endl;
		}
	}
	
	if(!ImportCell2Ds(mesh)){
		return false;
	}
	else {
		cout << "Cell2D marker:" << endl;
		if (mesh.Cell2DsMarker.size() != 0){
			for(auto it = mesh.Cell2DsMarker.begin(); it != mesh.Cell2DsMarker.end(); it++)
			{
				cout << "marker id:\t" << it -> first << "\t valori:";
				for(const unsigned int id : it -> second)
					cout << id << "\t";

				cout << endl;
			}
		}
		else{
			cout << "Nessun marker non nullo trovato" << endl;
		}
	}
	
    return true;

}
// ***************************************************************************

bool ImportCell0Ds(PolygonalMesh& mesh)//importo i punti della mesh
{
	ifstream file;
	file.open("./Cell0Ds.csv");

	if(file.fail())
		return false;
	
	list<string> listLines; //leggo tutte le righe e memorizzo in una lista temporanea(per conoscere il numero di righe)
	string line;
	while (getline(file, line))
		listLines.push_back(line);

	file.close();

	listLines.pop_front();//rimuovo header

	mesh.NumCell0Ds = listLines.size();//ricavo il numero di punti da memorizzare NumCell0Ds

	if (mesh.NumCell0Ds == 0)
	{
		cerr << "Non sono presenti Cell0D nel file" << endl;
		return false;
	} //controllo che il file non sia vuoto e che ci sia  almeno un punto da memorizzare

	mesh.Cell0DsId.reserve(mesh.NumCell0Ds);//ridimensiono la capacità necessaria per il vettore
	mesh.Cell0DsCoordinates = Eigen::MatrixXd::Zero(3, mesh.NumCell0Ds);//salvo le coordinate x e y per gli n punti contenuti nel file (z è pari a 0 perchè 2D)

	for (const string& line : listLines)
	{
		istringstream converter(line); //istringstream legge l'id e il marker, poi coordinata x e y

		unsigned int id;//inizializzo la variabile per l'id
		unsigned int marker;//inizializzo la variabile per il marker
		char tmp;//per il carattere ";"
		
		converter >>  id >> tmp >> marker >> tmp >> mesh.Cell0DsCoordinates(0, id) >> tmp >> mesh.Cell0DsCoordinates(1, id);
		mesh.Cell0DsId.push_back(id);

		/// Memorizza i marker
		//ogni marker è la chiave, a cui viene collegato il valore dei punti associati a quello 
		//per i punti, i marker vanno da 1 a 8
		
		if(marker != 0)//se il marker è = 0 non lo memorizzo 
		{
			const auto it = mesh.Cell0DsMarker.find(marker);//cerca all'interno della mappa e restituisce l'iteratore dell'elemento che si vuole trovare, altrimenti se non lo trova, restituisce "end"
			if(it!=mesh.Cell0DsMarker.end())
			{
				//mesh.Cell0DsMarker[marker].push_back(id);//aggiorno il valore relativo alla chiave
				it -> second.push_back(id); //le due soluzioni sono equivalenti
			}
			else 
			{
				mesh.Cell0DsMarker.insert({marker,{id}});//inserisce un nuovo marker se non ancora presente nella mappa
			}
		}
	}
    return true;
}
// ***************************************************************************
bool ImportCell1Ds(PolygonalMesh& mesh)
{
	ifstream file;
	file.open("./Cell1Ds.csv");

	if(file.fail())
		return false;

    	list<string> listLines;
	string line;
   	while (getline(file, line))
        	listLines.push_back(line);

    	file.close();

    	listLines.pop_front();// rimuovo header

    	mesh.NumCell1Ds = listLines.size();

    	if (mesh.NumCell1Ds == 0)
    	{
        	cerr << "Non sono presenti Cell1D nel file" << endl;
        	return false;
    	}

    	mesh.Cell1DsId.reserve(mesh.NumCell1Ds);
    	mesh.Cell1DsExtrema = Eigen::MatrixXi(2, mesh.NumCell1Ds);//per memorizzare i due estremi per ogni lato
	
	unsigned int k1 = 0; // contatore lati di lunghezza nulla
    	for (const string& line : listLines)
    	{
        	istringstream converter(line);

        	unsigned int id;
        	unsigned int marker;
			char tmp;

        	converter >>  id >> tmp >> marker >> tmp >> mesh.Cell1DsExtrema(0, id) >> tmp >> mesh.Cell1DsExtrema(1, id);
        	mesh.Cell1DsId.push_back(id);
	
		// Memorizza i marker
		if(marker != 0)//se il marker è = 0 non lo memorizzo 
		{
			const auto it = mesh.Cell1DsMarker.find(marker);//cerca all'interno della mappa e restituisce l'iteratore dell'elemento che si vuole trovare, altrimenti se non lo trova, restituisce "end"
			if(it!=mesh.Cell1DsMarker.end())
			{
				mesh.Cell1DsMarker[marker].push_back(id);
				//it -> second.push_back(id);
			}
			else 
			{
				mesh.Cell1DsMarker.insert({marker,{id}});//inserisce un nuovo marker se non ancora presente nella mappa
			}
		}
		
		//Test lunghezza lati non nulla 
		if(mesh.Cell1DsExtrema(0, id) == mesh.Cell1DsExtrema(1, id)){
			cout << "TEST FALLITO: il lato " << id << "ha lunghezza nulla!" << endl;
			k1++;
			//itero su tutti i lati, e se ne trovo che hanno lunghezza nulla, aumento il contatore di 1
		}	
	
    }
	
	if(k1 == 0){
		cout << "Tutti i lati della mesh hanno lunghezza non nulla - TEST PASSATO!" << endl;
	}
		
	return true;
}
// ***************************************************************************
bool ImportCell2Ds(PolygonalMesh& mesh)
{
    	ifstream file;
	file.open("./Cell2Ds.csv");

    	if(file.fail())
        	return false;

    	list<string> listLines;
    	string line;
    	while (getline(file, line))
        	listLines.push_back(line);

    	file.close();

    	listLines.pop_front();//rimuovo header

    	mesh.NumCell2Ds = listLines.size();//numero di poligoni della mesh

    	if (mesh.NumCell2Ds == 0)
    	{
        	cerr << "Non sono presenti Cell2D nel file" << endl;
        	return false;
    	}

    	mesh.Cell2DsId.reserve(mesh.NumCell2Ds);
    	mesh.Cell2DsVertices.reserve(mesh.NumCell2Ds);
    	mesh.Cell2DsEdges.reserve(mesh.NumCell2Ds);

	unsigned int k2 = 0;
    	for (const string& line : listLines)
    	{
        	istringstream converter(line);

        	unsigned int id;
			unsigned int marker;
			char tmp;
			unsigned int numVert;//numero di vertici del poligono corrente
			unsigned int numEdg;//numero di lati del poligono corrente
			vector<unsigned int> vertices;
			vector<unsigned int> edges;

			converter >> id >> tmp >> marker >> tmp >> numVert;
			vertices.reserve(numVert);
			unsigned int vert;
        	for(unsigned int i = 0; i < numVert; i++){
				converter >> tmp >> vert;
				vertices.push_back(vert);
			}
		
			converter >> tmp >> numEdg;
			edges.reserve(numEdg);
			unsigned int edg;
			for(unsigned int i = 0; i < numEdg; i++){
            	converter >> tmp >> edg;
				edges.push_back(edg);
			}

			mesh.Cell2DsId.push_back(id);
			mesh.Cell2DsVertices.push_back(vertices);
			mesh.Cell2DsEdges.push_back(edges);
		
			if(marker != 0)//se il marker è = 0 non lo memorizzo 
			{
				const auto it = mesh.Cell2DsMarker.find(marker);//cerca all'interno della mappa e restituisce l'iteratore dell'elemento che si vuole trovare, altrimenti se non lo trova, restituisce "end"
				if(it!=mesh.Cell2DsMarker.end())
				{
					mesh.Cell2DsMarker[marker].push_back(id);
					//it -> second.push_back(id);
				}
				else 
				{
					mesh.Cell2DsMarker.insert({marker,{id}});//inserisce un nuovo marker se non ancora presente nella mappa
				}
			} 
		
			///Test area poligono non nulla (scompongo ogni poligono in triangoli e poi sommo le aree)
			
			double area = 0.0;
			
			for(unsigned int i = 0; i < numVert; i++){
						
				unsigned int j = (i+1)%numVert; //con operatore modulo % chiudo il poligono
			
				//ricavo le coordinate dei vertici (memorizzate in Cell0DsCoordinates)
				const MatrixXd& coord = mesh.Cell0DsCoordinates;
				double xi = coord(0, vertices[i]);
				double yi = coord(1, vertices[i]);
				double xj = coord(0, vertices[j]);
				double yj = coord(1, vertices[j]);
			
				area += (xi * yj) - (xj * yi);		
		
			}
			area = abs(area) * 0.5;
			//cout << "area poligono " << id << " = " << area << endl;
		
			if (area < 1e-16)
			{
				cerr << "TEST FALLITO: Il poligono con id " << id << " ha area nulla!" << endl;
				k2++;
				return false;
			}	
			
		}
		if(k2 == 0){
			cout << "Tutti i poligoni della mesh area non nulla - TEST PASSATO!" << endl;
		}
	return true;
}

}