#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    vector<pair<int,int>> bridge;
    int idx = 0;
    
    while(1){                
        if(!bridge.empty()){
            if(bridge.front().second == bridge_length){
                bridge.erase(bridge.begin(),bridge.begin() + 1);
            }
        }

        int sum = 0;
        for(int i = 0;i < bridge.size();i++){
            sum += bridge[i].first;
        }
        if(sum + truck_weights[idx] <= weight && idx < truck_weights.size()){ 
            bridge.push_back(make_pair(truck_weights[idx], 0));
            idx++;
        }
        if(bridge.empty()) break;

        
        for(int i = 0;i < bridge.size();i++){
            bridge[i].second += 1;
        }
        answer++;

    }
    
    return answer;
}