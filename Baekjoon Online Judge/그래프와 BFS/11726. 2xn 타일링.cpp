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
		cout << "2";
		return 0;
	}

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[n];

	return 0;
}