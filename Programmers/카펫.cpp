#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool comp(int a, int b){
    return a> b;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int r,c;
    for(int i = yellow ; i >= 1; i--){
        if(yellow % i == 0){
            r = i;
            c = yellow / i;
            
            if((r * 2) + (c * 2) + 4 == brown){
                answer.push_back(r + 2);
                answer.push_back(c + 2);
                break;
            }
        }
    }
    sort(answer.begin(),answer.end(),comp);
    
    return answer;
}