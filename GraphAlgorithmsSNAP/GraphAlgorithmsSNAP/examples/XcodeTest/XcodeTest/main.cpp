//A01019608 Roberto Alejandro Gutiérrez Guill'en
//  main.cpp
//  XcodeTest

#include "/Users/gutz/Downloads/Snap-4.0/snap-core/Snap.h"

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <limits>
#include <queue>

#include "disjointset.h"

using namespace TSnap;
using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]) {
    
    TPt<TNodeEDatNet<TInt, TFlt> >  g = TNodeEDatNet<TInt, TFlt>::New();
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    insertVertex(g);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Tiempo de agregar vertice: " << time_span.count()  << "seconds" << endl;
    insertVertex(g);
    
    
    //Add vertices
    for (int i = 1; i < 15; i++) {
        g->AddNode(i);
    }
    //Add aristas
    g->AddEdge(1,4,8);
    g->AddEdge(1,3,8);
    g->AddEdge(2,5,7);
    g->AddEdge(3,2,7);
    g->AddEdge(3,10,4);
    g->AddEdge(3,5,8);
    g->AddEdge(4,7,3);
    g->AddEdge(4,8,2);
    g->AddEdge(4,5,1);
    g->AddEdge(5,6,9);
    g->AddEdge(6,13,4);
    g->AddEdge(7,4,6);
    g->AddEdge(8,7,3);
    g->AddEdge(8,9,3);
    g->AddEdge(9,10,2);
    g->AddEdge(9,12,4);
    g->AddEdge(10,6,6);
    g->AddEdge(10,3,10);
    g->AddEdge(11,12,6);
    g->AddEdge(12,9,2);
    g->AddEdge(12,11,8);
    g->AddEdge(12,14,9);
    g->AddEdge(13,14,6);
    g->AddEdge(14,13,2);
    
    
    t1 = high_resolution_clock::now();
    prim(g);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Tiempo de Prim: " << time_span.count()  << "seconds" << endl;
    
    t1 = high_resolution_clock::now();
    BFS(1);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Tiempo de BFS: " << time_span.count()  << "seconds" << endl;
    
    t1 = high_resolution_clock::now();
    dfsInit(1);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Tiempo de DFS: " << time_span.count()  << "seconds" << endl;
    
    t1 = high_resolution_clock::now();
    kruskals(g);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Tiempo de Kruskal: " << time_span.count()  << "seconds" << endl;
    
    t1 = high_resolution_clock::now();
    floydwarshall(g);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Tiempo de Floyd Warshall: " << time_span.count()  << "seconds" << endl;
    
    
    t1 = high_resolution_clock::now();
    dijkstras(g,1);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Tiempo de Dijkstras: " << time_span.count()  << "seconds" << endl;
  return 0;
}
