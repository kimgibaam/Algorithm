#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define mod 10007

int dp[1001][10];

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	// 현재 숫자가 i번째이고 끝자리가 j로 끝날때
	// i - 1에서 끝자리가 0~j까지 오는 경우의 수를 합한다
	for (int i = 2; i <= 1000; i++) {
		for (int j = 0; j < 10; j++) {
			int temp = 0;
			for (int k = 0; k <= j; k++) {
				temp = (temp + dp[i - 1][k]) % mod;
			}
			dp[i][j] = temp;
		}
	}

	int result = 0;
	for (int i = 0; i < 10; i++)
		result = (result + dp[n][i]) % mod;
	cout << result;

	return 0;
}