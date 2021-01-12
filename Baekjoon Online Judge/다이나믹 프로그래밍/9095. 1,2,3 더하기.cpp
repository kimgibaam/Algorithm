#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> picked;
int num;
int result;

void solve(int cnt) {
	if (cnt >= num) {
		if (cnt > num) return;
		else result++;
		return;
	}

	for (int i = 1; i < 4; i++) {
		cnt += i;
		solve(cnt);
		cnt -= i;
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> num;

		result = 0;
		solve(0);
		cout << result << endl;
	}

	return 0;
}