#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// n 자리수의 끝자리 수가 0,1;
long long dp[91][2];

int main() {
	int n;
	cin >> n;

	dp[1][1] = 1;
	dp[2][0] = 1;
	dp[3][1] = 1;
	dp[3][0] = 1;

	for (int i = 4; i <= 90; i++) {
		dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[n][0] + dp[n][1];

	return 0;
}