#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int len = progresses.size();
    
    while(1){ 
        for(int i = 0; i < progresses.size();i++){
            progresses[i] += speeds[i];
        }
        int cnt = 0;
        
        // while 조건 주의할것 
        while(progresses[0] >= 100 && progresses.size() != 0){
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            cnt++;
        }
        if(cnt > 0) {
            answer.push_back(cnt);
        }
        else continue;
        
        int num = 0;
        for(int i = 0; i < answer.size(); i++){
            num += answer[i];
        }
        if(num == len) break;
        
       
    }
    
    return answer;
}