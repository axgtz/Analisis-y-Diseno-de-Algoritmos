//Roberto Alejandro Gutierrez Guillen	A01019608
//Resolver problema de Reinas en un tablero con Backtracking
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
	int i, j;
	//Resolver Fila/Row, checa solo a la derecha porque 
	//a la izquierda ya estan colocados en otro row
	for (i= 0; i < col; i++) {
		if (tablero[row][i]) {
			return false;
		}
	}

	//Resolver Diagonal arriba
	for (i = row, j = col; j >= 0 && i < tam; i++, j--) {
		if (tablero[i][j]) {
			return false;
		}
	}

	//Resolver Diagonal abajo
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (tablero[i][j]) {
			return false;
		}
	}
	return true;
}

bool recursivoBuscar(int col) {
	if (col >= tam) {//Ya estan todas las reinas colocadas en lugares 	
		return true;//correctos donde no se eliminan
	}
	//cR = currentRow
	for (int cR = 0;cR<tam;cR++) {//Itera por todos los rows
		if (seguro(cR,col)) {

			//Colocar Reina en tablero
			tablero[cR][col]=1;
			//volver a llamar funcion de forma recursiva en sig columna
			if (recursivoBuscar(col+1)) {
				return true;
			}
			//Si sale del loop , se hace el backtrack porque la reina no se puede
			//colocar ahí, ya que no llevo a la solucion
			tablero[cR][col] = 0;
		}
	}
	//La reina no se puede colocar en ningun lugar
	return false;
}

bool solucion() {
	if (!recursivoBuscar(0)){
		cout << "No existe Solucion" << endl;
		return false;
	}
	imrpimirSolucion();
	return true;
}


int main() {
	cout << "Ingresa el tamano del tablero" << endl;
	cin >> tam;

	//Crear arreglo que contiene todo
	tablero = new int*[tam];
	for (int i = 0; i < tam; i++)
		tablero[i] = new int[tam];
	//Iniciar tablero en 0
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {
			tablero[i][j] = 0;
		}
	}
	solucion();

	int xx;
	cin >>xx;
	return 0;
}