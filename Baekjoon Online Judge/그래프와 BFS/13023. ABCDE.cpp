#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define max 2000

int n, m;
vector<int> graph[max];
bool visited[max];

// return 없이 int로 해서 에러 계속났음
void solve(int cnt, int idx) {
	if (cnt == 4) {
		cout << 1;
		exit(0);
	}

	for (int i = 0; i < graph[idx].size(); i++) {
		if (visited[graph[idx][i]] == false) {
			visited[idx] = true;
			solve(cnt + 1, graph[idx][i]);
			visited[idx] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(int i = 0 ;i < n; i++) {
		solve(0, i);
	}
	cout << 0;

	return 0;
}