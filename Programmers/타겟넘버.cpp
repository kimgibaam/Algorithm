#include <string>
#include <vector>

using namespace std;

int answer = 0;
int t;
vector<int> v;

void solve(int cnt,int num){
    if(cnt == v.size()){
        if(num == t) answer++;
        return;
    }
    
    solve(cnt + 1, num - v[cnt]);
    solve(cnt + 1, num + v[cnt]);
}

int solution(vector<int> numbers, int target) {
    v = numbers;
    t = target;
    solve(0,0);
    return answer;
}