#include <string>
#include <bits/stdc++.h>

using namespace std;

bool comp(pair<double,int> a, pair<double,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
  
    vector<int> v(N);
    for(int i =0; i < stages.size(); i++){
        v[stages[i] - 1]++; 
    }

    int num = stages.size();
    int not_clear = 0;
    vector<pair<double,int>> fail;   
    for(int i = 0; i < v.size(); i++){
        not_clear = v[i];
        if(not_clear == 0){
            fail.push_back(make_pair(0, i + 1));
        }
        else {
            fail.push_back(make_pair((double)not_clear/num, i + 1));
            num -= not_clear;
        }
    }
    sort(fail.begin(),fail.end(), comp);
    
    for(int i = 0; i < fail.size();i++){
        answer.push_back(fail[i].second);
    }
    
    cout << (double)0/0 << " " << (double)0/1 << endl;
    
    return answer;
}