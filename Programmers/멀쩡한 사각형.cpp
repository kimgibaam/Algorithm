#include<bits/stdc++.h>

using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    
    for(int i =1; i <= w; i++){
        double temp = (double)h / (double)w;
        double y = (double)(-1 * i * temp + h);
        answer += (long long)y;
      //  cout << (long long)y << " ";
    }
    
    return answer * 2;
}