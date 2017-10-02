//Roberto Alejandro Gutierrez Guillen       A01019608
#include <iostream>
#include <vector>
using namespace std;
/*
Un camionero conduce desde DF a Acapulco siguiendo una ruta dada y llevando un camión que le permite,
con el tanque de gasolina lleno, recorrer n kilómetros sin parar. El camionero dispone de un mapa de
carreteras que le indica las distancias entre las gasolineras que hay en su ruta. Como va con prisa,
el camionero desea detenerse a abastecer gasolina el menor número de veces posible.
Diseñe un algoritmo eficiente que determine en qué gasolineras tiene que parar el camionero.
*/

int main() {
    int gasTankKm = 80;
    int kmRec = 0;
    cout << "Introduce cantidad de kilometros que el coche puede recorrer con el tanque lleno" << endl;
    //cin >> gasTankKm;
    cout << endl;

    vector<int> gasStationsDist;
    vector<int> stops;

    gasStationsDist.push_back(49);
    gasStationsDist.push_back(46);
    gasStationsDist.push_back(21);
    gasStationsDist.push_back(17);
    gasStationsDist.push_back(19);
    gasStationsDist.push_back(40);
    gasStationsDist.push_back(25);
    gasStationsDist.push_back(51);
    gasStationsDist.push_back(13);
    gasStationsDist.push_back(50);
    gasStationsDist.push_back(45);

    int gasLeft = gasTankKm;;
    for(int i = 0;i <= gasStationsDist.size()-1 ;i++){
        gasLeft-=gasStationsDist[i];
        kmRec+=gasStationsDist[i];

        if(gasLeft<gasStationsDist[i+1]){
            stops.push_back(i);
            gasLeft = gasTankKm;
        }
    }

    if(kmRec >= 375){
        if(stops.empty()){//375 km entre DF y Aac
        }else{
            cout << "El coche se paro  en las siguientes Gasolineras" << endl;
            for(int i = 0; i< stops.size();i++){
                cout << "Parada número " << i <<": "<< stops[i]<< endl;
            }
        }
    }else {
        cout << "El coche no puede recorrer el trayecto con ese tanque de gasolina" << endl;
        cout << "El coche recorrió: " << kmRec << endl;
    }


    return 0;
}