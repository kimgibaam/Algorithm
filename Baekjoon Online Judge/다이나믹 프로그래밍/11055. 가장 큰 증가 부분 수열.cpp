#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[1000];
int dp[1000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
	
	for (int i = 1; i < n; i++) {
		int Max = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[j] < Max)
				dp[i] = max(dp[i], dp[j] + arr[i]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(dp[i], ans);
	cout << ans;
		
	return 0;
}