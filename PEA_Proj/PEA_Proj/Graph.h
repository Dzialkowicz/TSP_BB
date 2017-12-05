//
//  Graph.hpp
//  PEA_Proj
//
//  Created by Jakub Sanecki on 3.11.2017.
//  Copyright © 2017 Jakub Sanecki. All rights reserved.
//

#ifndef GRAPH_H
#define GRAPH_H


#include <stdio.h>
//#include "Array.h"
#include <iostream>
#include <vector>

using namespace std;

class Graph{
public:
    Graph();
    virtual ~Graph();
    virtual bool addEdge(unsigned i, unsigned j, unsigned cost) = 0;
    virtual bool rmvEdge(unsigned i, unsigned j) = 0;
    virtual unsigned getCost(unsigned i, unsigned j) = 0;
    virtual void dspGraph() = 0;
    unsigned getNOCities();
    static void genRandGraph(Graph &graph, unsigned maxCost);
    static vector<unsigned> TSPBB(Graph &graph);
    unsigned nOCities;
    
private:
    class checkRoute {
    public:
        bool operator() (const vector<unsigned>& lhs, const vector<unsigned>& rhs) const{
            return (lhs.at(0) > rhs.at(0));
        }
    };
    
};

#endif
