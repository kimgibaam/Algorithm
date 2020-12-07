#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    stringstream ss(s);
    string num;
    vector<int> nums;
    while(ss >> num){
        nums.push_back(stoi(num));
    }
    sort(nums.begin(),nums.end());
    answer = to_string(nums.front()) + " " + to_string(nums.back());
    return answer;
}