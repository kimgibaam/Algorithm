#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


int main() {
	int n;
	cin >> n;

	long long ans = 0;
	int offset = 1;
	int lim = 10;

	for (int i = 1; i <= n; i++) {
		if (i >= lim) {
			offset++;
			lim *= 10;
		}

		ans += offset;
	}
	cout << ans;

	return 0;
}