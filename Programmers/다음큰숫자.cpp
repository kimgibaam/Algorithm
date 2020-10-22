#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int num = n;
    int cnt = 0;
    while(num != 0) {
        if(num % 2 != 0) cnt++;
        num /= 2;
    }
    while(1) {
        n++;
        num = n;
        int count = 0;
        while(num != 0) {
            if(num % 2 != 0) count++;
            num /= 2;
        }
        if(cnt == count) break;
    }
    
    return n;
}