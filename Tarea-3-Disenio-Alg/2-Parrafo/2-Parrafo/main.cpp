//Roberto Alejandro Gutierrez Guillen       A01019608
/*Dada una secuencia de palabras p1, p2, ..., pn de longitudes l1, l2, ..., ln se desea agruparlas en líneas de longitud L. 
Las palabras están separadas por espacios cuya amplitud ideal (en milímetros) es b, pero los espacios pueden reducirse o 
ampliarse si es necesario (aunque sin solapamiento de palabras), de tal forma que una línea pi, pi+1, ..., pj tenga exactamente
longitud L. Sin embargo, existe una penalización por reducción o ampliación en el número total de espacios que aparecen o 
desaparecen. El costo de fijar la línea pi, pi+1, ..., pj es (j – i)|b’ – b|, siendo b’ el ancho real de los espacios, es 
decir (L – li – li+1 – ... – lj)/(j – i). No obstante, si j = n (la última palabra) el costo será cero a menos que b’ < b 
(ya que no es necesario ampliar la última línea).*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//Tecnica: Algoritmo Avido
//Complejidad O(n^2)
//Conocido como word wrap problem


int subsecuenciaComunMax(string x, string y) {
	int m = x.size();
	int n = y.size();
	int ** sub[m + 1][n + 1];
	for (int i = 0; i < m; i++) {
		sub[i][0] = 0;
	}
	for (int j = 0; j < n; j++) {
		sub[0][j] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i - 1] == y[j - 1]) {
				sub[i][j] = 1 + sub[i - 1][j - 1];
			}
			else {
				sub[i][j] = 0;
			}
		}
	}
	return sub[m][n];
}
int main() {
	string x, y;
	cout << "Escribe secuencia 1" << endl;
	cin >> x;
	cout << "Escribe secuencia 2" << endl;
	cin >> y;
	cout << subsecuenciaComunMax(x, y);
	return 0;
}