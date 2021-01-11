#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int dp[1001];

int main() {
	int n;
	cin >> n;
	
	if (n == 1) {
		cout << "1";
		return 0;
	}
	if (n == 2) {
		cout << "3";
		return 0;
	}

	dp[1] = 1;
	dp[2] = 3;
	// n - 1까지 차있다고하면 채울수 있는 경우 1가지, n - 2까지 차있다고하면 채울 수 있는 경우 2가지
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + (dp[i - 2] * 2)) % 10007;
	}

	cout << dp[n];

	return 0;
}