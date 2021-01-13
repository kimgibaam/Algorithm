#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define mod 1000000000

// n 일때 뒤에 끝나는 숫자가 0~9일 각각의 경우
int dp[101][10];

int main() {
	int n;
	cin >> n;

	// 0 으로 시작하는 수는 없다
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j < 10; j++) {
			if (j + 1 >= 10)
				dp[i][j] = dp[i - 1][j - 1];
			else if (j - 1 < 0)
				dp[i][j] = dp[i - 1][j + 1];
			else
				dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % mod;
		}
	}

	int result = 0;
	for (int i = 0; i < 10; i++)
		result = (result + dp[n][i]) % mod;
	cout << result;

	return 0;
}