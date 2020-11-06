#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    int Map[1001][1001] = {0};
    
    int num = 1;
    int r = 0, c = 0;
    int last = 0;
    for(int k = 1; k <= n; k++){
        last += k;
    }
    
    while(1){
        while(Map[r][c] == 0 && r < n)
            Map[r++][c] = num++;
        if(num > last) break;
        r--;
        c++;
        while(Map[r][c] == 0 && c < n)
            Map[r][c++] = num++;
        if(num > last) break;
        c--;
        
        r--;
        c--;
        while(Map[r][c] == 0)
            Map[r--][c--] = num++;
        if(num > last) break;
        r++;
        c++;
        r++;
    }
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n; j++){
            if(Map[i][j] != 0)
                answer.push_back(Map[i][j]);
        }
    }
    
    return answer;
}