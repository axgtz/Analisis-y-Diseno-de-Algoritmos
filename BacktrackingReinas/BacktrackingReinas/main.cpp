//Roberto Alejandro Gutierrez Guillen	A01019608
#include <iostream>

using namespace std;

int tam;//Tamaño del tablero
int **tablero;//Arreglo 2D que contiene el tablero

//Impresión Tablero
void imrpimirSolucion(){
	for (int i = 0; i < tam; i++)
	{
		for (int j = 0; j < tam; j++)
			cout << tablero[i][j] << "  ";
		cout << endl;
	}
}

//Es seguro poner a la reina
bool seguro(int row, int col) {
	//Resolver Fila/Row
	for (int i = 0; i < tam; i++) {
		if (tablero[row][i]) {
			return false;
		}
	}

	//Resolver Columna
	for (int i = 0; i < tam; i++) {
		if (tablero[i][col]) {
			return false;
		}
	}
	
	//Resolver diagonal
	for (int i = 0, int j=0; i < tam; i++) {
		if (tablero[row][i]) {
			return false;
		}
	}
	return true;
}


int main() {

	cout << "Ingresa el tamaño del tablero" << endl;
	cin >> tam;

	//Crear arreglo que contiene todo
	tablero = new int*[tam];
	for (int i = 0; i < tam; i++)
		tablero[i] = new int[tam];
	//Iniciar tablero en 0
	tablero[tam][tam] = { 0 };

}