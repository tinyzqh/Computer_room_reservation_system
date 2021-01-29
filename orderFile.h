/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   orderFile.h
 * Author: hzq
 *
 * Created on January 28, 2021, 6:12 PM
 */

#ifndef ORDERFILE_H
#define ORDERFILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "globalFile.h"

using namespace std;

class OrderFile{
public:
    // Default constructor
    OrderFile();
    
    // update reservation record
    void updateOrder();
    
    // container for recording all reservation information, key: number of reservations, value: record key-value pair information
    map<int, map<string, string> > m_orderData;
    
    int m_size;
    
};



#endif /* ORDERFILE_H */

