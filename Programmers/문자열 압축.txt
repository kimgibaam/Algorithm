#include <string>
#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = s.size();
    int original_size = s.size();
    int local_min;
    int cnt;
    
    for(int k =1; k <= s.size()/ 2; k++)  // 자를 크기
    {
        local_min = original_size;
        cnt = 0;
        
        for(int i = 0;i <= s.size() - k; i += k)   // 처음부터 k 만큼씩 이동
        {
            if (s.substr(i, k) == s.substr(i + k, k))   // 앞과 뒤가 같다
            {
                local_min -= k;
                cnt++;
            }
            else           //   다르다
            {
                if(cnt > 0){
                    if(cnt < 9)
                        local_min += 1;
                    else if(cnt < 99)
                        local_min += 2;
                    else if(cnt < 999)
                       local_min += 3;
                    else
                        local_min += 4;
                }
                cnt = 0;
            }
           
        }
        cout << local_min << " ";
        answer = min(answer,local_min);
    }
    
    return answer;
}