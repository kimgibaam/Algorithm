#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define mod 1000000000

// n일때 k개 써서 만들수 있는 경우의 수
long long dp[201][201];

int main() {
	int N, K;
	cin >> N >> K;

	// 0부터 n까지니까 0도 포함
	for (int i = 0; i <= N; i++)
		dp[i][1] = 1;

	for (int n = 0; n <= N; n++) {
		for (int k = 2; k <= K; k++) {
			for (int x = 0; x <= n; x++) {   // 0부터 n까지니까 0도 포함
				dp[n][k] = (dp[n][k] + dp[x][k - 1]) % mod;
			}
		}
	}
	
	cout << dp[N][K];

	return 0;
}