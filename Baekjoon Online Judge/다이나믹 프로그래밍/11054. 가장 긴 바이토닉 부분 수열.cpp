#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[1000];
int dp[1000][2];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i][0] = dp[i][1] = 1;
	}
	
	for (int i = 0; i < n; i++) {
		int Max = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[j] < Max)
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		int Max = arr[i];
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < Max)
				dp[i][1] = max(dp[i][1], dp[j][1] + 1);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(dp[i][0] + dp[i][1], ans);
	cout << ans - 1;
		
	return 0;
}