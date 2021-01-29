/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hzq
 *
 * Created on January 25, 2021, 8:43 PM
 */
#include <cstdlib> 
#include <iostream>
#include <fstream>
#include <string>
#include"globalFile.h"
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

using namespace std;

void managerMenu(Identity* &manager){
    while(true){
        // Call the administrator submenu
        manager->openMenu();
        
        // Casting base class pointer to derived class pointer
        Manager* man = (Manager*)manager;
        
        int select = 0;
        if(cin >> select){
            if(select ==  1){
                cout << "add account"  << endl;
                man->addPerson();
            }else if(select == 2){
                cout << "view account" << endl;
                man->showPerson();
            }else if(select == 3){
                cout << "view computer room information" << endl;
                man->showComputer();
            }else if(select == 4){
                cout << "clear reservation record" << endl;
                man->cleanFile();
            }else{
                // Logout

                // Destroys the specified heap object
                delete manager; // 
                cout << "Logout successfully!" << endl;
                return;
            }
        }else{
            std::cout << "managerMenu Invalid input!" << std::endl;
            cin.clear();
        }        
    }
}

void studentMenu(Identity* &student){
    while(true){
        student->openMenu();
        
        Student* stu = (Student*)student;
        
        int select = 0;
        
        if(cin >> select){
            if(select == 1){
                // Apply for a reservation
                stu->applyOrder();
                
            }else if(select == 2){
                // View your own reservation
                stu->showMyOrder();
                
            }else if(select == 3){
                // View all reservation
                stu->showAllOrder();
            
            }else if(select == 4){
                // Cancel reservation
                stu->cancelOrder();
            }else{
                delete student;
                cout << "quit successful " << endl;
            }
        }else{
            cout << "Invalid input!" << endl;
            cin.clear();
        }
    }
}

// Go to the teacher submenu page
void teacherMenu(Identity* &teacher) {
	while (true) {
		// Call the teacher submenu
		teacher->openMenu();

		// Casting base class pointer to derived class pointer
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;

		if (select == 1) {
			// View all reservation
			tea->showALLOrder();
		}
		else if (select == 2) {
			// Review reservation
			tea->validOrder();
		}
		else {
			// Logout
			delete teacher;
			cout << "Logout successful!" << endl;

			return;
		}
	}
}

void LoginIn(string fileName, int type){
    
    // base class pointer pointing to derived object
    Identity* person = NULL;
    
    // read file
    ifstream ifs;
    ifs.open(fileName.c_str(), ios::in);
    
    // determine if the file exists
    if(!ifs.is_open()){
        cout << "file is not exist" << endl;
        ifs.close();
        return;
    }
    
    // Ready For Input Information
    int id = 0;
    string name;
    string pwd;
    
    if(type == 1){ // student login
        cout << "Please Input Your Student ID" << endl;
//        if(){
//        }else{
//        }
        cin >> id;
    }else if(type == 2){ // teacher login
        cout << "Please Input Your Teacher ID" << endl;
        cin >> id;
    }
    
    cout << "Please Input Your User Name" << endl;
    cin >> name;
    
    cout << "Please Input Your PassWard" << endl;
    cin >> pwd;
    
    if(type == 1){ // student login
        
        // ID, name and passward from file
        int fID; 
        string fName;
        string fPwd;
        
        while(ifs >> fID && ifs >> fName && ifs >> fPwd){
            if(fID == id && fName == name && fPwd == pwd){
                cout << "Student login verification success!" << endl;
                person = new Student(id, name, pwd);
                
                // enter student submenu page
                studentMenu(person);
                
                return;
            }
        }
        
        
    }else if(type == 2){ // teacher login
        
        // ID, name and passward from file
        int fID; 
        string fName;
        string fPwd;
        
        while(ifs >> fID && ifs >> fName && ifs >> fPwd){
            if(fID == id && fName == name && fPwd == pwd){
                cout << "Teacher login verification success!" << endl;
                person = new Teacher(id, name, pwd);
                
                // enter Teacher submenu page
                teacherMenu(person);
                
                return;
            }
        }
        
    }else if(type == 3){ // administer login
        
        // name and passward from file
        string fName;
        string fPwd;
        
        while(ifs >> fName && ifs >> fPwd){
            if(fName == name && fPwd == pwd){
                cout << "admin login verification success!" << endl;
                person = new Manager(name, pwd);
                
                // enter Admin submenu page
                managerMenu(person);
                
                return;
            }
        }
    }
    
    cout << "Failed to verify login" << endl;
    
    return;
}

int main() {
    
//    string fileName;
//    fileName = STUDENT_FILE;
//
//    ifstream ifs;
//    ifs.open(fileName.c_str(), ios::in);
//    if (!ifs.is_open()) {
//            cout << "File reading failed!" << endl;
//            
//    }
//
//    ifs.close();
    
    int select = 0;
    
    while(true){
        
        cout << "========  Welcome to the computer room reservation system!  ========" << endl;
        cout << endl << "Please enter your identity" << endl;
        cout << "\t\t -------------------------------------\n" << endl;
        cout << "\t\t|                                     |\n" << endl;
        cout << "\t\t|      1. Student                     |\n" << endl;
        cout << "\t\t|                                     |\n" << endl;
        cout << "\t\t|      2. Teacher                     |\n" << endl;
        cout << "\t\t|                                     |\n" << endl;
        cout << "\t\t|      3. Administrator               |\n" << endl;
        cout << "\t\t|                                     |\n" << endl;
        cout << "\t\t|      0. Quit System                 |\n" << endl;
        cout << "\t\t|                                     |\n" << endl;
        cout << "\t\t -------------------------------------\n" << endl;
        cout << "Please enter your choice: " << endl;
        
        if(cin >> select){       // chose user id
            switch(select){
                case 1:          // user id == student
                    LoginIn(STUDENT_FILE, 1);
                    break;
                case 2:          // user id == teacher
                    LoginIn(TEACHER_FILE, 2);
                    break;
                case 3:          // user id == administrator 
                    LoginIn(ADMIN_FILE, 3);
                    break;
                case 0:          // quit system
                    cout << "Hope to see you again" << endl;
                    return 0;
                    break;
                default:
                    cout << "Incorrect input, please re-select" << endl;
                    break;
            } 
        }else{
            cout << "Invalid input!" << endl;
            cin.clear();
        }
    }
    return 0;
}

