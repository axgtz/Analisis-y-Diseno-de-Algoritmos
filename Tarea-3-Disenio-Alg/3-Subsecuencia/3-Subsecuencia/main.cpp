//Roberto Alejandro Gutierrez Guillen       A01019608
#include <iostream>
#include <vector>
using namespace std;
/*
Dada una secuencia X={x1 x2 ... xm}, se dice que Z={z1 z2 ... zk} es una subsecuencia de X (siendo k ≤ m)
si existe una secuencia creciente {i1 i2 ... ik} de índices de X tales que para todo j = 1, 2, ..., k tenemos xij = zj.
Dadas dos secuencias X e Y, se dice que Z es una subsecuencia común de X e Y si es subsecuencia de X y subsecuencia de Y.
Diseñe un algoritmo que permita determinar la subsecuencia de longitud máxima común a dos secuencias.
*/
//Complejidad es O(n*m) n por el numero de columnas que se recorren y m por las filas que se recorren en la matriz
//Algoritmo programación dinámico

void subsequenciaComunMax(char *X, char *Y, int m, int n){
	vector<vector<int>> L;

	for (int i = 0; i <= m; i++){
		for (int j = 0; j <= n; j++){
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}
	int index = L[m][n];

	vector<char> substring;
	substring[index] = '\0'; 

	int i = m, j = n;
	while (i > 0 && j > 0){
		if (X[i - 1] == Y[j - 1]){
			substring[index - 1] = X[i - 1];
			i--; j--; index--;  
		}
		else if (L[i - 1][j] > L[i][j - 1])
			i--;
		else
			j--;
	}
	//Imprimir substring
	cout << "El substring de " << X << " y " << Y << " es " << substring << endl;
}

int main(){
	char X[] = "GGATABA";
	char Y[] = "BBBGATACA";
	int m = strlen(X);
	int n = strlen(Y);
	subsequenciaComunMax(X, Y, m, n);
	return 0;
}