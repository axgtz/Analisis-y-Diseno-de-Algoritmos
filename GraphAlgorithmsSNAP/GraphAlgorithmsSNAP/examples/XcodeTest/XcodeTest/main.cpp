//A01019608 Roberto Alejandro Gutiérrez Guill'en
//  main.cpp
//  XcodeTest

#include "/Users/gutz/Downloads/Snap-4.0/snap-core/Snap.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <limits>
#include <queue>

using namespace TSnap;

int main(int argc, char* argv[]) {
    
    TPt<TNodeEDatNet<TInt, TFlt> >  g = TNodeEDatNet<TInt, TFlt>::New();
    
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
  return 0;
}
