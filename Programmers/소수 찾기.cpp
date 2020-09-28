#include <bits/stdc++.h>

using namespace std;

int arr[7];
bool visited[7];
vector<int> v;
set<int> s;
int len;

// 중복이 허용되지 않는 순열
void dfs(int cnt, int tocnt){
    if(cnt == tocnt){
        string temp;
        
        // 결과값
        for(int k = 0; k < v.size(); k++){
            temp += to_string(v[k]);
        }
        int num = stoi(temp);
        
        // 소수 판별
        if(num == 0 || num == 1) return;
        for(int a = 2; a < num; a++){
            if(num % a == 0) return;
        }
        s.insert(num);
        return;
    }
    
    for(int i = 0; i < len; i ++){
        if(visited[i]) continue;
        visited[i] = true;
        v.push_back(arr[i]);
        dfs(cnt + 1,tocnt);
        visited[i] = false;
        v.pop_back();
    }
}

int solution(string numbers) {
    len = numbers.size();
    
    // 문자 -> 숫자
    for(int i =0; i < len;i++){
        arr[i] = numbers[i] - '0';
    }
    
    // 각 선택 개수 마다 완전 탐색
    for(int i = 1;i <= len; i++){
        dfs(0,i);    
    }
    
    return s.size();
}