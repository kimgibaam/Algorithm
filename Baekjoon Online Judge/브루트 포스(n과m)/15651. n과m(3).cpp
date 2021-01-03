#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n, m;
vector<int> picked;

void solve(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << picked[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		picked.push_back(i);
		solve(cnt + 1);
		picked.pop_back();
	}
}

int main() {
	cin >> n >> m;

	solve(0);

	return 0;
}