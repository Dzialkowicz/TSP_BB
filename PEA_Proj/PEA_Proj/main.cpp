//
//  main.cpp
//  PEA_Proj
//
//  Created by Jakub Sanecki on 3.11.2017.
//  Copyright © 2017 Jakub Sanecki. All rights reserved.
//

#include <iostream>
#include "myClock.h"
#include "Array.h"
#include "Graph.h"
#include "arrayGraph.h"
#include "listGraph.h"
#include <cstdlib>
#include <fstream>

using namespace std;
//B&B All
const int maxCityCost = 400;


int main(int argc, const char * argv[]) {
    
    MyClock myClock;    //timer
    char TSPOpt ='z';        //While Option
    Graph *graph = NULL;//indexes are stored here
    
    while(TSPOpt != '0'){
        cout<<"0 - Exit\n";
        cout<<"1 - Generate Random matrix\n";
        cout<<"2 - Display Matrix\n";
        cout<<"3 - Solve in B&B\n";
        cout<<"4 - Load file .txt\n";
        
        cin>>TSPOpt;
        
        switch (TSPOpt) {
            
            case '0':{//0 - Exit
                
            }
                break;
            case '1':{//1 - Generate Random matrix\n"
                int cities;
                cout<<"Get number of cities: \n";
                cin>>cities;
                
                if(graph != NULL)
                    delete graph;
                    graph = new ListGraph(cities);
                Graph::genRandGraph(*graph, maxCityCost);
            }
                break;
            case '2':{//2 - Display Matrix
                if(graph != NULL)
                    graph->dspGraph();
                else
                    cout<<"Error: No Data\n";
            }
                break;
            case '3':{//3 - Solve in B&B
                if(graph != NULL){
                    myClock.start();
                    vector<unsigned> route = Graph::TSPBB(*graph);
                    myClock.stop();
                    
                    unsigned routeLengthFromStart = 0;
                    unsigned routeLength = 0;
                    
                    cout<< "City: "<< route.at(0) <<"\t Route length: "<<routeLength <<"\t Total Length From Start: " <<routeLengthFromStart << "\n";

                    for(int i = 1; i< route.size(); i++){
                        routeLength = graph->getCost(route.at(i-1), route.at(i));
                        routeLengthFromStart += routeLength;
                        cout<< "City: "<< route.at(i) <<"\t Route length: "<<routeLength <<"\t Total Length From Start: " <<routeLengthFromStart << "\n";
                    }
                    cout << "Total Length:  "<< routeLengthFromStart<< "\n";
                    cout << "Algorithm Time: "<< myClock.getTime()<<" Seconds\n";
                }
                else{
                    cout <<"Graph is empty!\n";
                }
            }
                break;
            case '5':{//7 - Load file .txt
                string file;
                ifstream TSPFile;
                
                TSPFile.open("tsp.txt");
                if(TSPFile.is_open()){
                    TSPFile >> file;
                    int cities = atoi(file.c_str());
                    
                    //delete garbage
                    if(graph != NULL){
                        delete graph;
                    }
                    graph = new ListGraph(cities);
                    
                    for(int i=0; i<cities; i++){
                        for(int j=0; j<cities; j++){
                            TSPFile >> file;
                            int cost = atoi(file.c_str());
                            if(i != j){
                                graph->addEdge(i, j, cost);
                            }
                        }
                    }
                    
                    TSPFile.close();
                    
                    cout<< "Loaded graph contains "<<cities<< " cities\n";
                }
                else{
                    cout<<"Error during loading a file\n";
                }
            }
                break;
                
            default:{
                cout << "Wrong choice\n";
            }
                break;
        }
    }
    
    // insert code here...
    //std::cout << "Hello, World!\n";
    //return 0;
}
