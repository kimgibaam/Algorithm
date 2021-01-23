#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int n, k;
int alpha[26];
vector<string> input;
int ans = 0;

void answering() {
	int curr = 0;
	for (int i = 0; i < input.size(); i++) {
		bool ok = true;
		for (int j = 0; j < input[i].size(); j++) {
			if (alpha[input[i][j] - 'a'] == 0) {
				ok = false;
				break;
			}
		}
		if (ok == true) curr++;
	}
	ans = max(ans, curr);
}

void dfs(int cnt, int idx) {
	if (cnt == k - 5) {
		answering();
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (alpha[i] == 1) continue;
		alpha[i] = 1;
		dfs(cnt + 1, i + 1);
		alpha[i] = 0;
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		input.push_back(s);
	}

	if (k < 5) {
		cout << 0;
		return 0;
	}
	else if (k == 26) {
		cout << n;
		return 0;
	}

	alpha['a' - 'a'] = 1;
	alpha['n' - 'a'] = 1;
	alpha['t' - 'a'] = 1;
	alpha['i' - 'a'] = 1;
	alpha['c' - 'a'] = 1;

	dfs(0, 0);
	cout << ans;

	return 0;
}