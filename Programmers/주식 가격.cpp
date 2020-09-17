#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int count =0;
    for(int i = 0;i < prices.size(); i++){
        for(int j = i; j < prices.size() - 1; j++){
            if(prices[i] <= prices[j]){
                count++;
            }
            else {
                break;
            }
        }
        answer.push_back(count);
        count = 0;
        
    }
    return answer;
}