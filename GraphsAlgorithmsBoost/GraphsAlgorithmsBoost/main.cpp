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
#include <tuple>
#include <stack>
#include <map>

using namespace boost;
using namespace std;
using namespace std::chrono;

typedef property<edge_weight_t, int> EdgeWeightProperty;
typedef adjacency_list<listS, vecS, directedS,no_property, EdgeWeightProperty > DirectedGraph;

typedef graph_traits<DirectedGraph>::edge_iterator edge_iterator;

typedef graph_traits<DirectedGraph>::vertex_descriptor Vertex;
typedef graph_traits<DirectedGraph>::edge_descriptor Edge;
typedef graph_traits<DirectedGraph>::edge_iterator e_it;
typedef graph_traits<DirectedGraph>::vertex_iterator v_it;
typedef graph_traits<DirectedGraph>::out_edge_iterator oe_it;

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

vector<vector<int>> floydwarshall(DirectedGraph g){
    vector<vector<int>> dist;
    unsigned long numVertex = num_vertices(g);
    dist.resize(numVertex);
    pair<v_it,v_it> iterators = vertices(g);
    for(v_it it = iterators.first; it != iterators.second; ++it){
        for(v_it it2 = iterators.first; it2 != iterators.second; ++it2){
            if(it == it2){
                dist[*it].push_back(0);
                continue;
            }else dist[*it].push_back(100000);
        }
    }
    pair<e_it,e_it> edIt = edges(g);
    for(e_it it = edIt.first; it != edIt.second; ++it)
        dist[source(*it,g)][target(*it,g)] = get(edge_weight_t(),g, *it);
        
        for(int k = 0; k < numVertex; ++k)
            for(int i = 0; i < numVertex; ++i)
                for(int j = 0; j < numVertex; ++j)
                    if(dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                    return dist;
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

struct oper2{bool operator()(const Edge& one, const Edge& two){return get(edge_weight_t(),g,one)>get(edge_weight_t(), g, two);}};
vector<std::tuple<Vertex, Vertex, int>> kruskals(DirectedGraph g){
    vector<vector<int>*> travelled;
    vector<std::tuple<Vertex, Vertex, int>> result;
    std::priority_queue<Edge, vector<Edge>, oper2> next;
    pair<v_it,v_it> iterators = vertices(g);
    int contador = 0;
    Edge checking;
    Vertex source, target;
    for(v_it it = iterators.first; it != iterators.second; ++it){
        vector<int>* a = new vector<int>;
        a->push_back(contador);
        travelled.push_back(a);
        contador++;
    }
    pair<e_it,e_it> edIt = edges(g);
    for(e_it it = edIt.first; it != edIt.second; ++it){
        std::pair<Edge,bool> a = boost::edge(boost::source(*it,g),boost::target(*it,g), g);
        next.push(a.first);
    }
    while(!next.empty()){
        checking = next.top();
        source = boost::source(checking,g);
        target = boost::target(checking,g);
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
vector<pair<int, Vertex>> dijkstras(DirectedGraph g, unsigned long initialNode){
    vector<pair<int, Vertex>> distances;
    map<Vertex, bool> visited;
    priority_queue<std::tuple<int,Vertex,Vertex>, vector<std::tuple<int,Vertex,Vertex>>,oper> next;
    std::tuple<int,Vertex,Vertex> checking;
    Vertex source, target;
    int weight, checkingWeight;
    pair<v_it,v_it> iterators = vertices(g);
    for(v_it it = iterators.first; it != iterators.second; ++it)
        distances.push_back(make_pair(INT_MAX, -1));
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
        distances[target] = make_pair(checkingWeight,source);
        pair<oe_it,oe_it> oeIt = out_edges(target,g);
        for(oe_it it = oeIt.first; it != oeIt.second; ++it){
            Vertex newTarget = boost::target(*it,g);
            if(visited[newTarget]) continue;
            weight = get(edge_weight_t(),g, *it);
            next.push(make_tuple(distances[target].first + weight,target,newTarget));
        }
    }
    return distances;
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
    
}



