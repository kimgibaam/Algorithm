#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n, m;
vector<int> picked;
int visited[9];

void solve(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << picked[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 1) continue;
		picked.push_back(i);
		visited[i] = 1;
		solve(cnt + 1);
		picked.pop_back();
		visited[i] = 0;
	}
}

int main() {
	cin >> n >> m;

	solve(0);

	return 0;
}