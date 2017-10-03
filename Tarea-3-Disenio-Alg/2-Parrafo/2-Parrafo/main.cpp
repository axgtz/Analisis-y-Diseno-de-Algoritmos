//Roberto Alejandro Gutierrez Guillen       A01019608
/*Dada una secuencia de palabras p1, p2, ..., pn de longitudes l1, l2, ..., ln se desea agruparlas en l�neas de longitud L. 
Las palabras est�n separadas por espacios cuya amplitud ideal (en mil�metros) es b, pero los espacios pueden reducirse o 
ampliarse si es necesario (aunque sin solapamiento de palabras), de tal forma que una l�nea pi, pi+1, ..., pj tenga exactamente
longitud L. Sin embargo, existe una penalizaci�n por reducci�n o ampliaci�n en el n�mero total de espacios que aparecen o 
desaparecen. El costo de fijar la l�nea pi, pi+1, ..., pj es (j � i)|b� � b|, siendo b� el ancho real de los espacios, es 
decir (L � li � li+1 � ... � lj)/(j � i). No obstante, si j = n (la �ltima palabra) el costo ser� cero a menos que b� < b 
(ya que no es necesario ampliar la �ltima l�nea).*/
#include <iostream>
#include <vector>
using namespace std;
//Tecnica: Algoritmo Avido
//Complejidad O(n)
int main() {
	vector<string> parrafo, linea;
	vector<float> l;
	float L = 20, b = 1, length = 0, linelength = 0, extra, expanding, reducing;
	int i = 0, j;
	bool imprimio = true;


	for (j = 0; j < parrafo.size(); j++){
		if (imprimio){
			i = j;
			imprimio = false;
			linea.clear();
			length = 0;
		}
		length += l[j];
		linelength = length + ((j - i) * b);
		if (linelength > L){
			extra = linelength - L;
			reducing = b - (extra / (j - i));
			expanding = b + (L - ((length - l[j]) + (b * (j - i - 1)))) / (j - i - 1);

			if (((fabs(expanding - b) * (j - i - 1)) > (fabs(reducing - b) * (j - i))) && reducing > 0){
				linea.push_back(parrafo[j]);
				for (auto x : linea) {
					cout << x << " ";
				}
				cout << reducing << "r";
				cout << "\n";
				imprimio = true;

			}else{
				for (auto x : linea){
					cout << x << " ";
				}
				cout << expanding << "a";
				cout << "\n";
				j--;
				imprimio = true;
			}
		}
		linea.push_back(parrafo[j]);
	}
	for (auto x : linea){
		cout << x << " ";
	}
	cout << "\n";

	return 0;
}