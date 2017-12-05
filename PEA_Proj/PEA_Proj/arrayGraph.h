//
//  arrayGraph.hpp
//  PEA_Proj
//
//  Created by Jakub Sanecki on 3.11.2017.
//  Copyright © 2017 Jakub Sanecki. All rights reserved.
//
#ifndef ARRAYGRAPH_H
#define ARRAYGRAPH_H


#include <stdio.h>
#include "Graph.h"
//extends graph
class ArrayGraph : public Graph{
public:
    ArrayGraph(unsigned nOCities);
    virtual ~ArrayGraph();
    bool addEdge(unsigned i, unsigned j, unsigned cost);
    bool rmvEdge(unsigned i, unsigned j);
    unsigned getCost(unsigned i, unsigned j);
    void dspGraph();
private:
    unsigned **graphMatrix;
    unsigned **graphArray;
};

#endif
