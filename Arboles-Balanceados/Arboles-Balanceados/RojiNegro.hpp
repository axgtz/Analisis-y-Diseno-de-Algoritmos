//
//  Redblack.hpp
//  Arboles-Balanceados
//
//  Created by Alex Gutz on 8/31/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include "ArbolBinarioBusqueda.h"

template<class T>
class Redblack : public ArbolBinarioBusqueda<T>{
public:
    Redblack();
    
    NodoRB<T> * abuelo(NodoRB<T> * nodo);
    NodoRB<T> * tio(NodoRB<T> * nodo);
    NodoRB<T> * hermano(NodoRB<T> * nodo);
    
    NodoRB<T> * nodoMaximo(NodoRB<T> * nodo);
    
    void verificar(NodoRB<T> * raiz);
    void checarPropiedadUno(NodoRB<T> * nodo);
    void checarPropiedadDos(NodoRB<T> * nodo);
    void checarPropiedadTres(NodoRB<T> * nodo);
    void checarPropiedadCuatro(NodoRB<T> * root);
    void checarPropiedadCuatroHelper(NodoRB<T> * nodo, int contblacks, int& blackPath);
    
    std::string color(NodoRB<T> * nodo);
    
    void rotarIzq(Redblack * arbol, NodoRB<T> * nodo);
    void rotarDer(Redblack * arbol, NodoRB<T> * nodo);
    
    void RBinsert(T valor);
    void insertarCasoUno(Redblack * arbol, NodoRB<T> * nodo);
    void insertarCasoDos(Redblack * arbol, NodoRB<T> * nodo);
    void insertarCasoTres(Redblack * arbol, NodoRB<T> * nodo);
    void insertarCasoCuatro(Redblack * arbol, NodoRB<T> * nodo);
    void insertarCasoCinco(Redblack * arbol, NodoRB<T> * nodo);
    
    void RBdelete(T valor);
    void borrarCasoUno(Redblack * arbol, NodoRB<T> * nodo);
    void borrarCasoDos(Redblack * arbol, NodoRB<T> * nodo);
    void borrarCasoTres(Redblack * arbol, NodoRB<T> * nodo);
    void borrarCasoCuatro(Redblack * arbol, NodoRB<T> * nodo);
    void borrarCasoCinco(Redblack * arbol, NodoRB<T> * nodo);
    void borrarCasoSeis(Redblack * arbol, NodoRB<T> * nodo);
    
    
    void verificarArbol(NodoRB<T>* raiz);
};

template<class T>
Redblack<T>::Redblack() : ArbolBinarioBusqueda<T>() {}

template<class T>
NodoRB<T> * Redblack<T>::abuelo(NodoRB<T> * nodo){
    if(nodo != nullptr && nodo->getPadre() != nullptr)
        return nodo->getPadre()->getPadre();
    else
        return nullptr;
}

template<class T>
NodoRB<T> * Redblack<T>::tio(NodoRB<T> * nodo){
    NodoRB<T> * abu = abuelo(nodo);
    
    if(abu == nullptr)
        return nullptr;
    else if(nodo->getPadre() == abu->getIzquierdo())
        return abu->getDerecho();
    else
        return abu->getIzquierdo();
}

template<class T>
NodoRB<T> * Redblack<T>::hermano(NodoRB<T> * nodo){
    if(nodo != nullptr && nodo->getPadre() != nullptr){
        if(nodo == nodo->getPadre()->getIzquierdo())
            return nodo->getPadre()->getDerecho();
        else
            return nodo->getPadre()->getIzquierdo();
    }
    else
        return nullptr;
}

template<class T>
NodoRB<T> * Redblack<T>::nodoMaximo(NodoRB<T> * nodo){
    while (nodo->getDerecho() != nullptr){
        nodo = nodo->getDerecho();
    }
    return nodo;
}

template<class T>
void Redblack<T>::verificar(NodoRB<T>* raiz){
    checarPropiedadUno(raiz);
    checarPropiedadDos(raiz);
    checarPropiedadTres(raiz);
    checarPropiedadCuatro(raiz);
}

template<class T>
void Redblack<T>::checarPropiedadUno(NodoRB<T> * nodo){
    if(nodo == nullptr)
        return;
    
    checarPropiedadUno(nodo->getIzquierdo());
    checarPropiedadUno(nodo->getDerecho());
}

template<class T>
void Redblack<T>::checarPropiedadDos(NodoRB<T> * nodo){
    
}

template<class T>
void Redblack<T>::checarPropiedadTres(NodoRB<T> * nodo){
    if (nodo == nullptr)
        return;
    
    
    checarPropiedadTres(nodo->getIzquierdo());
    checarPropiedadTres(nodo->getDerecho());
}

template <class T>
void Redblack<T>::checarPropiedadCuatro(NodoRB<T> * root){
    
    int blackPath = -1;
    std::string mensaje="";
    
    return checarPropiedadCuatroHelper(root, 0, blackPath);
}

template <class T>
void Redblack<T>::checarPropiedadCuatroHelper(NodoRB<T> * nodo, int contblacks, int& blackPath){
    std::string color;
    
    
    if (nodo != nullptr) {
        color = nodo->getColor();
    }else{
        color = "";
    }
    
    if (color == "black"){
        contblacks++;
    }
    if (nodo == nullptr){
        if (blackPath == -1){
            blackPath = contblacks;
        }else{
            if (contblacks != blackPath){
                std::cout << "No es Redblack" << std::endl;
            }
        }
        return;
    }
    checarPropiedadCuatroHelper(nodo->getIzquierdo(),  contblacks, blackPath);
    checarPropiedadCuatroHelper(nodo->getDerecho(), contblacks, blackPath);
    
    return;
}

template<class T>
std::string Redblack<T>::color(NodoRB<T> * nodo)
{
    if(nodo == nullptr)
        return "black";
    else
        return nodo->getColor();
}

template<class T>
void Redblack<T>::rotarIzq(Redblack * arbol, NodoRB<T> * node_x){
    NodoRB<T> *node_y;
    
    if(node_x->getDerecho() == NULL){
        return;
    }
    
    node_y = node_x->getDerecho();
    
    if(node_y->getIzquierdo() != NULL){
        node_y->getIzquierdo()->setPadre(node_x);
        node_x->setDerecho(node_y->getIzquierdo());
    }
    
    node_y->setPadre(node_x->getPadre());
    
    if(node_x->getPadre() == NULL){
        this->setRaiz(node_y);
    }else if(node_x == node_x->getPadre()->getIzquierdo()){
        node_x->getPadre()->setIzquierdo(node_y);
    }else{
        node_x->getPadre()->setDerecho(node_y);
    }
    
    node_x->setDerecho(node_y->getIzquierdo());
    node_y->setIzquierdo(node_x);
    node_x->setPadre(node_y);
    
}

template<class T>
void Redblack<T>::rotarDer(Redblack * arbol, NodoRB<T> * node_y){
    NodoRB<T> *node_x;
    
    if(node_y->getIzquierdo() == NULL){
        return;
    }
    
    node_x = node_y->getIzquierdo();
    
    if(node_x->getDerecho() != NULL){
        node_x->getDerecho()->setPadre(node_y);
        node_y->setIzquierdo(node_x->getDerecho());
    }
    
    node_x->setPadre(node_y->getPadre());
    
    if(node_y->getPadre() == NULL){
        this->setRaiz(node_x);
    }else if(node_y == node_y->getPadre()->getIzquierdo()){
        node_y->getPadre()->setIzquierdo(node_x);
    }else{
        node_y->getPadre()->setDerecho(node_x);
    }
    
    node_y->setIzquierdo(node_x->getDerecho());
    node_x->setDerecho(node_y);
    node_y->setPadre(node_x);
}

template<class T>
void Redblack<T>::RBinsert(T valor){
    NodoRB<T> * nodo = this->insertar(valor);
    nodo->setColor("red");
    insertarCasoUno(this, nodo);
    verificar(this->getRaiz());
    
}

template<class T>
void Redblack<T>::insertarCasoUno(Redblack * arbol, NodoRB<T> * nodo){
    if(nodo->getPadre() == nullptr)
        nodo->setColor("black");
    else
        insertarCasoDos(this, nodo);
}

template<class T>
void Redblack<T>::insertarCasoDos(Redblack * arbol, NodoRB<T> * nodo){
    if(nodo->getPadre()->getColor() == "black")
        return;
    else
        insertarCasoTres(this, nodo);
}

template<class T>
void Redblack<T>::insertarCasoTres(Redblack * arbol, NodoRB<T> * nodo){
    if(color(tio(nodo)) == "red")
    {
        nodo->getPadre()->setColor("black");
        tio(nodo)->setColor("black");
        abuelo(nodo)->setColor("red");
        insertarCasoUno(arbol, abuelo(nodo));
    }else{
        insertarCasoCuatro(arbol, nodo);
    }
}

template<class T>
void Redblack<T>::insertarCasoCuatro(Redblack * arbol, NodoRB<T> * nodo){
    if(nodo == nodo->getPadre()->getDerecho() && nodo->getPadre() == abuelo(nodo)->getIzquierdo()){
        rotarIzq(arbol, nodo->getPadre());
        nodo = nodo->getIzquierdo();
    }
    else if(nodo == nodo->getPadre()->getIzquierdo() && nodo->getPadre() == abuelo(nodo)->getDerecho()){
        rotarDer(arbol, nodo->getPadre());
        nodo = nodo->getDerecho();
    }
    insertarCasoCinco(arbol, nodo);
}

template<class T>
void Redblack<T>::insertarCasoCinco(Redblack * arbol, NodoRB<T> * nodo){
    nodo->getPadre()->setColor("black");
    abuelo(nodo)->setColor("red");
    if (nodo == nodo->getPadre()->getIzquierdo() && nodo->getPadre() == abuelo(nodo)->getIzquierdo())
    {
        rotarDer(arbol, abuelo(nodo));
    }
    else
    {
        rotarIzq(arbol, abuelo(nodo));
    }
}

template <class T>
void Redblack<T>::RBdelete(T valor){
    NodoRB<T> * hijo;
    NodoRB<T> * nodo;
    nodo = this->buscar(valor);
    if (nodo == nullptr)
        return;
    
    if (nodo->getIzquierdo() != nullptr && nodo->getDerecho() != nullptr){
        NodoRB<T> * pred = nodoMaximo(nodo->getIzquierdo());
        nodo->setInfo(pred->getInfo());
        nodo = pred;
    }
    hijo = nodo->getDerecho() == nullptr ? nodo->getIzquierdo()  : nodo->getDerecho();
    if (color(nodo) == "black"){
        nodo->getColor() = color(hijo);
        borrarCasoUno(this, nodo);
    }
    
    
    if (nodo->getPadre() == nullptr){
        this->setRaiz(hijo);
    }else{
        if (nodo == nodo->getPadre()->getIzquierdo())
            nodo->getPadre()->setIzquierdo(hijo);
        else
            nodo->getPadre()->setDerecho(hijo);
    }
    if (hijo != nullptr){
        hijo->setPadre(nodo->getPadre());
    }
    delete nodo;
    verificar(this->getRaiz());
}

template <class T>
void Redblack<T>::borrarCasoUno(Redblack * arbol, NodoRB<T> * nodo)
{
    if(nodo->getPadre() == nullptr)
        return;
    else
        borrarCasoDos(this, nodo);
}

template <class T>
void Redblack<T>::borrarCasoDos(Redblack * arbol, NodoRB<T> * nodo){
    if (color(hermano(nodo)) == "red"){
        nodo->getPadre()->setColor("red");
        hermano(nodo)->setColor("black");
        if (nodo == nodo->getPadre()->getIzquierdo())
            rotarIzq(this, nodo->getPadre());
        else
            rotarDer(this, nodo->getPadre());
    }
    borrarCasoTres(this, nodo);
}

template <class T>
void Redblack<T>::borrarCasoTres(Redblack * arbol, NodoRB<T> * nodo){
    if (color(nodo->getPadre()) == "black" && color(hermano(nodo)) == "black" &&
        color(hermano(nodo)->getIzquierdo()) == "black" && color(hermano(nodo)->getDerecho()) == "black"){
        hermano(nodo)->setColor("red");
        borrarCasoUno(this, nodo->getPadre());
    }else
        borrarCasoCuatro(this, nodo);
}

template <class T>
void Redblack<T>::borrarCasoCuatro(Redblack * arbol, NodoRB<T> * nodo){
    if (color(nodo->getPadre()) == "red" && color(hermano(nodo)) == "black" &&
        color(hermano(nodo)->getIzquierdo()) == "black" && color(hermano(nodo)->getDerecho()) == "black"){
        hermano(nodo)->setColor("red");
        nodo->getPadre()->setColor("black");
    }else
        borrarCasoCinco(this, nodo);
}

template<class T>
void Redblack<T>::borrarCasoCinco(Redblack * arbol, NodoRB<T> * nodo){
    if (nodo == nodo->getPadre()->getIzquierdo() && color(hermano(nodo)) == "black" &&
        color(hermano(nodo)->getIzquierdo()) == "red" && color(hermano(nodo)->getDerecho()) == "black"){
        hermano(nodo)->setColor("red");
        hermano(nodo)->getIzquierdo()->setColor("black");
        rotarDer(this, hermano(nodo));
    }else if (nodo == nodo->getPadre()->getDerecho() && color(hermano(nodo)) == "black" &&
             color(hermano(nodo)->getDerecho()) == "red" && color(hermano(nodo)->getIzquierdo()) == "black"){
        hermano(nodo)->setColor("red");
        hermano(nodo)->getDerecho()->setColor("black");
        rotarIzq(this, hermano(nodo));
    }
    borrarCasoSeis(this, nodo);
}

template<class T>
void Redblack<T>::borrarCasoSeis(Redblack * arbol, NodoRB<T> * nodo){
    hermano(nodo)->setColor(color(nodo->getPadre()));
    nodo->getPadre()->setColor("black");
    if (nodo == nodo->getPadre()->getIzquierdo()){
        hermano(nodo)->getDerecho()->setColor("black");
        rotarIzq(this, nodo->getPadre());
    }else{
        hermano(nodo)->getIzquierdo()->setColor("black");
        rotarDer(this, nodo->getPadre());
    }
}

template<class T>
void Redblack<T>::verificarArbol(NodoRB<T>* raiz){
    verificar(raiz);
}
