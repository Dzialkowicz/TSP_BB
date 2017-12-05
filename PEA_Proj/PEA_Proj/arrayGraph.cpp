//
//  arrayGraph.cpp
//  PEA_Proj
//
//  Created by Jakub Sanecki on 3.11.2017.
//  Copyright © 2017 Jakub Sanecki. All rights reserved.
//

#include "arrayGraph.h"
#include <iostream>

using namespace std;

ArrayGraph::ArrayGraph(unsigned nOCities){//Constructor
    this->nOCities = nOCities;
    graphMatrix = new unsigned *[nOCities];
    graphArray = new unsigned *[nOCities];
    //protecting arr from partitioning
    
    for(int i=0; i<nOCities;i++){
        graphMatrix[i] = *(graphArray + i * nOCities);
        
        for(int j=0; j<nOCities; j++){
            graphMatrix[i][j] = 0;
        }
    }
}

ArrayGraph::~ArrayGraph(){
    delete graphArray;
    delete graphMatrix;
}

bool ArrayGraph::addEdge(unsigned i, unsigned j, unsigned cost){
    if(cost >= 1000){
        //Suppressing to big cost
        cost = 900;
    }
    
    if(graphMatrix[i][j]>0){
        return false;
    }
    else{
        graphMatrix[i][j] = cost;
        return true;
    }
}

bool ArrayGraph::rmvEdge(unsigned i, unsigned j){
    if(graphMatrix[i][j] == 0){
        return false;
    }
    else{
        graphMatrix[i][j] = 0;
        return true;
    }
}

unsigned ArrayGraph::getCost(unsigned i, unsigned j){
    return graphMatrix[i][j];
}

void ArrayGraph::dspGraph(){
    for(int i=0; i< nOCities; i++){
        for(int j =0; j< nOCities;j++)
    cout<< graphMatrix[i][j] << "\t";
    }
}

