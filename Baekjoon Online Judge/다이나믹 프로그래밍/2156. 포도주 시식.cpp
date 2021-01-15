#include<iostream>
#include<algorithm>

using namespace std;

int grape[10001];
int dp[10001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> grape[i];
	}
	
	dp[1] = grape[1];
	dp[2] = grape[1] + grape[2];

	// 마셨는지 안마셨는지 상관없이 가장 큰값이 dp에 들어감
	// 마실수 없는 경우 
	// 첫번째로 마시는 경우  
	// 두번째로 마시는 경우 
	for (int i = 3; i <= n; i++) {
		dp[i] = max(max(dp[i - 1], dp[i - 2] + grape[i]), dp[i - 3] + grape[i - 1] + grape[i]);
	}

	cout << dp[n];

	return 0;
} 