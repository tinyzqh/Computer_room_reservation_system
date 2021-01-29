/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"orderFile.h"

OrderFile::OrderFile(){
    ifstream ifs;
    string file_name;
    file_name = ORDER_FILE;
    ifs.open(file_name.c_str(), ios::in);
    
    string date;
    string period;
    string stuId;
    string stuName;
    string roomId;
    // reservation status
    string status;
    
    // number of reservations
    this->m_size = 0;
    
    while(ifs >> date && ifs >> period && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status){
        string key;
        string value;
        map<string, string> m;
        
        // intercept date
        int pos = date.find(":");
        if(pos != -1){
            key = date.substr(0, pos);
            value = date.substr(pos+1, date.size()-pos-1);
            m.insert(make_pair(key, value));
        }
        
        // intercept period
        pos = period.find(":");
        if (pos != -1) {
            key = period.substr(0, pos);
            value = period.substr(pos + 1, period.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        // intercept student ID
        pos = stuId.find(":");
        if (pos != -1) {
            key = stuId.substr(0, pos);
            value = stuId.substr(pos + 1, stuId.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        // intercept student name
        pos = stuName.find(":");
        if (pos != -1) {
            key = stuName.substr(0, pos);
            value = stuName.substr(pos + 1, stuName.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        // intercept computer room number
        pos = roomId.find(":");
        if (pos != -1) {
            key = roomId.substr(0, pos);
            value = roomId.substr(pos + 1, roomId.size() - pos - 1);
            m.insert(make_pair(key, value));
        }
	
        // intercept review status
        pos = status.find(":");
        if (pos != -1) {
                key = status.substr(0, pos);
                value = status.substr(pos + 1, status.size() - pos - 1);
                m.insert(make_pair(key, value));
        }
        
        this->m_orderData.insert(make_pair(this->m_size, m));
        this->m_size++;
    }
    
    // test
    for (map<int, map<string, string> >::iterator it = m_orderData.begin(); it != m_orderData.end(); it++) {
            cout << "Number of record = " << it->first << " value = " << endl;
            for (map<string, string>::iterator mit = (*it).second.begin(); mit != it->second.end(); mit++)
                    cout << " key = " << mit->first << " value = " << mit->second << " ";
            cout << endl;
    }
    
    ifs.close();
    
}

// update reservation record
void OrderFile::updateOrder(){
    if(this->m_size == 0) return;
    
    string file_name;
    file_name = ORDER_FILE;
    ofstream ofs(file_name.c_str(), ios::out | ios::trunc);
    
    for(int i=0; i< this->m_size; i++){
        ofs << "date:" << this->m_orderData[i]["date"] << " ";
        ofs << "period:" << this->m_orderData[i]["period"] << " ";
        ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
        ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
        ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
        ofs << "status:" << this->m_orderData[i]["status"] << endl;
    }
}