//
//  listGraph.hpp
//  PEA_Proj
//
//  Created by Jakub Sanecki on 3.11.2017.
//  Copyright © 2017 Jakub Sanecki. All rights reserved.
//

#ifndef LISTGRAPH_H
#define LISTGRAPH_H

#include <stdio.h>
#include "Graph.h"
//extends Graph
class ListGraph : public Graph{
public:
    ListGraph(unsigned NOCities);
    virtual ~ListGraph();
    bool addEdge(unsigned i, unsigned j, unsigned cost);
    bool rmvEdge(unsigned i, unsigned j);
    unsigned getCost(unsigned i, unsigned j);
    void dspGraph();
private:
    struct elem{
        unsigned city;
        int cost;
        elem *next; //index of next City
    };
    elem **graphList;
};

#endif
