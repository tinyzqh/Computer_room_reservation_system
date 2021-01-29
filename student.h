/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   student1.h
 * Author: hzq
 *
 * Created on January 26, 2021, 10:29 PM
 */

#ifndef STUDENT1_H
#define STUDENT1_H

#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include"globalFile.h"
#include"orderFile.h"
#include"computerRoom.h"
#include <fstream>
#include<vector>
#include<stdlib.h> 

class Student:public Identity{
public:
    // Default constructor
    Student();  
    
    // Parameterized constructor, parameter: student ID, name and password
    Student(int id, string name, string pwd); 
    
    // Menu interface
    virtual void openMenu();
    
    // Apply for a reservation
    void applyOrder();
    
    // View your own reservation
    void showMyOrder();
    
    // View all reservation
    void showAllOrder();
    
    // Cancel reservation
    void cancelOrder();
    
    // Student ID
    int m_Id;
    
    vector<ComputerRoom> vCom;
};

#endif /* STUDENT1_H */

