/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   identity1.h
 * Author: hzq
 *
 * Created on January 26, 2021, 10:28 PM
 */

#ifndef IDENTITY1_H
#define IDENTITY1_H

#pragma once // Prevent duplicate inclusion of header files
#include<iostream>
using namespace std;


// Base Class of Identity
class Identity{
public:
    virtual void openMenu() = 0; 
    string m_name; // user name
    string m_pwd;  // user passward
};

#endif /* IDENTITY1_H */

