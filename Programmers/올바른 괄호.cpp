#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> mstack;
    
    for(int i = 0 ; i < s.size(); i++){
        if(s[i] == '(') mstack.push(s[i]);
        else {
            if(mstack.empty()) return false;
            mstack.pop();
        }
    }
    if(mstack.empty()) return true;
    else return false;
}