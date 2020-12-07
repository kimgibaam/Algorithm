#include <string>
#include <vector>

using namespace std;

int num[100000];

int solution(int n) {
    num[1] = 1;
    for(int i = 2; i <= n; i++){
        num[i] = (num[i - 1] + num[i - 2]) % 1234567;
    }
    
    return num[n] % 1234567;
}