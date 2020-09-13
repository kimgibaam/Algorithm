#include <string>
#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> imap;
    
    for(vector<string>::iterator it = record.begin(); it != record.end(); it++){
        stringstream ss(*it);
        string cmd,id,name;
        ss >> cmd;
        if(cmd == "Enter"){
            ss >> id;
            ss >> name;
            imap[id] = name;
        }
        else if(cmd == "Change") {
            ss >> id;
            ss >> name;
            imap[id] = name;
        }
    }
    
    for(vector<string>::iterator it = record.begin(); it != record.end(); it++){
        stringstream ss(*it);
        string cmd,id,name;
        ss >> cmd;
        if(cmd == "Enter"){
            ss >> id;
            ss >> name;
            answer.push_back(imap[id] + "님이 들어왔습니다.");
        }
        else if(cmd == "Leave") {
            ss >> id;
            answer.push_back(imap[id] + "님이 나갔습니다.");

        }
    }
    
    return answer;
}