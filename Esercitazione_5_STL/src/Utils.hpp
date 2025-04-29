#pragma once

#include <iostream>
#include "PolygonalMesh.hpp"

using namespace std;

namespace PolygonalLibrary
{
/// Importa la polygonal mesh e verifica che la mesh sia corretta
/// mesh: PolygonalMesh struct
/// restituisce il risultato della lettura, true se ha successo, false altrimenti
bool ImportMesh(PolygonalMesh& mesh);

/// Importa le proprietà dei vertici (Cell0D) dal file Cell0Ds.csv
/// mesh: PolygonalMesh struct
/// restituisce il risultato della lettura, true se ha successo, false altrimenti
bool ImportCell0Ds(PolygonalMesh& mesh);

/// Importa le proprietà dei lati (Cell1D) dal file Cell1Ds.csv
/// mesh: PolygonalMesh struct
/// restituisce il risultato della lettura, true se ha successo, false altrimenti
bool ImportCell1Ds(PolygonalMesh& mesh);

/// Importa le proprietà dei poligoni (Cell2D) dal file Cell2Ds.csv
/// mesh: PolygonalMesh struct
/// restituisce il risultato della lettura, true se ha successo, false altrimenti
bool ImportCell2Ds(PolygonalMesh& mesh);
}

