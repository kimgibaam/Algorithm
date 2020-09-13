#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int temp;
    stack<int> s;
    
    for(int i = 0; i < moves.size();i++){
        moves[i] -= 1;
    }
    
    for(int i = 0; i < moves.size();i++){
        for(int h = 0; h < board.size() ; h++){
            if(board[h][moves[i]] == 0){   // 인형없다 더 내려감
                continue;
            }
            else{        // 인형이 있다
                temp = board[h][moves[i]];
                board[h][moves[i]] = 0;
                
                if(s.empty() || s.top() != temp){   // 비었거나 두개가 다르다
                    s.push(temp);
                }
                else{   // 두개가 같다 -> 없어져야되고 카운트 증가
                    s.pop();
                    answer += 2;
                }
                break;
                    
            }
        }

    }
    return answer;
}