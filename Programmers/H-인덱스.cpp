#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    
    for(int i = 0; i < citations.size(); i++){
        bool flag = true;
        int h = citations.size() - i;
        for(int j = i; j< citations.size(); j++){
            if(citations[j] >= h) continue;
            else flag = false;
        }
        if(flag == false) {
            continue;
        }
        else {
            answer = max(answer,h);
        }
        cout << flag << endl;
    }
    
    return answer;
}