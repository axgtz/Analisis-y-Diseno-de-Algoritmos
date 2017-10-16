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

typedef TPt<TNEANet> g;
typedef pair<int, int> par;
visited.assign(n, false);
TPt<TNodeEDatNet<TInt, TFlt> >  g = TNodeEDatNet<TInt, TFlt>::New();
max_size = n;

using namespace TSnap;
using namespace std;
using namespace std::chrono;

void insertVertex(int valor{
    g->addNode(valor);
}

void insertEdge(int source,int destination, int weight){
    g->add_edge(source,destination);
    TNEANet::TEdgeI EI = g->GetEI(a,b);
    g->AddIntAttrDatE(EI, weight, "weight");
}

void deleteVertex(int v){
    g->DelNode(v);
}

void deleteEdge(int source, int dest){
    g->DelEdge(a,b);
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

vector<vector<int>> floydwarshall(){
    vector<vector<int>> dist;
    unsigned long numVertex = num_vertices(g);
    dist.resize(numVertex);
    par<v_it,v_it> iterators = vertices(g);
    for(v_it it = iterators.first; it != iterators.second; ++it){
        for(v_it it2 = iterators.first; it2 != iterators.second; ++it2){
            if(it == it2){
                dist[*it].push_back(0);
                continue;
            }else dist[*it].push_back(100000);
        }
    }
    par<e_it,e_it> edIt = edges(g);
    for(e_it it = edIt.first; it != edIt.second; ++it)
        dist[source(*it,g)][target(*it,g)] = get(edge_weight_t(),g, *it);
    
    for(int k = 0; k < numVertex; ++k)
        for(int i = 0; i < numVertex; ++i)
            for(int j = 0; j < numVertex; ++j)
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    return dist;
}

void BFS(int v){
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

void prim(){
    vector < typename graph_traits < DirectedGraph >::vertex_descriptor > dg(num_vertices(g));
    
    prim_minimum_spanning_tree(dG, &dg[0]);
}

struct oper2{bool operator()(const Edge& one, const Edge& two){return get(edge_weight_t(),g,one)>get(edge_weight_t(), g, two);}};
vector<std::tuple<Vertex, Vertex, int>> kruskals(DirectedGraph g){
    vector<vector<int>*> travelled;
    vector<std::tuple<Vertex, Vertex, int>> result;
    std::priority_queue<Edge, vector<Edge>, oper2> next;
    par<v_it,v_it> iterators = vertices(g);
    int contador = 0;
    Edge checking;
    Vertex source, target;
    for(v_it it = iterators.first; it != iterators.second; ++it){
        vector<int>* a = new vector<int>;
        a->push_back(contador);
        travelled.push_back(a);
        contador++;
    }
    par<e_it,e_it> edIt = edges(g);
    for(e_it it = edIt.first; it != edIt.second; ++it){
        std::par<Edge,bool> a = edge(source(*it,g),target(*it,g), g);
        next.push(a.first);
    }
    while(!next.empty()){
        checking = next.top();
        source = source(checking,g);
        target = target(checking,g);
        next.pop();
        if(*travelled[source] == *travelled[target]) continue;
        vector<int> add;
        for(vector<int>::iterator it = travelled[target]->begin(); it != travelled[target]->end(); ++it){
            travelled[source]->push_back(*it);
            add.push_back(*it);
        }
        for(vector<int>::iterator it = add.begin(); it != add.end(); ++it)
            travelled[*it] = travelled[source];
        result.push_back(make_tuple(source,target,get(edge_weight_t(), g, checking)));
    }
    return result;
    
}
struct oper{bool operator()(const std::tuple<int,Vertex, Vertex>& one, const std::tuple<int,Vertex, Vertex>& two){return std::get<0>(one)>std::get<0>(two);}};
vector<par<int, Vertex>> dijkstras(int initialNode){
    vector<par<int, Vertex>> distances;
    map<Vertex, bool> visited;
    priority_queue<std::tuple<int,Vertex,Vertex>, vector<std::tuple<int,Vertex,Vertex>>,oper> next;
    std::tuple<int,Vertex,Vertex> checking;
    Vertex source, target;
    int weight, checkingWeight;
    par<v_it,v_it> iterators = vertices(g);
    for(v_it it = iterators.first; it != iterators.second; ++it)
        distances.push_back(make_par(INT_MAX, -1));
    distances[initialNode].first = 0;
    next.push(std::make_tuple(0,initialNode,initialNode));
    while(!next.empty()){
        checking = next.top();
        next.pop();
        target = std::get<2>(checking);
        source = std::get<1>(checking);
        if(visited[target]) continue;
        visited[target] = true;
        checkingWeight = std::get<0>(checking);
        if(distances[target].first < checkingWeight) continue;
        distances[target] = make_par(checkingWeight,source);
        par<oe_it,oe_it> oeIt = out_edges(target,g);
        for(oe_it it = oeIt.first; it != oeIt.second; ++it){
            Vertex newTarget = target(*it,g);
            if(visited[newTarget]) continue;
            weight = get(edge_weight_t(),g, *it);
            next.push(make_tuple(distances[target].first + weight,target,newTarget));
        }
    }
    return distances;
}
int main(int argc, char* argv[]) {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    insertVertex(1);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Tiempo de agregar Nodo: " << time_span.count()  << "seconds" << endl;

    t1 = high_resolution_clock::now();
    deleteVertex(1);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Tiempo de Insertar Nodo: " << time_span.count()  << "seconds" << endl;
    
    t1 = high_resolution_clock::now();
    g->AddEdge(1,6,6);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Tiempo de Agregar Vertice: " << time_span.count()  << "seconds" << endl;
    
    t1 = high_resolution_clock::now();
    deleteVertex(1);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Tiempo de agregar vertice: " << time_span.count()  << "seconds" << endl;



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
    prim();
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
    kruskals();
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Tiempo de Kruskal: " << time_span.count()  << "seconds" << endl;
    
    t1 = high_resolution_clock::now();
    floydwarshall();
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Tiempo de Floyd Warshall: " << time_span.count()  << "seconds" << endl;
    
    
    t1 = high_resolution_clock::now();
    dijkstras(1);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Tiempo de Dijkstras: " << time_span.count()  << "seconds" << endl;
  return 0;
}
