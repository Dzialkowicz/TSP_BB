//
//  Array.cpp
//  PEA_Proj
//
//  Created by Jakub Sanecki on 3.11.2017.
//  Copyright © 2017 Jakub Sanecki. All rights reserved.
//

#include "Array.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

Array::Array(){//Constructor of Parametric Array
    length = 0;
    arr = NULL;
    param = NULL;
}

Array::~Array(){//Destructor
    if(arr != NULL)
        delete [] arr;
    if(param != NULL)
        delete [] param;
}

void Array::addValue(int val, int par){
    length++;
    int *newArr = new int [length];
    int *newParam = new int [length];
    
    //Cloning arrays
    for(int i=0; i<length - 1; i++){
        newArr[i] = arr[i];
        newParam[i] = param[i];
    }
    //Adding given values to a tmp array
    newArr[length - 1] = val;
    newParam[length - 1] = par;
    
    //Deleting old values
    if(arr != NULL)
        delete [] arr;
    if(param != NULL)
        delete [] param;
    
    //Assigning new values to Array array
    arr = newArr;
    param = newParam;
}

void Array::rmvIndex(int index){
    if(arr != NULL && param != NULL ){
        length--;
        
        int *newArr;
        int *newParam;
        //Checking if we have data to remove
        if(length>0){
        newArr = new int [length];
        newParam = new int [length];
        
            for(int i = 0;i<index;i++){
                newArr[i] = arr[i];
                newParam[i] = param[i];
            }
            
            for(int i = index; i< length; i++){
                newArr[i] = arr[i+1];
                newParam[i] = param[i+1];
            }
        
        }
        else{
            newArr = NULL;
            newParam = NULL;
        }
        //Deleting unused vals
        delete [] arr;
        delete [] param;
        
        //New array with removed index
        arr = newArr;
        param = newParam;
    }
}

void Array::clrArray(){
    
    if(arr != NULL && param != NULL){
        delete [] arr;
        delete [] param;
        length = 0;
        arr = NULL;
        param = NULL;
    }
}

int Array::getValue(int index){
    return arr[index];
}

int Array::getParam(int index){
    return param[index];
}

int Array::getLength(){
    return length;
}

int Array::sumValue(){
    if(length > 0){
        //Clear prev sum
        int sum = 0;
        
        for(int i=0; i< length; i++){
            sum += arr[i];
        }
        return sum;
    }
    else{
        return 0;
    }
}

int Array::sumParams(){
    if(length > 0){
        //Clear prev sum
        int sum = 0;
        
        for(int i=0; i< length; i++){
            sum += param[i];
        }
        return sum;
    }
    else{
        return 0;
    }
}

void Array::dspArray(){
    for(int i =0; i<length; i++){
        cout<< arr[i]<< " : "<< param[i] << "\n";
    }
}
