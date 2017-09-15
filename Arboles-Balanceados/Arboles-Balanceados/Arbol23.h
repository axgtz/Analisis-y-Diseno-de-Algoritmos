//  Arboles-Balanceados
//
//  Created by Alex Gutz on 9/10/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//
//Node------
#include <iomanip>
#include <queue>
#include <iostream>
#include <vector>

template <class T>
class Node23{
    bool hasSmall = false;
    bool hasHigh = false;
    bool full = false;
    T* menor = nullptr;
    T* mayor = nullptr;
    T* tempCentro = nullptr;
    Node23<T>* padre = nullptr;
    Node23<T>* izquierdo = nullptr;
    Node23<T>* centro = nullptr;
    Node23<T>* derecho = nullptr;
    Node23<T>* temp = nullptr;
public:
    Node23<T>():izquierdo(nullptr),centro(nullptr),derecho(nullptr),padre(nullptr),menor(nullptr),mayor(nullptr),tempCentro(nullptr),temp(nullptr){}
    Node23(T _menor){
        menor = new T(_menor);
        hasSmall = true;
    }
    virtual ~Node23(){
        izquierdo = centro = derecho = padre = temp = nullptr;
        menor = mayor = nullptr;
    }
    
    Node23<T>* getTemp()
    {
        return temp;
    }
    
    void setTemp(Node23<T>* Node)
    {
        temp = Node;
    }
    
    T getTempCentro()
    {
        return *tempCentro;
    }
    
    void borrarTempCentro()
    {
        if(tempCentro)
        {
            tempCentro = nullptr;
        }
    }
    
    void setTempCentro(T _info)
    {
        if(tempCentro == nullptr)
        {
            tempCentro = new T(_info);
        }
        else
        {
            *tempCentro = _info;
        }
    }
    
    bool tieneTempCentro()
    {
        if(tempCentro)
            return true;
        else
            return false;
    }
    
    void setMenor(T _info)
    {
        if(menor!=nullptr)
        {
            *menor = _info;
        }
        else
        {
            menor = new T(_info);
        }
    }
    
    void setMayor(T _info)
    {
        if(mayor!=nullptr)
        {
            *mayor = _info;
        }
        else
        {
            mayor = new T(_info);
        }
    }
    
    T getMenor()
    {
        return *menor;
    }
    
    T getMayor()
    {
        return *mayor;
    }
    
    bool isFull()
    {
        if(mayor && menor)
            return true;
        return false;
    }
    
    bool tieneTresLlaves()
    {
        return mayor && menor && tempCentro;
    }
    
    void setInfo(T _info)
    {
        if(!menor)
        {
            menor = new T(_info);
        }
        else
        {
            if(_info >= *menor)
            {
                if(!mayor)
                {
                    mayor = new T(_info);
                }
            }
            else if(_info < *menor)
            {
                mayor = new T(*menor);
                *menor = _info;
            }
        }
    }
    
    void borrarLlaves()
    {
        if(menor)
            menor = nullptr;
        if(mayor)
            mayor = nullptr;
    }
    
    void setInfoCentro(T _info)
    {
        if(mayor && menor)
        {
            if(!tempCentro)
            {
                tempCentro = new T(_info);
                if(_info < *menor)
                {
                    *tempCentro = *menor;
                    *menor = _info;
                }
                else if(_info >= *menor && _info <= *mayor)
                {
                    *tempCentro = _info;
                }
                else
                {
                    *tempCentro = *mayor;
                    *mayor = _info;
                }
            }
            else
            {
                if(_info < *menor)
                {
                    *tempCentro = *menor;
                    *menor = _info;
                }
                else if(_info >= *menor && _info <= *mayor)
                {
                    *tempCentro = _info;
                }
                else
                {
                    *tempCentro = *mayor;
                    *mayor = _info;
                }
            }
        }
    }
    
    void borrarMayor()
    {
        if(mayor)
        {
            mayor = nullptr;
        }
    }
    
    void borrarMenor()
    {
        if(menor)
            menor = nullptr;
    }
    
    void cambioMayorAMenor()
    {
        if(!menor)
            menor = new T(*mayor);
        else
            *menor = *mayor;
        mayor = nullptr;
    }
    
    
    bool hasLower(){
        if(menor==nullptr)
            return false;
        else
            return true;
    }
    bool hasHigher(){
        if(mayor==nullptr)
            return false;
        else
            return true;
    }
    
    bool sinLlaves()
    {
        return !menor && !mayor;
    }
    
    Node23<T> * getIzquierdo() const { return izquierdo; }
    void setIzquierdo(Node23<T> * info) { izquierdo = info; }
    
    Node23<T> * getDerecho() const { return derecho; }
    void setDerecho(Node23<T> * info) { derecho = info; }
    
    Node23<T> * getCentro() const { return centro; }
    void setCentro(Node23<T> * info) { centro = info; }
    
    Node23<T> * getPadre() const { return padre; }
    void setPadre(Node23<T> * info) { padre = info; }
};



//Arbol------

template <class T>
class Arbol23 {
  
protected:
  Node23<T> * raiz = nullptr;
  std::vector<T> nivelesLeaf;
  
public:
  Arbol23() { }
  ~Arbol23();
  
  bool empty();
  
  void clear();
  void clear(Node23<T> * Node);
  
  Node23<T> * getRaiz() const;
  void setRaiz(const T info);
  void setRaiz(Node23<T> * Node);
  bool isRoot(Node23<T> * Node);
  
  void insertar23(T info);
  void insertar23(Node23<T> * info);
  void insertar23(Node23<T> * padre, Node23<T> * info);
  void insertar23(Node23<T> * padre, T info);
  
  void printAsc(Node23<T> * Node, int nivel);
  void printAsc();
  
  void printDesc(Node23<T> * Node, int nivel);
  void printDesc();
  
  void asignarRaiz(Node23<T>* raiz);
  bool es23 ();
  bool es23(Node23<T>* Node);
  
  void redistribuirHijos(Node23<T>* contenedor, Node23<T>* Node1, Node23<T>* Node2);
  void dividir(Node23<T>* contenedor);
  bool checaNodeDos(Node23<T>* Node);
  bool checaNodeTres(Node23<T>* Node);
  bool hijosLibres(Node23<T>* Node);
  
  Node23<T>* buscarNode(const T info, Node23<T> * Node);
  bool buscar(const T info);
  
  Node23<T>* encontrarNodeABorrar(Node23<T>*, T info);
  bool borrarNode(Node23<T>* Node);
  bool borrar(T info);
  void arreglar(Node23<T>* Node);
  Node23<T>* getSucesorInorder(Node23<T>* Node);
  
  void getNivelesLeaf(Node23<T>* Node);
  bool getLlavesNode(Node23<T>* Node);
  bool getHijosNode(Node23<T>* Node);
  bool encontrarNode(Node23<T>*, T info);
  
  void esLeaf() ;
  bool esLeaf(Node23<T> * Node) ;
  
  void ancestros(Node23<T> * Node) const;
  
  int getAltura() const;
  int getAltura(Node23<T> * Node) const ;
  
  int getProfundidad() const;
  int getProfundidad(Node23<T> * Node) const;
  
  int getNivel() const;
  int getNivel(Node23<T> * Node) const;
  
  void ordenar(T a[], int N);
  
};

template <class T>
Arbol23<T>::~Arbol23() {
  clear();
}

template <class T>
bool Arbol23<T>::empty() {
  return raiz == nullptr;
}

template <class T>
void Arbol23<T>::clear() {
  clear(raiz);
}

template <class T>
void Arbol23<T>::clear(Node23<T> * Node) {
  if (Node) {
    clear(Node->getIzquierdo());
    clear(Node->getDerecho());
    delete Node;
  }
}

template <class T>
Node23<T> * Arbol23<T>::getRaiz() const {
  return raiz;
}

template <class T>
void Arbol23<T>::setRaiz(const T info) {
  Node23<T> * Node = new Node23<T>(info);
  setRaiz(Node);
}

template <class T>
void Arbol23<T>::setRaiz(Node23<T> * Node) {
  if (!empty()) {
    Node->setIzquierdo(raiz);
    raiz->setPadre(Node);
    raiz = Node;
  }
  else {
    raiz = Node;
  }
}

template <class T>
bool Arbol23<T>::isRoot(Node23<T> * Node) {
  return Node == this->raiz;
}

template <class T>
void Arbol23<T>::insertar23(T info) {
  insertar23(this->raiz, info);
}

template <class T>
void Arbol23<T>::insertar23(Node23<T> * info) {
  insertar23(this->raiz, info);
}

template <class T>
void Arbol23<T>::asignarRaiz(Node23<T>* Node) {
  raiz = Node;
}

template <class T>
void Arbol23<T>::redistribuirHijos(Node23<T>* contenedor, Node23<T>* Node1, Node23<T>* Node2) {
  Node1->setIzquierdo(contenedor->getIzquierdo());
  Node1->setDerecho(contenedor->getCentro());
  Node2->setIzquierdo(contenedor->getTemp());
  Node2->setDerecho(contenedor->getDerecho());
  Node1->getIzquierdo()->setPadre(Node1);
  Node1->getDerecho()->setPadre(Node1);
  Node2->getIzquierdo()->setPadre(Node2);
  Node2->getDerecho()->setPadre(Node2);
}

template <class T>
void Arbol23<T>::dividir(Node23<T>* contenedor) {
  
  if(isRoot(contenedor)) {
    Node23<T>* newRoot = new Node23<T>(contenedor->getTempCentro());
    asignarRaiz(newRoot);
    Node23<T>* Node1 = new Node23<T>(contenedor->getMenor());
    Node23<T>* Node2 = new Node23<T>(contenedor->getMayor());
    if(contenedor->getTemp()!=nullptr)
      redistribuirHijos(contenedor, Node1, Node2);
    newRoot->setIzquierdo(Node1);
    newRoot->setDerecho(Node2);
    newRoot->getIzquierdo()->setPadre(newRoot);
    newRoot->getDerecho()->setPadre(newRoot);
    delete contenedor;
  }
  else if(contenedor->getPadre() != nullptr) {
    Node23<T>* padre = contenedor->getPadre();
    if(padre->isFull()) {
      padre->setInfoCentro(contenedor->getTempCentro());
      if(padre->getDerecho() == contenedor) {
        Node23<T>* Node1 = new Node23<T>(contenedor->getMenor());
        Node23<T>* Node2 = new Node23<T>(contenedor->getMayor());
        if(contenedor->getTemp()!=nullptr)
          redistribuirHijos(contenedor, Node1, Node2);
        padre->setDerecho(Node2);
        padre->setTemp(Node1);
        padre->getDerecho()->setPadre(padre);
        padre->getTemp()->setPadre(padre);
        delete contenedor;
      }
      else if(padre->getIzquierdo() == contenedor) {
        Node23<T>* Node1 = new Node23<T>(contenedor->getMenor());
        Node23<T>* Node2 = new Node23<T>(contenedor->getMayor());
        if(contenedor->getTemp()!=nullptr)
          redistribuirHijos(contenedor, Node1, Node2);
        padre->setIzquierdo(Node1);
        padre->setTemp(padre->getCentro());
        padre->setCentro(Node2);
        padre->getIzquierdo()->setPadre(padre);
        padre->getCentro()->setPadre(padre);
        padre->getTemp()->setPadre(padre);
        delete contenedor;
        
      }
      else {
        Node23<T>* Node1 = new Node23<T>(contenedor->getMenor());
        Node23<T>* Node2 = new Node23<T>(contenedor->getMayor());
        if(contenedor->getTemp()!=nullptr)
          redistribuirHijos(contenedor, Node1, Node2);
        padre->setCentro(Node1);
        padre->setTemp(Node2);
        padre->getCentro()->setPadre(padre);
        padre->getTemp()->setPadre(padre);
        delete contenedor;
      }
      dividir(padre);
    }
    else {
      padre->setInfo(contenedor->getTempCentro());
      if(padre->getDerecho() == contenedor)
      {
        Node23<T>* Node1 = new Node23<T>(contenedor->getMenor());
        Node23<T>* Node2 = new Node23<T>(contenedor->getMayor());
        if(contenedor->getTemp()!=nullptr)
          redistribuirHijos(contenedor, Node1, Node2);
        padre->setDerecho(Node2);
        padre->setCentro(Node1);
        padre->getDerecho()->setPadre(padre);
        padre->getCentro()->setPadre(padre);
        delete contenedor;
      }
      else if(padre->getIzquierdo() == contenedor) {
        Node23<T>* Node1 = new Node23<T>(contenedor->getMenor());
        Node23<T>* Node2 = new Node23<T>(contenedor->getMayor());
        if(contenedor->getTemp()!=nullptr)
          redistribuirHijos(contenedor, Node1, Node2);
        padre->setIzquierdo(Node1);
        padre->setCentro(Node2);
        padre->getIzquierdo()->setPadre(padre);
        padre->getCentro()->setPadre(padre);
        delete contenedor;
      }
      if(padre->tieneTresLlaves())
        dividir(padre);
    }
  }
}

template <class T>
bool Arbol23<T>:: checaNodeDos(Node23<T>* Node) {
  if((Node->hasLower() && !Node->hasHigher()) || (!Node->hasLower() && Node->hasHigher()))
    return true;
  else
    return false;
}

template <class T>
bool Arbol23<T>:: checaNodeTres(Node23<T>* Node) {
  if(Node->hasLower() && Node->hasHigher())
    return true;
  else
    return false;
}

template <class T>
bool Arbol23<T>::hijosLibres(Node23<T>* Node) {
  if(Node->getIzquierdo() == nullptr || Node->getCentro() == nullptr || Node->getDerecho() == nullptr)
    return true;
  else
    return false;
}

template <class T>
void Arbol23<T>::insertar23(Node23<T> * padre, T info) {
  Node23<T>* contenedor = new Node23<T>();
  if(raiz == nullptr)
  {
    asignarRaiz(new Node23<T>(info));
    return;
  }
  contenedor = buscarNode(info, raiz);
  if(checaNodeDos(contenedor))
  {
    contenedor->setInfo(info);
    contenedor->borrarTempCentro();
  }
  else if(checaNodeTres(contenedor))
  {
    contenedor->setInfoCentro(info);
    dividir(contenedor);
  }
}

template <class T>
bool Arbol23<T>::buscar(const T info) {
  bool found;
  
  if (buscarNode(info, raiz) != nullptr) {
    found = true;
  }
  else {
    found = false;
  }
  
  return found;
  
}

template <class T>
Node23<T>* Arbol23<T>::buscarNode(const T info, Node23<T> * Node) {
  if(Node == nullptr)
    return nullptr;
  if(esLeaf(Node))
    return Node;
  else if(checaNodeDos(Node)) {
    if(info <= Node->getMenor())
      return buscarNode(info, Node->getIzquierdo());
    else
      return buscarNode(info, Node->getDerecho());
  }
  else if(checaNodeTres(Node)) {
    if(info <= Node->getMenor())
      return buscarNode(info, Node->getIzquierdo());
    else if(info > Node->getMayor())
      return buscarNode(info, Node->getDerecho());
    else
      return buscarNode(info, Node->getCentro());
  }
  return Node;
}

template <class T>
void Arbol23<T>::printAsc() {
  printAsc(raiz, 0);
  std::cout << std::endl;
}

template <class T>
void Arbol23<T>::printAsc(Node23<T> * Node, int lv) {
  if(Node == nullptr)
    return;
  if(esLeaf(Node)) {
    if(checaNodeDos(Node)) {
      std::cout << Node->getMenor() << " "<< std::flush;
    }
    else if(checaNodeTres(Node)) {
      std::cout << Node->getMenor() << " " << Node->getMayor();
    }
  }
  else if(checaNodeDos(Node)) {
    printAsc(Node->getIzquierdo(), lv);
    std::cout << Node->getMenor() << " "<< std::flush;
    printAsc(Node->getDerecho(), lv);
  }
  else if(checaNodeTres(Node)) {
    printAsc(Node->getIzquierdo(), lv);
    std::cout << Node->getMenor() << " "<< std::flush;
    printAsc(Node->getCentro(), lv);
    std::cout << Node->getMayor() << " "<< std::flush;
    printAsc(Node->getDerecho(), lv);
  }
}

template <class T>
void Arbol23<T>::printDesc() {
  printDesc(raiz, 0);
  std::cout << std::endl;
}

template <class T>
void Arbol23<T>::printDesc(Node23<T> * Node, int lv) {
  if(Node == nullptr)
    return;
  if(esLeaf(Node)) {
    if(checaNodeDos(Node)) {
      std::cout << Node->getMenor() << " "<< std::flush;
    }
    else if(checaNodeTres(Node)) {
      std::cout << Node->getMayor() << " " << Node->getMenor() << " ";
    }
  }
  else if(checaNodeDos(Node)) {
    printDesc(Node->getDerecho(), lv);
    std::cout << Node->getMenor() << " "<< std::flush;
    printDesc(Node->getIzquierdo(), lv);
  }
  else if(checaNodeTres(Node)) {
    printDesc(Node->getDerecho(), lv);
    std::cout << Node->getMayor() << " "<< std::flush;
    printDesc(Node->getCentro(), lv);
    std::cout << Node->getMenor() << " "<< std::flush;
    printDesc(Node->getIzquierdo(), lv);
  }
}


template <class T>
void Arbol23<T>::arreglar(Node23<T>* Node) {
  if(isRoot(Node)) {
    asignarRaiz(Node->getCentro());
    delete Node;
  }
  else {
    bool threeKeys = false;
    Node23<T>* padre = Node->getPadre();
    if(checaNodeDos(padre)) {
      Node23<T>* hermano = new Node23<T>();
      if(padre->getDerecho() == Node)
        hermano = padre->getIzquierdo();
      else
        hermano = padre->getDerecho();
      if(padre->getDerecho() == Node) {
        
        if(checaNodeTres(padre->getIzquierdo())){
          threeKeys = true;
          T hermanoLower = hermano->getMenor();
          T hermanoHigher = hermano->getMayor();
          T padreVal = padre->getMenor();
          T keys[3] = {hermanoLower,hermanoHigher,padreVal};
          ordenar(keys,3);
          T low = keys[0];
          T mid = keys[1];
          T high = keys[2];
          Node->setInfo(high);
          padre->borrarLlaves();
          padre->setInfo(mid);
          hermano->borrarLlaves();
          hermano->setInfo(low);
          
          
          if(!esLeaf(Node)) {
            Node->setDerecho(Node->getCentro());
            Node->setCentro(nullptr);
            Node->setIzquierdo(hermano->getDerecho());
            Node->getIzquierdo()->setPadre(Node);
            hermano->setDerecho(hermano->getCentro());
            hermano->setCentro(nullptr);
          }
        }
      }
      else {
        if(checaNodeTres(padre->getDerecho()))
        {
          threeKeys = true;
          T hermanoLower = hermano->getMenor();
          T hermanoHigher = hermano->getMayor();
          T padreVal = padre->getMenor();
          T keys[3] = {hermanoLower,hermanoHigher,padreVal};
          ordenar(keys,3);
          T low = keys[0];
          T mid = keys[1];
          T high = keys[2];
          Node->setInfo(low);
          padre->borrarLlaves();
          padre->setInfo(mid);
          hermano->borrarLlaves();
          hermano->setInfo(high);
          
          if(!esLeaf(Node)) {
            Node->setIzquierdo(Node->getCentro());
            Node->setCentro(nullptr);
            Node->setDerecho(hermano->getIzquierdo());
            Node->getDerecho()->setPadre(Node);
            hermano->setIzquierdo(hermano->getCentro());
            hermano->setCentro(nullptr);
          }
        }
      }
    }
    else if(checaNodeTres(padre)) {
      Node23<T>* hermano = new Node23<T>();
      if(padre->getDerecho() == Node) {
        if(checaNodeTres(padre->getCentro())) {
          threeKeys = true;
          hermano = padre->getCentro();
          Node->setInfo(padre->getMayor());
          padre->setMayor(hermano->getMayor());
          hermano->borrarMayor();
          if(!esLeaf(Node)) {
            Node->setDerecho(Node->getCentro());
            Node->setIzquierdo(hermano->getDerecho());
            Node->getIzquierdo()->setPadre(Node);
            hermano->setDerecho(hermano->getCentro());
            hermano->setCentro(nullptr);
          }
        }
      }
      else if(padre->getCentro() == Node) {
        if(checaNodeTres(padre->getIzquierdo())) {
          threeKeys = true;
          hermano = padre->getIzquierdo();
          Node->setInfo(padre->getMenor());
          padre->setMenor(hermano->getMayor());
          hermano->borrarMayor();
          if(!esLeaf(Node)) {
            Node->setDerecho(Node->getCentro());
            Node->setIzquierdo(hermano->getDerecho());
            Node->getIzquierdo()->setPadre(Node);
            hermano->setDerecho(hermano->getCentro());
            hermano->setCentro(nullptr);
          }
        }
      }
      else {
        if(checaNodeTres(padre->getCentro())) {
          threeKeys = true;
          hermano = padre->getCentro();
          Node->setInfo(padre->getMenor());
          padre->setMenor(hermano->getMenor());
          hermano->cambioMayorAMenor();
          if(!esLeaf(Node)) {
            Node->setIzquierdo(Node->getCentro());
            Node->setDerecho(hermano->getIzquierdo());
            Node->getDerecho()->setPadre(Node);
            hermano->setIzquierdo(hermano->getCentro());
            hermano->setCentro(nullptr);
          }
        }
      }
    }
    if(!threeKeys) {
      Node23<T>* hermano = new Node23<T>();
      if(checaNodeDos(padre)) {
        if(padre->getDerecho() == Node) {
          hermano = padre->getIzquierdo();
          hermano->setInfo(padre->getMenor());
          
          if(!esLeaf(Node)) {
            hermano->setCentro(hermano->getDerecho());
            hermano->setDerecho(Node->getCentro());
          }
          padre->setCentro(hermano);
          padre->getCentro()->setPadre(padre);
          padre->setIzquierdo(nullptr);
          padre->setDerecho(nullptr);
          padre->borrarLlaves();
          delete Node;
        }
        else {
          hermano = padre->getDerecho();
          hermano->setInfo(padre->getMenor());
          if(!esLeaf(Node))
          {
            hermano->setCentro(hermano->getIzquierdo());
            hermano->setIzquierdo(Node->getCentro());
            hermano->getIzquierdo()->setPadre(hermano);
          }
          padre->setCentro(hermano);
          padre->getCentro()->setPadre(padre);
          padre->setIzquierdo(nullptr);
          padre->setDerecho(nullptr);
          padre->borrarLlaves();
          delete Node;
        }
      }
      else if(checaNodeTres(padre)) {
        if(padre->getDerecho() == Node) {
          hermano = padre->getCentro();
          hermano->setInfo(padre->getMayor());
          if(!esLeaf(Node)) {
            hermano->setCentro(hermano->getDerecho());
            hermano->setDerecho(Node->getCentro());
            hermano->getDerecho()->setPadre(hermano);
          }
          padre->setDerecho(hermano);
          padre->getDerecho()->setPadre(padre);
          padre->setCentro(nullptr);
          padre->borrarMayor();
          delete Node;
        }
        else if(padre->getCentro() == Node) {
          hermano = padre->getIzquierdo();
          hermano->setInfo(padre->getMenor());
          if(!esLeaf(Node)) {
            hermano->setCentro(hermano->getDerecho());
            hermano->setDerecho(Node->getCentro());
            hermano->getDerecho()->setPadre(hermano);
          }
          padre->setIzquierdo(hermano);
          padre->getIzquierdo()->setPadre(padre);
          padre->setCentro(nullptr);
          padre->borrarMenor();
          padre->cambioMayorAMenor();
          delete Node;
        }
        else {
          hermano = padre->getCentro();
          hermano->setInfo(padre->getMenor());
          if(!esLeaf(Node)) {
            hermano->setCentro(hermano->getIzquierdo());
            hermano->setIzquierdo(Node->getCentro());
            hermano->getIzquierdo()->setPadre(hermano);
          }
          padre->setIzquierdo(hermano);
          padre->getIzquierdo()->setPadre(padre);
          padre->setCentro(nullptr);
          padre->borrarMenor();
          padre->cambioMayorAMenor();
          delete Node;
        }
      }
      if(padre->sinLlaves()) {
        hermano->setPadre(padre);
        arreglar(padre);
      }
    }
  }
}

template <class T>
bool Arbol23<T>::borrar(T info) {
  Node23<T>* Node = new Node23<T>();
  Node = encontrarNodeABorrar(raiz, info);
  if(Node) {
    Node23<T>* leafNode = new Node23<T>();
    if(!esLeaf(Node)) {
      leafNode = getSucesorInorder(Node);
      T swapVal = leafNode->getMenor();
      Node->setMenor(swapVal);
    }
    else {
      if(Node->getMayor() == info) {
        Node->borrarMayor();
        return true;
      }
    }
    leafNode->borrarMenor();
    if(leafNode->sinLlaves()) {
      arreglar(leafNode);
    }
    return true;
  }
  else
    return false;
}

template <class T>
Node23<T>* Arbol23<T>::getSucesorInorder(Node23<T>* Node) {
  if (Node) {
    Node23<T> * workingNode = Node->getIzquierdo();
    if(workingNode){
      while (workingNode->getDerecho() != nullptr) {
        workingNode = workingNode->getDerecho();
      }
      return workingNode;
    }
    return nullptr;
    
  } else {
    return nullptr;
  }
}

template <class T>
Node23<T>* Arbol23<T>::encontrarNodeABorrar(Node23<T>* Node, T info) {
  if(Node == nullptr)
    return nullptr;
  if(esLeaf(Node)) {
    if(checaNodeDos(Node)) {
      if(Node->getMenor() == info){
        return Node;
      }
    }
    else if(checaNodeTres(Node)) {
      if(Node->getMenor() == info || Node->getMayor() == info) {
        return Node;
      }
    }
    return nullptr;
  }
  else if(checaNodeDos(Node)) {
    if(info == Node->getMenor()) {
      return Node;
    }
    
    if(info < Node->getMenor())
      return encontrarNodeABorrar(Node->getIzquierdo(), info);
    else
      return encontrarNodeABorrar( Node->getDerecho(), info);
  }
  else if(checaNodeTres(Node))
{
    if(Node->getMenor() == info || Node->getMayor() == info) {
      return Node;
    }
    if(info < Node->getMenor())
      return encontrarNodeABorrar(Node->getIzquierdo(), info);
    else if(info > Node->getMayor())
      return encontrarNodeABorrar(Node->getDerecho(), info);
    else
      return encontrarNodeABorrar(Node->getCentro(), info);
  }
  return nullptr;
}

template <class T>
bool Arbol23<T>::encontrarNode(Node23<T>* Node, T info) {
  if(Node == nullptr)
    return false;
  if(esLeaf(Node)) {
    if(checaNodeDos(Node)) {
      if(Node->getMenor() == info)
      {
        return true;
      }
    }
    else if(checaNodeTres(Node)) {
      if(Node->getMenor() == info || Node->getMayor() == info) {
        return true;
      }
    }
    return false;
  }
  else if(checaNodeDos(Node)) {
    if(info == Node->getMenor()) {
      return true;
    }
    
    if(info < Node->getMenor())
      return encontrarNode(Node->getIzquierdo(), info);
    else
      return encontrarNode( Node->getDerecho(), info);
  }
  else if(checaNodeTres(Node)) {
    if(Node->getMenor() == info || Node->getMayor() == info) {
      return true;
    }
    if(info < Node->getMenor())
      return encontrarNode(Node->getIzquierdo(), info);
    else if(info > Node->getMayor())
      return encontrarNode(Node->getDerecho(), info);
    else
      return encontrarNode(Node->getCentro(), info);
  }
  return false;
}

template <class T>
bool Arbol23<T>::es23() {
  return es23(raiz);
}

template <class T>
bool Arbol23<T>::es23(Node23<T>* Node) {
  nivelesLeaf.clear();
  getNivelesLeaf(raiz);
  T cmp = nivelesLeaf[0];
  bool leafs = true;
  for(int i=1; i<nivelesLeaf.size(); i++) {
    if(nivelesLeaf[i] != cmp)
      leafs = false;
  }
  return leafs;
}

template <class T>
void Arbol23<T>::getNivelesLeaf(Node23<T>* Node) {
  if(Node == nullptr)
    return;
  if(esLeaf(Node)) {
    nivelesLeaf.push_back(getNivel(Node));
  }
  else if(checaNodeDos(Node)) {
    getNivelesLeaf(Node->getIzquierdo());
    getNivelesLeaf(Node->getDerecho());
  }
  else if(checaNodeTres(Node)) {
    getNivelesLeaf(Node->getIzquierdo());
    getNivelesLeaf(Node->getCentro());
    getNivelesLeaf(Node->getDerecho());
  }
}

template <class T>
void Arbol23<T>::esLeaf() {
  esLeaf(raiz);
}

template <class T>
bool Arbol23<T>::esLeaf(Node23<T> * Node) {
  if(Node->getIzquierdo() == nullptr && Node->getCentro() == nullptr && Node->getDerecho() == nullptr)
    return true;
  else
    return false;
}

template <class T>
void Arbol23<T>::ancestros(Node23<T> * Node) const {
  if (Node) {
    std::cout << *Node << " -> ";
    ancestros(Node->getPadre());
  }
}

template <class T>
int Arbol23<T>::getAltura() const {
  return getAltura(raiz);
}

template <class T>
int Arbol23<T>::getAltura(Node23<T> * Node) const {
  if (!Node)
    return -1;
  return 1 + std::max(getAltura(Node->getIzquierdo()), getAltura(Node->getDerecho()));
}

template <class T>
int Arbol23<T>::getProfundidad() const {
  return getProfundidad(raiz);
}

template <class T>
int Arbol23<T>::getProfundidad(Node23<T> * Node) const {
  if (Node == nullptr) {
    return 0;
  }
  else {
    return getProfundidad(Node->getPadre())+1;
  }
}

template <class T>
int Arbol23<T>::getNivel() const {
  return getNivel(raiz);
}

template <class T>
int Arbol23<T>::getNivel(Node23<T> * Node) const {
  int nivel = 0;
  while (Node != nullptr && Node->getPadre() != nullptr) {
    nivel++;
    Node = Node->getPadre();
  }
  return nivel;
}

template <class T>
void Arbol23<T>::ordenar(T a[], int N) {
  
  int i, j, flag = 1;
  int temp;
  int numLength = N;
  for(i = 1; (i <= numLength) && flag; i++) {
    flag = 0;
    for (j=0; j < (numLength -1); j++) {
      if (a[j+1] < a[j]) {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
        flag = 1;
      }
    }
  }
  return;
}
