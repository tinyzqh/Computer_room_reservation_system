/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   manager.h
 * Author: hzq
 *
 * Created on January 27, 2021, 1:27 PM
 */

#ifndef MANAGER_H
#define MANAGER_H

#pragma once

#include"identity.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include"globalFile.h"
#include"computerRoom.h"
#include<algorithm>
#include <fstream>

class Manager:public Identity{
public:
    // Default constructor
    Manager();
    
    // Parameterized constructor, parameter: manager ID, name and password
    Manager(string name, string pwd);
    
    // Menu interface
    virtual void openMenu();
    
    // add Person Information
    void addPerson();
    
    // show Person Information
    void showPerson();
    
    // show computer information
    void showComputer();
    
    // clear the order information
    void cleanFile();
    
    // Initialize container
    void initVector();

    // Duplicate detection, parameter 1: check student or teacher ID, parameter 2: identity type
    bool checkRepeat(int id, int type);

    // Student container
    vector<Student> vStu;

    // Teacher container
    vector<Teacher> vTea;

    // Computer room container
    vector<ComputerRoom> vCom;

};

#endif /* MANAGER_H */

