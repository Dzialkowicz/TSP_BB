//
//  Graph.cpp
//  PEA_Proj
//
//  Created by Jakub Sanecki on 3.11.2017.
//  Copyright © 2017 Jakub Sanecki. All rights reserved.
//

//VECTOR - AT - Zwraca referencję na element, który znajduje się na podanej pozycji w kontenerze
//VECTOR - PUSH BACK - Dodaje nowy element na końcu kontenera vector.
//VECTOR - BACK - Zwraca referencję na ostatni element w kontenerze.
//VECTOR - BEGIN - Zwraca iterator wskazujący na pierwszy element.
//VECTOR - Zwraca referencję na pierwszy element w kontenerze.
//ALGORITHM - NEXT_PERMUTATION Rearranges the elements in the range [first,last) into the next lexicographically greater permutation.

#include "Graph.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <queue> // For priority queue
#include <iostream>

using namespace std;

Graph::Graph(){//Constructor
    
}
Graph::~Graph(){//Destructor
    
}

unsigned Graph::getNOCities(){
    return nOCities;
}

void Graph::genRandGraph(Graph &graph, unsigned maxCost){
    srand(time(NULL));
    
    for(int i=0; i<graph.nOCities; i++){
        for(int j=0; j< graph.nOCities; j++){
            //Not "Infinity Edge" - fill matrix with random data
            if( i != j){
                int randCost = rand()%maxCost + 1;
                graph.addEdge(i, j, randCost);
            }
        }
    }
}

vector<unsigned> Graph::TSPBB(Graph &graph){
    vector<unsigned> optimalRoute; //Stores current optimal route
    //First best Branch & Bound algorithm
    //Priority is a value of a edge of a city. At first, we will be looking at a city with the largest edge
    //For each city we are looking if it's "promising"
    //
    //FIFO Adapter Priority queue
    //              Data Type               Data container             Funktor for comparing data     Name
    priority_queue  <vector<unsigned>,      vector<vector<unsigned> >, checkRoute >                   routePriorityQueue;
    
    int optimalLength = -1; // first length from n city to n, which is 0, which on algorithm is infinity. -1 for infinity.
    vector<unsigned> currentClassifiedRoute;
    
    //First element of Current Classified Tree is Length
    //No matter which edge is a beggining one, so take the first and insert. it will be best value and a root
    currentClassifiedRoute.push_back(0);
    currentClassifiedRoute.push_back(0);
    //Add route to a priority queue
    routePriorityQueue.push(currentClassifiedRoute);
    
    // do while queue is not empty
    while(!routePriorityQueue.empty()){
        //remove root from the queue
        currentClassifiedRoute = routePriorityQueue.top();
        routePriorityQueue.pop();
        
        //check if cuurent value is better than best
        if(optimalLength == -1 || currentClassifiedRoute.at(0) < optimalLength){
            
            //Checking if city was used in previous iteration
            for(int i = 0; i<graph.nOCities ; i++){
                bool usedCity = false;
                for(int j = 1; j<currentClassifiedRoute.size(); j++ ){
                    if(currentClassifiedRoute.at(j) == i){
                        usedCity = true;
                        break;
                    }
                }
                if(usedCity){
                    continue;
                }
                
                //New route with possible new solution
                vector<unsigned> possibleRoute = currentClassifiedRoute;
                //unsigned possibleRouteLength = graph.getCost(possibleRoute.back(), i);
                possibleRoute.push_back(i);
                
                //If it is a leaf
                if(possibleRoute.size() > graph.nOCities){
                    
                    //Adding return path.
                    possibleRoute.push_back(0);
                    possibleRoute.at(0) = 0;
                    
                    //Count return path length.
                    for(int j = 1; j< possibleRoute.size() - 1; j++){
                        possibleRoute.at(0) += graph.getCost(possibleRoute.at(j), possibleRoute.at(j+1));
                    }
                    //If possible route is better, than we have a new optimal route
                    if(optimalLength == -1 || possibleRoute.at(0) < optimalLength){
                        optimalLength = possibleRoute.at(0);
                        possibleRoute.erase(possibleRoute.begin());
                        optimalRoute = possibleRoute;
                    }
                }
                //If it's not a leaf
                else{
                    //Count return path length.
                    possibleRoute.at(0) = 0;
                    for(int j = 1; j< possibleRoute.size() - 1; j++){
                        possibleRoute.at(0) += graph.getCost(possibleRoute.at(j), possibleRoute.at(j+1));
                    }
                    
                    for(int j = 1; j< graph.nOCities; j++){
                        
                        //leave used cities
                        bool usedCity = false;
                        for(int k = 1; k < possibleRoute.size(); k++){
                            if(j==possibleRoute.at(k)){
                                
                                usedCity = true;
                                break;
                            }
                        }
                        if(usedCity){
                            continue;
                        }
                        int minimumRoute = -1;
                        for(int k = 0; k < graph.nOCities; k++){
                            //leave last route to City in the last city in partial solution except last route
                            if(j==i and k == 0){
                                continue;
                            }
                            
                            //leave route to a city in route that was solved earlier
                            bool usedCity = false;
                            for(int l = 2; l < possibleRoute.size(); l++){
                                if( k== possibleRoute.at(l)){
                                    usedCity = true;
                                    break;
                                }
                            }
                            //again check if was used
                            if(usedCity){
                                continue;
                            }
                            //don't solve for itself
                            if(k ==j){
                                continue;
                            }
                            //Shortest possible route for a partial solution
                            unsigned possibleLength = graph.getCost(j, k);
                            if(minimumRoute == -1){
                                minimumRoute = possibleLength;
                            }
                            else if(minimumRoute > possibleLength){
                                minimumRoute = possibleLength;
                            }
                        }
                        possibleRoute.at(0) += minimumRoute;
                }
                    //Check the next route
                    if(optimalLength == -1 || possibleRoute.at(0) < optimalLength){
                        routePriorityQueue.push(possibleRoute);
                    }
            }
        }
    
    }
        else {
            break;
        }
    }
    return optimalRoute;
}




