#pragma once

#include <iostream>
#include "Eigen/Eigen"

#include <vector>
#include <list>
#include <map>

using namespace std;
using namespace Eigen;


namespace PolygonalLibrary {

struct PolygonalMesh
{
	unsigned int NumCell0Ds = 0; //numero di Cell0D 
	vector<unsigned int> Cell0DsId =  {}; //id vertici (vettore 1 x NumCell0D)
	MatrixXd Cell0DsCoordinates = {}; //matrice coordinate dei punti (matrice 2 x NumCell0Ds), perchè ho 2 coordinate per ogni punto
	map<unsigned int, list<unsigned int>> Cell0DsMarker = {}; //salva i marker per ogni punto
	
	unsigned int NumCell1Ds = 0;//numero di Cell1D
	vector<unsigned int> Cell1DsId = {};//id lati (vettore 1 x NumCell1D)
	MatrixXi Cell1DsExtrema = {};//estremi dei lati (matrice 2 x NumCell1Ds) - dall'id(i) all'id(j)
	map<unsigned int, list<unsigned int>> Cell1DsMarker = {}; //salva i marker per ogni segmento
	
	unsigned int NumCell2Ds = 0;//numero poligoni
	vector<unsigned int> Cell2DsId = {};//id poligoni
	vector<vector<unsigned int>> Cell2DsVertices = {};//vertici del poligono (lista di liste)
	vector<vector<unsigned int>> Cell2DsEdges = {};//lati del poligono (lista di liste)
	map<unsigned int, list<unsigned int>> Cell2DsMarker = {}; //salva i marker per ogni poligono
};

}

