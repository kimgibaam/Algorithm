#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
    string strA = to_string(a);
    string strB = to_string(b);
    string AB = strA + strB, BA = strB+strA;
    int numAB = stoi(AB), numBA = stoi(BA);
    return numAB > numBA;
    
}

string solution(vector<int> numbers) {
    string answer = "";
    
    int count = 0;
    for(int i =0; i< numbers.size();i++){
        if(numbers[i] == 0) count++;   
    }
    if(count == numbers.size()) return "0";
    
    sort(numbers.begin(),numbers.end(),comp);
    for(int i =0; i< numbers.size();i++){
        answer += to_string(numbers[i]);
    }
    
    return answer;
}