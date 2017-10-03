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
using namespace std;
//Tecnica: Algoritmo Avido
//Complejidad O(n^2)
#define INF 100

int imprimirSol(int p[], int n);

int main(){
	int l[] = { 3, 2, 2, 5 };
	int n = sizeof(l) / sizeof(l[0]);
	int M = 6;

	int extras[n + 1][n + 1];

	int lc[n + 1][n + 1];

	int c[n + 1];

	int p[n + 1];

	int i, j;

	for (i = 1; i <= n; i++){
		extras[i][i] = M - l[i - 1];
		for (j = i + 1; j <= n; j++)
			extras[i][j] = extras[i][j - 1] - l[j - 1] - 1;
	}

	for (i = 1; i <= n; i++){
		for (j = i; j <= n; j++){
			if (extras[i][j] < 0)
				lc[i][j] = INF;
			else if (j == n && extras[i][j] >= 0)
				lc[i][j] = 0;
			else
				lc[i][j] = extras[i][j] * extras[i][j];
		}
	}


	c[0] = 0;
	for (j = 1; j <= n; j++){
		c[j] = INF;
		for (i = 1; i <= j; i++){
			if (c[i - 1] != INF && lc[i][j] != INF && (c[i - 1] + lc[i][j] < c[j])){
				c[j] = c[i - 1] + lc[i][j];
				p[j] = i;
			}
		}
	}

	imprimirSol(p, n);
	return 0;
}

int imprimirSol(int p[], int n) {
	int numL;
	if (p[n] == 1) {
		numL = 1;
	}else {
		numL = imprimirSol(p, p[n] - 1) + 1;
	}
	cout << "Numero de linea: " << numL << "Palabra num " << p[n] << "a palabra num" << n << endl;
	return k;
}
