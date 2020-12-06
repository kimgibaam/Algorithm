#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int num = 1;
    while(num <= n){
        int temp = num;
        for(int k = temp + 1; temp <= n; k++){
            if(temp == n) {
                answer++;
                break;
            }
            temp += k;
        }
        num++;
    }
    
    return answer;
}