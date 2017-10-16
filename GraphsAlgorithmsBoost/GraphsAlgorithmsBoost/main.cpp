// Bfs and dfshttps://gist.github.com/mailpraveens/78713d5d69601bdb6737
//  main.cpp
//  GraphsAlgorithmsBoost
//
//  Created by Alex Gutz on 10/10/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
#include <boost/config.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/detail/adjacency_list.hpp>

#include <boost/graph/prim_minimum_spanning_tree.hpp>
#include <boost/graph/graphviz.hpp>

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <chrono>
#include <queue>

using namespace boost;
using namespace std;
using namespace std::chrono;

typedef property<edge_weight_t, int> EdgeWeightProperty;
typedef adjacency_list<listS, vecS, directedS,no_property, EdgeWeightProperty > DirectedGraph;

typedef graph_traits<DirectedGraph>::edge_iterator edge_iterator;

typedef graph_traits<DirectedGraph>::vertex_descriptor Vertex;
typedef graph_traits<DirectedGraph>::edge_descriptor Edge;
typedef boost::graph_traits<DirectedGraph>::edge_iterator e_it;
typedef boost::graph_traits<DirectedGraph>::vertex_iterator v_it;

DirectedGraph g;
property_map<DirectedGraph, edge_weight_t>::type weightmap = get(edge_weight, g);

void insertVertex(DirectedGraph dG){
    add_vertex(dG);
}

void insertEdge(unsigned long source,unsigned long destination, int weight ,DirectedGraph &dG){
    auto e = add_edge(source,destination,weight,dG).first;
    weightmap[e]=weight;
}

void deleteVertex(unsigned long v,DirectedGraph &dG){
    remove_vertex(v, dG);
}

void deleteEdge(unsigned long source, unsigned long dest, DirectedGraph &dG){
    remove_edge(source,dest,dG);
}

void imprimirEdges(){
    auto edge = edges(g);
    for(auto i = edge.first; i != edge.second; i++)
        cout << "Edge: "<< " source= " << source(*i, g) << " destination= " << target(*i, g) << " weight= " << weightmap[*i] << "\n";
}

void dfs(int vertice, int visitados){
    visitados |= (1 << vertice);
    auto adjacentRange = adjacent_vertices(vertice, g);
    for(auto i = adjacentRange.first; i != adjacentRange.second; i++){
        if (!(visitados & (1 << *i))){
            dfs(*i, visitados);
        }
    }
}

void dfsInit(int vertice){
    int visitados = 0;
    dfs(vertice, visitados);
}

void BFS(unsigned long v){
    int visited = 0;
    std::queue<int> q;
    
    visited |= (1 << v);
    q.push(v);
    
    while(!q.empty()){
        v = q.front();
        q.pop();
        auto adjacentRange = adjacent_vertices(v, g);
        for(auto i = adjacentRange.first; i != adjacentRange.second; i++){
            if (!(visited & (1 << *i))){
                q.push(*i);
                visited |= (1 << *i);
            }
        }
    }
}

void prim(DirectedGraph & dG){
    vector < typename graph_traits < DirectedGraph >::vertex_descriptor > dg(num_vertices(dG));
    
    prim_minimum_spanning_tree(dG, &dg[0]);
}

void ksruskal(){
    
}

void dijkstra(){
    
}

void floydWarshall(DirectedGraph & dG){
}


int main(){
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    insertVertex(g);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Tiempo de agregar vertice: " << time_span.count()  << "seconds" << endl;
    insertVertex(g);
    
    t1 = high_resolution_clock::now();
    insertEdge(1,2,8,g);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Tiempo de agregar arista: " << time_span.count()  << "seconds" << endl;
    
    t1 = high_resolution_clock::now();
    remove_edge(1, 2, g);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Tiempo de quitar arista: " << time_span.count()  << "seconds" << endl;
    
    t1 = high_resolution_clock::now();
    remove_vertex(1, g);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Tiempo de quitar vertice: " << time_span.count()  << "seconds" << endl;


    for(int i=1; i<=14;i++){
         insertVertex(g);
    }
    
    insertEdge(1,4,8,g);
    insertEdge(1,3,8,g);
    insertEdge(2,5,7,g);
    insertEdge(3,2,7,g);
    insertEdge(3,5,8,g);
    insertEdge(3,10,4,g);
    insertEdge(4,7,3,g);
    insertEdge(4,8,2,g);
    insertEdge(4,5,1,g);
    insertEdge(5,6,9,g);
    insertEdge(6,13,4,g);
    insertEdge(7,4,6,g);
    insertEdge(8,7,3,g);
    insertEdge(8,9,3,g);
    insertEdge(9,10,2,g);
    insertEdge(9,12,4,g);
    insertEdge(10,6,6,g);
    insertEdge(10,3,10,g);
    insertEdge(11,12,6,g);
    insertEdge(12,11,8,g);
    insertEdge(12,9,2,g);
    insertEdge(12,14,9,g);
    insertEdge(13,14,6,g);
    insertEdge(14,13,2,g);

    imprimirEdges();
    
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
    
}



