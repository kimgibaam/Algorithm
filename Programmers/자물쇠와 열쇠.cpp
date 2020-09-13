#include <bits/stdc++.h>
using namespace std;

int lock_size;
int key_size;

bool check(int arr[60][60]){
    for(int i = 20; i < 20 + lock_size; i++){
        for(int j = 20; j < 20 + lock_size; j++){
            if(arr[i][j] != 1)
                return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int arr[60][60];   // 0 초기화
    lock_size = lock.size();
    key_size = key.size();
    
    for(int i = 20; i < 20 + lock.size(); i++){
        for(int j = 20; j < 20 + lock.size(); j++){
            arr[i][j] = lock[i - 20][j - 20];
        }
    }
    
    int temp[60][60];
    vector<vector<int>> temp_key(key_size,vector<int>(key_size));  // 2차원 벡터 정적 선언
    
    for(int t = 0; t < 4; t++){
        for(int i = 0; i < 40; i++){
            for(int j = 0; j < 40; j++){   // 큰격자판 각 첫자리부터 덧셈시작
                copy(&arr[0][0],&arr[0][0]+60*60,&temp[0][0]);   // 2차원 배열 복사
            
                for(int a = 0; a < key.size(); a++){
                    for(int b = 0; b< key.size(); b++){
                        temp[i + a][j + b] += key[a][b]; 
                    }
                }   // 다 더했음
            
                if(check(temp)) return true;
            }
        }
        //회전
        int r = 0, c = key_size - 1;
        copy(key.begin(),key.end(),temp_key.begin());
        for (int x = 0 ; x < key_size; x++){
            for(int y = 0 ; y< key_size;y++){
                key[r][c] = temp_key[x][y];
                r++;
            }
            c--;
            r = 0;
        }
    }    
        
    return false;
}