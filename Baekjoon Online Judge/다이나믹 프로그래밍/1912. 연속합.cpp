#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int num[100000];
int dp[100000];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		dp[i] = num[i];
	}

	int Max = dp[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + dp[i], dp[i]);
		Max = max(Max, dp[i]);
	}

	cout << Max;

	return 0;
}