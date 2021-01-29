/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "student.h"

Student::Student(){}

Student::Student(int id, string name, string pwd){
    this->m_Id = id;
    this->m_name = name;
    this->m_pwd = pwd;
    
    // initialize computer room information
    ifstream ifs;
    string file_name;
    file_name = COMPUTER_FILE;
    ifs.open(file_name.c_str(), ios::in);

    ComputerRoom com;
    while (ifs >> com.m_ComId && ifs >> com.m_MaxNum){
        vCom.push_back(com);
    }
    
    ifs.close();
}

void Student::openMenu(){
    cout << "Welcome student representative: " << this->m_name << " login!" << endl;
    cout << "\t\t ------------------------------------------\n" << endl;
    cout << "\t\t|                                          |\n" << endl;
    cout << "\t\t|        1. Apply Reservation              |\n" << endl;
    cout << "\t\t|                                          |\n" << endl;
    cout << "\t\t|        2. View Your Reservation          |\n" << endl;
    cout << "\t\t|                                          |\n" << endl;
    cout << "\t\t|        3. View All Reservation           |\n" << endl;
    cout << "\t\t|                                          |\n" << endl;
    cout << "\t\t|        4. Cancel Reservation             |\n" << endl;
    cout << "\t\t|                                          |\n" << endl;
    cout << "\t\t|        0. Logout                         |\n" << endl;
    cout << "\t\t|                                          |\n" << endl;
    cout << "\t\t ------------------------------------------\n" << endl;
    cout << "Please choose your operation: " << endl;
}

void Student::applyOrder(){
    cout << "The computer room is open from Monday to Friday!" << endl;
    cout << "Please enter the time to apply for a reservation: " << endl;
    cout << "1. Monday"  << endl;
    cout << "2. Tuesday" << endl;
    cout << "3. Wednesday" << endl;
    cout << "4. Thursday" << endl;
    cout << "5. Friday" << endl;
    
    // date 
    int date = 0;
    
    while(true){
        if(cin >> date){
            if(date >= 1 && date <= 5) break; // Input data is correct!
            cout << "Incorrect input, please re-enter" << endl;
        }else{
            cout << "Invalid Input" << endl;
            cin.clear();
        }
    }
    
    // morning or afternoon
    int period = 0;
    
    cout << "Please enter the time period to applying for a reservation: " << endl;
    cout << "1. Morning" << endl;
    cout << "2. Afternoon" << endl;
    
    while(true){
        if(cin >> period){
            if(period >= 1 && period <=2) break;
            cout << "Incorrect input, please re-enter" << endl;
        }else{
            cout << "Invalid Input" << endl;
            cin.clear();
        }
    }
    cout << "Please choose the computer room:" << endl;
    for(int i=0; i< vCom.size(); i++){
        cout << "Computer room " << vCom[i].m_ComId << " capacity: " << vCom[i].m_MaxNum << endl;
    }
    
    // computer room number
    int room;
    while(true){
        if(cin >> room){
            if(room >= 1 && room <=3) break;
            cout << "Incorrect input, please re-enter" << endl;
        }else{
            cout << "Invalid input" << endl;
            cin.clear();
        }
    }

    cout << "Your reservation is successfully applied and is under review by teachers!" << endl;

    ofstream ofs;
    string file_name;
    file_name = ORDER_FILE;

    ofs.open(file_name.c_str(), ios::app);

    ofs << "date:" << date << " ";
    ofs << "period:" << period << " ";
    ofs << "stuId:" << this->m_Id << " ";
    ofs << "stuName:" << this->m_name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << endl;
    
    ofs.close();
    
}

void Student::showMyOrder(){
    OrderFile resFile;
    if(resFile.m_size == 0){
        cout << "No reservation record!" << endl;
        return; 
    }
    
    for (int i = 0; i < resFile.m_size; i++) {
        if(atoi(resFile.m_orderData[i]["stuId"].c_str()) == this->m_Id){
            cout << i + 1 << ". ";
            cout << "Reservation date: " << resFile.m_orderData[i]["date"];
            cout << ", Period: " << (resFile.m_orderData[i]["period"] == "1" ? "Morning" : "Afternoon");
            cout << ", Student ID: " << resFile.m_orderData[i]["stuId"];
            cout << ", Student name: " << resFile.m_orderData[i]["stuName"];
            cout << ", Computer room number: " << resFile.m_orderData[i]["roomId"];

            string status = ", Status: ";

            // 1--under review, 2--already reserved, -1--reserve failed, 0--cancel reservation
            if (resFile.m_orderData[i]["status"] == "1")
                    status += "under review";
            else if (resFile.m_orderData[i]["status"] == "2")
                    status += "already reserved";
            else if (resFile.m_orderData[i]["status"] == "-1")
                    status += "reserve failed, not approved";
            else
                    status += "reservation canceled";

            cout << status << endl;
        }
        
    }
    
}

void Student::showAllOrder(){
    OrderFile resFile;

    if (resFile.m_size == 0) {
            cout << "No reservation record!" << endl;
            return;
    }

    for (int i = 0; i < resFile.m_size; i++) {
        cout << i + 1 << ". ";
        cout << "Reservation date: " << resFile.m_orderData[i]["date"];
        cout << ", Period: " << (resFile.m_orderData[i]["period"] == "1" ? "Morning" : "Afternoon");
        cout << ", Student ID: " << resFile.m_orderData[i]["stuId"];
        cout << ", Student name: " << resFile.m_orderData[i]["stuName"];
        cout << ", Computer room number: " << resFile.m_orderData[i]["roomId"];

        string status = ", Status: ";

        // 1--under review, 2--already reserved, -1--reserve failed, 0--cancel reservation
        if (resFile.m_orderData[i]["status"] == "1")
                status += "under review";
        else if (resFile.m_orderData[i]["status"] == "2")
                status += "already reserved";
        else if (resFile.m_orderData[i]["status"] == "-1")
                status += "reserve failed, not approved";
        else
                status += "reservation canceled";

        cout << status << endl;
    }

}

void Student::cancelOrder(){
    OrderFile resFile;

    if (resFile.m_size == 0) {
        cout << "No reservation record!" << endl;

        return;
    }

    cout << "Records under review or successfully reserved can be canceled" << endl;

    vector<int> v;
    int index = 1;
    for (int i = 0; i < resFile.m_size; i++) {
        if (this->m_Id == atoi(resFile.m_orderData[i]["stuId"].c_str())) {
            if (resFile.m_orderData[i]["status"] == "1" || resFile.m_orderData[i]["status"] == "2") {
                    v.push_back(i);

                    cout << index++ << ". ";
                    cout << "Reservation date: " << resFile.m_orderData[i]["date"];
                    cout << ", Period: " << (resFile.m_orderData[i]["period"] == "1" ? "Morning" : "Afternoon");
                    cout << ", Computer room number: " << resFile.m_orderData[i]["roomId"];

                    string status = ", Status: ";

                    // 1--under review, 2--already reserved
                    if (resFile.m_orderData[i]["status"] == "1")
                            status += "under review";
                    else if (resFile.m_orderData[i]["status"] == "2")
                            status += "already reserved";

                    cout << status << endl;
            }
        }
    }

    cout << "Please enter the record number to cancel(press 0 to return):" << endl;

    int select = 0;
    while (true) {
        if(cin >> select){
            if (select >= 0 && select <= v.size()) {
                if (select == 0)
                        break;
                else{
                    resFile.m_orderData[v[select - 1]]["status"] = "0";
                    resFile.updateOrder();
                    cout << "Reservation has been cancelled!" << endl;
                    break;
                }
            }

            cout << "Incorrect input, please re-enter: " << endl;
        
        }else{
            cout << "Invalid input!" << endl;
            cin.clear();
        }
        
    }

}