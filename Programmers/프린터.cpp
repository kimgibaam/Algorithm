#include <bits/stdc++.h>

using namespace std;
bool comp(int a, int b){
    return a > b;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q;
    
    for(int i = 0; i < priorities.size(); i++){
        q.push(make_pair(priorities[i],i));    
    }
    sort(priorities.begin(),priorities.end(),comp);
    
    int idx = 0;
    pair<int,int> temp;
    while(!q.empty()){
        if(q.front().first == priorities[idx]){
            answer++;
            if(q.front().second == location) return answer;
            q.pop();
            idx++;
        }
        else {
            temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    
    return answer;
}