#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define offset 1000000009

long long dp[100001][4];

// n개 뽑았을 때의 마지막 수가 1 일때 : n-1에서 마지막수 2,3 인것의 합
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

		if (n == 1 || n == 2) {
			cout << "1" << endl;
			continue;
		}
		else if (n == 3) {
			cout << "3" << endl;
			continue;
		}
		
		for (int i = 4; i <= n; i++) {
			dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % offset;
			dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % offset;
			dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % offset;
		}

		cout << (dp[n][1] + dp[n][2] + dp[n][3]) % offset << endl;;
	}

	return 0;
}