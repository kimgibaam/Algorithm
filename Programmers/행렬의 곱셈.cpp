#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size());
    vector<vector<int>> arr2_turn(arr2[0].size(),vector<int>(arr2.size()));
    for(int i = 0;i < arr2.size();i++){
        for(int j = 0; j < arr2[0].size(); j++){
            arr2_turn[j][i] = arr2[i][j];
        }
    }
    
    for(int i = 0; i < arr1.size();i++) {
        for(int j = 0; j < arr2_turn.size(); j++){
            
            int sum = 0;
            for(int k =0 ;k < arr1[0].size(); k++){
                sum += (arr1[i][k] * arr2_turn[j][k]);
            }
            answer[i].push_back(sum);
        }
    }
    
    return answer;
}