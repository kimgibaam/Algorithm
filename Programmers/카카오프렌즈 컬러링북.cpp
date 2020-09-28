#include <bits/stdc++.h>

using namespace std;

int visited[100][100];
int cnt;
int r,c;

void print(){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void recur(vector<vector<int>> picture, int i, int j){
    visited[i][j] = 1;
    cnt++;
    if(j + 1 < c){
        if(picture[i][j + 1] == picture[i][j] && visited[i][j + 1] == 0)
            recur(picture, i, j + 1);
    }
    if( i + 1 < r){
        if(picture[i + 1][j] == picture[i][j] && visited[i + 1][j] == 0)
            recur(picture,i + 1, j);
    }
    if( i - 1 >= 0){
        if(picture[i - 1][j] == picture[i][j] && visited[i - 1][j] == 0)
            recur(picture,i - 1, j);
    }
    if( j - 1 >= 0 ){
        if(picture[i][j - 1] == picture[i][j] && visited[i][j - 1] == 0)
            recur(picture,i, j - 1);
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> v;
    memset(visited,0,sizeof(visited));
    cnt = 0;
    r = m;
    c = n;
 
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] == 0 && picture[i][j] != 0){
                recur(picture,i,j);
                //print();
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }

    sort(v.begin(),v.end());
    
    vector<int> answer(2);
    answer[1] = v.back();
    answer[0] = v.size();
    return answer;
}