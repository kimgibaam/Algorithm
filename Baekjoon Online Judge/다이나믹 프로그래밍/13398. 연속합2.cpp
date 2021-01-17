#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int num[100000];
// 1은 제거한번 했음을 의미
int dp[100000][2];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		dp[i][0] = num[i];
	}

	int ans = dp[0][0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0] + num[i], num[i]);
		// 자기 자신을 제거한 값 vs 이전에 한번 제거했던 값
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + num[i]); 
		ans = max(ans, max(dp[i][0], dp[i][1]));
	}

	cout << ans;

	return 0;
}