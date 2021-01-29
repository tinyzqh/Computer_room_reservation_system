/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   teacher.h
 * Author: hzq
 *
 * Created on January 26, 2021, 10:27 PM
 */

#ifndef TEACHER_H
#define TEACHER_H


#include<iostream>
using namespace std;
#include"identity.h"
#include<vector>
 

class Teacher:public Identity{
public:
    // Default constructor
    Teacher();
    
    // Parameterized constructor, parameter: teacher ID, name and password
    Teacher(int empID, string name, string pwd);
    
    // Menu interface
    virtual void openMenu();
    
    // View all reservation
    void showALLOrder();
    
    // check the order
    void validOrder();
    
    int m_EmpId; // teacher ID
};

#endif /* TEACHER_H */

