#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

// 소수인가?
bool arr[4000001];
int n;

void eratos() {
	for (int i = 1; i <= n; i++)
		arr[i] = true;
	for (int i = 2; i * i <= n; i++) {
		if (arr[i] == false) continue;
		for (int j = i + i; j <= n; j += i) {
			arr[j] = false;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	eratos();

	int ans = 0;
	for (int i = 2; i <= n; i++) {  // 시작 위치
		if (arr[i] == false) continue;
		int sum = 0;
		for (int j = i; j <= n; j++) {  // 끝나는 위치
			if (arr[j] == true) sum += j;
			if (sum >= n) {
				if (sum == n) ans++;
				break;
			}
		}
	}

	cout << ans;

	return 0;
}