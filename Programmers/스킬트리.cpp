#include <bits/stdc++.h>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i =0; i < skill_trees.size(); i++){
        vector<int> v(skill.size(),30);
        bool ok = true;
        for(int j = 0; j < skill_trees[i].size(); j++){
            for(int k =0; k < skill.size();k++){
                if(skill[k] == skill_trees[i][j]){
                    v[k] = j;
                }
            }
        }// 한 스킬트리 끝
        for(int i =0;i< v.size() -1;i++){
            if(v[i] > v[i + 1]) {
                ok = false;
                break;
            }
        }
        if(ok) answer++;
    }
    
    return answer;
}