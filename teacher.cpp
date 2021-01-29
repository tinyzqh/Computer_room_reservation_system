/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"teacher.h"
#include "orderFile.h"

Teacher::Teacher(){}

Teacher::Teacher(int empID, string name, string pwd){
    
}

void Teacher::openMenu(){
    cout << "Welcome teacher: " << this->m_name << " login!" << endl;
    cout << "\t\t ------------------------------------------\n" << endl;
    cout << "\t\t|                                          |\n" << endl;
    cout << "\t\t|         1. View all reservation          |\n" << endl;
    cout << "\t\t|                                          |\n" << endl;
    cout << "\t\t|         2. Review reservation            |\n" << endl;
    cout << "\t\t|                                          |\n" << endl;
    cout << "\t\t|         0. Logout                        |\n" << endl;
    cout << "\t\t|                                          |\n" << endl;
    cout << "\t\t ------------------------------------------\n" << endl;
    cout << "Please choose your operation: " << endl;
}

void Teacher::showALLOrder(){
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

void Teacher::validOrder(){
    OrderFile resFile;

    if (resFile.m_size == 0) {
        cout << "No reservation record!" << endl;

        return;
    }

	vector<int> v;
	int index = 0;
	cout << "The reservation records to be reviewed are as follows: " << endl;

	for (int i = 0; i < resFile.m_size; i++) {
            if (resFile.m_orderData[i]["status"] == "1") {
                    v.push_back(i);

                    cout << ++index << ". ";
                    cout << "Reservation date: " << resFile.m_orderData[i]["date"];
                    cout << ", Period: " << (resFile.m_orderData[i]["period"] == "1" ? "Morning" : "Afternoon");
                    cout << ", Student ID: " << resFile.m_orderData[i]["stuId"];
                    cout << ", Student name: " << resFile.m_orderData[i]["stuName"];
                    cout << ", Computer room number: " << resFile.m_orderData[i]["roomId"];

                    string status = ", Status: under review";
                    cout << status << endl;
            }
	}

	cout << "Please enter the reservation record to review, press 0 to return: " << endl;
	int select = 0;
	int result = 0;

	while (true) {
            if(cin >> select){
                if (select >= 0 && select <= v.size()) {
                    if (select == 0)
                            break;

                    cout << "Please enter the audit result: " << endl;
                    cout << "1. Approved" << endl;
                    cout << "2. Not approved" << endl;

                    cin >> result;
                    if (result == 1)
                            resFile.m_orderData[v[select - 1]]["status"] = "2";
                    else
                            resFile.m_orderData[v[select - 1]]["status"] = "-1";

                    // update reservation record
                    resFile.updateOrder();
                    cout << "Review completed!" << endl;
                    break;
            }

            cout << "Incorrect input, please re-enter: " << endl;
            
            }else{
                cout << "Invalid input!" << endl;
                cin.clear();
            }

            
	}

}