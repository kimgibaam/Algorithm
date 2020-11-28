#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i = 0; i < scoville.size();i++){
        q.push(scoville[i]);
    }
    
    while(!q.empty()){
        int first = q.top();
        int second;
        q.pop();
        
        if(first >= K) break;
        else {
            if(q.size() == 0) return -1;
            else if(q.size() >= 1){
                second = q.top();
                q.pop();
            }
        }
        q.push(first + (second * 2));
        
        answer++;
    }
    
    return answer;
}