#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string,int> m;
    
    for(int i = 0; i < clothes.size(); i++){
        m[clothes[i][1]]++;
    }
    int mul = 1;
    for(map<string,int>::iterator it = m.begin(); it != m.end(); it++){
        mul *= (it->second + 1);
    }
    return mul - 1;
}