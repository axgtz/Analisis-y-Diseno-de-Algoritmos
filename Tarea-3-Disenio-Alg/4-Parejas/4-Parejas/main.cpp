//Roberto Alejandro Gutierrez Guillen       A01019608
#include <iostream>
#include <vector>
using namespace std;
/*Supongamos que tenemos n hombres y n mujerActuales y dos matrices M y H que contienen las preferencias de los 
unos por los otros. Más concretamente, la fila M[i,·] es una ordenación (de mayor a menor) de las mujerActuales 
según las preferencias del i-ésimo hombre y, análogamente, la fila H[i,·] es una ordenación (de mayor a menor)
de los hombres según las preferencias de la i-ésima mujerActual.

Diseñe un algoritmo que encuentre, si es que existe, un emparejamiento de hombres y mujerActuales tal que todas
las parejas formadas sean estables. Una pareja (h,m) es estable si no se da ninguna de estas dos circunstancias:

Existe una mujerActual m’ (que forma la pareja (h’,m’)) tal que el hombre h la prefiere sobre la mujerActual m y además 
la mujerActual m’ también prefiere a h sobre h’.
Existe un hombre h” (que forma la pareja (h”,m”)) tal que la mujerActual m lo prefiere sobre el hombre h y además 
el hombre h” también prefiere a m sobre la mujerActual m”. */
//Tecnica:Backtracking
//Complejidad O(n^2)
//Basado en algoritmo Gale–Shapley 


//Foward Declaration de funciones
bool mujerActualElige(vector<vector<int>> preferencias, int mujerActual, int esposo, int nuevoHombre);
void parejas();
#define NUMPAREJAS 4
vector<vector<int>> preferencia = { { 7, 5, 6, 4 },{ 5, 4, 6, 7 },{ 4, 5, 6, 7 },{ 4, 5, 6, 7 },{ 0, 1, 2, 3 },
{ 0, 1, 2, 3 },{ 0, 1, 2, 3 },{ 0, 1, 2, 3 } };

int main(){

	parejas();

	return 0;
}

void parejas(){
	vector<int> esposoDemujerActuales;
	vector<bool> hombresSolteros;

	//Se inicializa vector con todos los hombres y mujerActuales solteros
	for (int i = 0; i < NUMPAREJAS; i++){
		esposoDemujerActuales.push_back(-1);
		hombresSolteros.push_back(false);
	}

	int hombresSinPareja = NUMPAREJAS;

	while (hombresSinPareja > 0){
		int nuevoHombre;
		for (nuevoHombre = 0; nuevoHombre < NUMPAREJAS; nuevoHombre++)
			if (hombresSolteros[nuevoHombre] == false)
				break;
		for (int i = 0; i < NUMPAREJAS && hombresSolteros[nuevoHombre] == false; i++){
			int mujerActual = preferencia[nuevoHombre][i];

			if (esposoDemujerActuales[mujerActual - NUMPAREJAS] == -1){
				esposoDemujerActuales[mujerActual - NUMPAREJAS] = nuevoHombre;
				hombresSolteros[nuevoHombre] = true;
				hombresSinPareja--;
			}else {
				int esposo = esposoDemujerActuales[mujerActual - NUMPAREJAS];
				if (mujerActualElige(preferencia, int mujerActual, int esposo, int nuevoHombre) == false){
					esposoDemujerActuales[mujerActual - NUMPAREJAS] = nuevoHombre;
					hombresSolteros[nuevoHombre] = true;
					hombresSolteros[esposo] = false;
				}
			}
		} 
	}
	cout << "mujerActual  -  Hombre" << endl;
	for (int i = 0; i < NUMPAREJAS; i++)
		cout << i + NUMPAREJAS << " - " << esposoDemujerActuales[i] << endl;
}

bool mujerActualElige(vector<vector<int>> preferencias, int mujerActual, int esposo, int nuevoHombre) {
	for (int i = 0; i < NUMPAREJAS; i++) {
		if (preferencias[mujerActual][i] == esposo)
			return true;
		if (preferencias[mujerActual][i] == nuevoHombre)
			return false;
	}
}