#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

int N, M;
vector<int> v;
vector<int> picked;
map<int, int> m;

void solve(int cnt, int idx) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << picked[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		if (m[v[i]] == 0) continue;
		picked.push_back(v[i]);
		m[v[i]]--;
		solve(cnt + 1, i);
		picked.pop_back();
		m[v[i]]++;

	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (m[temp] == 0) {
			m[temp] = 1;
			v.push_back(temp);
		}
		else m[temp]++;
	}
	sort(v.begin(), v.end());
	solve(0, 0);

	return 0;
}