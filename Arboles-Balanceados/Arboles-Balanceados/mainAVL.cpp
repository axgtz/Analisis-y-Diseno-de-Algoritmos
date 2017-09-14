//  Arboles-Balanceados
//Roberto Alejandro Gutierrez Guillen
#include <iostream>
#include "AVLTree.h"

//Librerias de lectura de datos
#include <fstream>
#include <sstream>

//void menu();

int main(){
	AVLTree<int> tree;
	
	ifstream archivo_entrada; //Declarar variable que se usa para acceder a las funciones de ifstream

	string st= "100000.txt";

	archivo_entrada.open(st);

	if (archivo_entrada.fail()) {
		cout << "Error al abrir el archivo" << endl;
		return 0;
	}

	char linea[128];

	archivo_entrada.getline(linea, sizeof(linea));		//Usando la variable linea se extrae toda la primera linea del archivo de texto

	int tam;

	if (!(istringstream(linea) >> tam)) {				//Se guarda el numero de lineas que contiene el archivo de texto
		tam = 0;
		cout << "Error al leer el tamano del arreglo en el archivo de texto" << endl;
		return 0;
	}

	for (int i = 0; i<tam; i++) {
		archivo_entrada.getline(linea, sizeof(linea));
		//Se inserta el nodo en el Arbol con la funcion insertar de la clase
		TreeNode<int> * node = new TreeNode<int>(stoi(linea));
		tree.insert(node);
		//preset_data[i];
	}

	archivo_entrada.close();
	cout << "lall" << endl;
	tree.printInOrder();

	int xx;
	cin >> xx;
    return 0;
}
/*
void menu(){
    

	
    int number;
    char ans = 'a';
    bool found = false;
    int preset_data[] = {9, 2, 5, 12, 7, 18, 13, 14, 1, 29, 16};
    int preset_size = sizeof preset_data / sizeof preset_data[0];

    while (ans != 'q'){
        cout << "\n== Binary Search Tree Test Menu ==\n";
        cout << "\tf. Fill the tree with preset data\n";
        cout << "\ti. Insert a new number to the tree\n";
        cout << "\ts. Search for a number in the tree\n";
        cout << "\tr. Remove a number from the tree\n";
        cout << "\tc. Clear the tree\n";
        cout << "\tp. Print the data in the tree In-order\n";
        cout << "\to. Print the data in the tree Post-order\n";
        cout << "\tt. Print the data as a tree\n";
        cout << "\tm. Get the smallest number in the tree\n";
        cout << "\tl. Get the number of leaves in the tree\n";
        cout << "\tq. Quit the program\n";
        cout << "Enter your selection: ";
        cin >> ans;

        switch (ans){
            // Fill with preset values
            case 'f':
                cout << "\tInserting: ";
                for (int i=0; i<preset_size; i++){
                    cout << preset_data[i] << " ";
                    tree.insert(preset_data[i]);
                }
                cout << endl;
                break;
            // Insert a new data node
            case 'i':
                cout << "\tEnter the new number to insert: ";
                cin >> number;
                tree.insert(number);
                break;
            // Search for data in the tree
            case 's':
                cout << "\tEnter the number to search for: ";
                cin >> number;
                found = tree.search(number);
                cout << "\tNumber: " << number << " was " << (found ? "found" : "NOT found") << " in the tree" << endl;
                break;
            // Remove an element from the tree
            case 'r':
                cout << "\tEnter the new number to remove: ";
                cin >> number;
                tree.remove(number);
                break;
            // Clear the contents of the tree
            case 'c':
                tree.clear();
                break;
            // Print the tree in order
            case 'p':
                tree.printInOrder();
                break;
            // Print the tree post order
            case 'o':
                tree.printPostOrder();
                break;
            // Print the tree "graphically"
            case 't':
                tree.printTree();
                break;
            // Get the smallest value stored in the tree
            case 'm':
                node = tree.getMin();
                if (node)
                    cout << "\tSmallest number: " << node->getData() << endl;
                else
                    cout << "\tApparently the tree is empty" << endl;
                break;
            // Count the number of leaves in the tree
            case 'l':
                number = tree.countLeaves();
                cout << "\tNumber of leaves: " << number << endl;
                break;
            // Quit the program
            case 'q':
                cout << "See you later" << endl;
                break;
            default:
                cout << "Invalid option. Try again ..." << endl;
                break;
        }
    }
}
*/
