//
//  Array.h
//  PEA_Proj
//
//  Created by Jakub Sanecki on 3.11.2017.
//  Copyright © 2017 Jakub Sanecki. All rights reserved.
//
#ifndef ARRAY_H
#define ARRAY_H


#include <stdio.h>
class Array{
public:
    Array();
    ~Array();
    void addValue(int val, int param);
    void rmvIndex(int index);
    void clrArray();
    void dspArray();
    
    int getValue(int index);
    int getParam(int index);
    int sumValue();
    int sumParams();
    int getLength();
    
private:
    int length;
    int *arr;
    int *param;
};

#endif
