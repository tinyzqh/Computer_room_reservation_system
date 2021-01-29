/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"manager.h"

void printStudent(Student& stu) {
	cout << "Student ID: " << stu.m_Id << " Name: " << stu.m_name << " Password: " << stu.m_pwd << endl;
}

void printTeacher(Teacher& tea) {
	cout << "Teacher ID: " << tea.m_EmpId << " Name: " << tea.m_name << " Password: " << tea.m_pwd << endl;
}

Manager::Manager(){}

Manager::Manager(string name, string pwd){
    
    // Initialize administrator information
    this->m_name = name;
    this->m_pwd = pwd;
    
    // Initialize container, get student and teacher information in all files
    this->initVector();
    
    // Initialize computer room information
    string File_Name;
    File_Name = COMPUTER_FILE;
    ifstream ifs;
    ifs.open(File_Name.c_str(), ios::in);

    ComputerRoom com;
    while(ifs >> com.m_ComId && ifs >> com.m_MaxNum){
        vCom.push_back(com);
    } 

    ifs.close();
    cout << "The number of computer room is: " << vCom.size() << endl;
}

void Manager::openMenu(){
    cout << "Welcome administrator: " << this->m_name << " login!" << endl;
    cout << "\t\t -------------------------------------------\n" << endl;
    cout << "\t\t|                                          |\n" << endl;
    cout << "\t\t|       1. Add account                     |\n" << endl;
    cout << "\t\t|                                          |\n" << endl;
    cout << "\t\t|       2. View account                    |\n" << endl;
    cout << "\t\t|                                          |\n" << endl;
    cout << "\t\t|       3. View computer room              |\n" << endl;
    cout << "\t\t|                                          |\n" << endl;
    cout << "\t\t|       4. Clear reservation record        |\n" << endl;
    cout << "\t\t|                                          |\n" << endl;
    cout << "\t\t|       0. Logout                          |\n" << endl;
    cout << "\t\t|                                          |\n" << endl;
    cout << "\t\t ------------------------------------------\n" << endl;
    cout << "Please choose your operation: " << endl;
}

void Manager::addPerson(){
    cout << "Please enter the add account type" << endl;
    cout << "1. Add stuent" << endl;
    cout << "2. Add teacher" << endl;
    
    string fileName;
    string tip;
    // Repeat errorTips
    string errorTips;
    
    ofstream ofs;
    int select = 0;
    if(cin >> select){
        if(select == 1){
            fileName = STUDENT_FILE;
            tip = "Please enter student ID: ";
            errorTips = "Duplicate student ID, please re-enter: ";
        }else{
            fileName = TEACHER_FILE;
            tip = "Please enter teacher ID: ";
            errorTips = "Duplicate teacher ID, please re-enter: ";
        }
    }else{
        std::cout << "Invalid input!" << std::endl;
        cin.clear();
    }
    
    ofs.open(fileName.c_str(), ios::out | ios::app);
    int id;
    string name;
    string pwd;
    
    
    cout << tip << endl;
    while(true){
        if(cin >> id){
            bool ret = this->checkRepeat(id, select);
            if(ret) cout << errorTips;
            else break;
        }
    }

    cout << "Please enter username: " << endl;
    cin >> name;
    
    cout << "Please enter password: " << endl;
    cin >> pwd;
    
    // Add data to file
    ofs << id << " " << name << " " << pwd << " " << endl;
    
    cout << "Account successfully created!" << endl;
    ofs.close();
    
    // Initialize container, get student and teacher information in all files
    this->initVector(); 
    
}

void Manager::showPerson(){
    cout << "Please select the content to display: " << endl;
    cout << "1. View all students" << endl;
    cout << "2. View all teachers" << endl;

    int select = 0;
    
    if(cin >> select){
        if(select == 1){
            // view all students
            cout << "All student information is as follows: " << endl;
            for_each(vStu.begin(), vStu.end(), printStudent);
        }
        else {
            // view all teachers
            cout << "All teacher information is as follows: " << endl;
            for_each(vTea.begin(), vTea.end(), printTeacher);
        }
    }else{
        std::cout << "Invalid input!" << std::endl;
        cin.clear();
    }
}

void Manager::showComputer(){
    cout << "Computer Information Show:" << endl;
    for(vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++){
        cout << "Computer Id: " << it->m_ComId << endl;
        cout << "Computer Capacity: " << it->m_MaxNum << endl;
    }
}

void Manager::cleanFile(){
    string Order_File;
    Order_File = ORDER_FILE;
    
    ofstream ofs(Order_File.c_str(), ios::trunc);
    ofs.close();
    
    cout << "Had Cleaned the Order Information" << endl;
}

// Initialize container
void Manager::initVector() {
	// Make sure container is empty
	vStu.clear();
	vTea.clear();

	// Read student information
        
	string fileName;
        fileName = STUDENT_FILE;

        ifstream ifs;
	ifs.open(fileName.c_str(), ios::in);
	if (!ifs.is_open()) {
		cout << "File reading failed!" << endl;
		return;
	}

	Student stu;
	while (ifs >> stu.m_Id && ifs >> stu.m_name && ifs >> stu.m_pwd) {
            vStu.push_back(stu);
        }
	cout << "The current number of students is: " << vStu.size() << endl;
	ifs.close();

	// Read teacher information
	ifs.open(TEACHER_FILE, ios::in);
	Teacher tea;
	while (ifs >> tea.m_EmpId && ifs >> tea.m_name && ifs >> tea.m_pwd){
            vTea.push_back(tea);
        }
	cout << "The current number of teacher is: " << vTea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type){
    if(type == 1){ // check student
        for(vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++){
            if(id == it->m_Id) return true;
        }
    }else{
        for(vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++){
            if(id == it->m_EmpId) return true;
        }
    }
    return false;
}


 