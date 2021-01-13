#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int num[1001];
int dp[1001];

// n개 뽑았을 때의 최대값은 n - 1 + 1
//  n - 2 + 2 .... n - N + N 중 최대값
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}

	dp[1] = num[1];
	for (int i = 2; i <= N; i++) {

		int temp = num[i];
		for (int j = 1; i - j > 0; j++) {
			temp = min(temp, dp[i - j] + dp[j]);
		}
		dp[i] = temp;
	}

	cout << dp[N];

	return 0;
}