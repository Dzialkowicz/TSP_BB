//
//  listGraph.cpp
//  PEA_Proj
//
//  Created by Jakub Sanecki on 3.11.2017.
//  Copyright © 2017 Jakub Sanecki. All rights reserved.
//

#include "listGraph.h"
#include <iostream>

using namespace std;

ListGraph::ListGraph(unsigned nOCities){//Constructor
    this->nOCities = nOCities;
    graphList = new elem*[nOCities];
    
    for(int i = 0; i< nOCities; i++){
        graphList[i] = NULL;
    }
}

ListGraph::~ListGraph(){//Destructor
    for(int i =0; i<nOCities; i++){
        if(graphList[i] != NULL){
            elem *pos = graphList[i];
            do{
                elem *next = pos->next;
                delete pos;
                pos = next;
            }
            while
            (pos != NULL);
        }
    }
    delete [] graphList;
}

bool ListGraph::addEdge(unsigned i, unsigned j, unsigned cost){
    //Suppress to big cost
    if(cost >= 1000)
        cost = 900;
    
    //Initiate new graphList
    if(graphList[i] == NULL){
        graphList[i] = new elem;
        graphList[i]->city = j;
        graphList[i]->cost = cost;
        graphList[i]->next = NULL;
        
        return true;
    }
    else{
        bool ifExists = false;
        elem *next = graphList[i];
        elem *pos = NULL;
        do{
            pos = next;
            next = next->next;
            if(pos->city == j){
                ifExists = true;
                break;
            }
        }
        while
            (next != NULL);
        //Add new edge if it doesn't exist
        if(!ifExists){
            elem *addedNewEdge = new elem;
            addedNewEdge->city = j;
            addedNewEdge->cost = cost;
            addedNewEdge->next = NULL;
            pos->next = addedNewEdge;
            
            return true;
        }
        else{
            return false;
        }
    }
    
}

bool ListGraph::rmvEdge(unsigned i, unsigned j){
    if(graphList[i] == NULL)
        return false;
    else{
        bool ifExists = false;
        elem *next = graphList[i];
        elem *pos = NULL;
        elem *prev = NULL;
        do{
            prev = pos;
            pos = next;
            next = next->next;
            if(pos->city == j){
                ifExists = true;
                break;
            }
        }
        while
            (next !=NULL);
        
        if(!ifExists)
            return false;
        else{
            delete pos;
            if(prev != NULL)
                prev->next = next;
            else
                graphList[i] = next;
            
            return true;
        }
    }
}

unsigned ListGraph::getCost(unsigned i, unsigned j){
    if(graphList[i] == NULL)
        return 0;
    else{
        bool ifExists = false;
        elem *next = graphList[i];
        elem *pos = NULL;
        do{
            pos = next;
            next = next->next;
            if(pos->city == j){
                ifExists = true;
                break;
        }
        }
        while
            (next != NULL);
        if(!ifExists)
            return 0;
        else
            return pos->cost;
    }
}

void ListGraph::dspGraph(){
    for(int i=0; i<nOCities; i++){
        cout << i << " - From City \n ";
        if(graphList[i] != NULL){
            elem *next = graphList[i];
            elem *pos = NULL;
            do{
                pos = next;
                next = next->next;
                cout<<"\t\t"<<"To City: "<< pos->city << " Cost: "<< pos->cost << " \n";
            }
            while
                (next != NULL);
        }
    }
}
