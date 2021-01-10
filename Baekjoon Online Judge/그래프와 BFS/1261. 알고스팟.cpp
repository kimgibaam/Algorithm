#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int map[100][100];
int visited[100][100];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int main() {
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
		}
	}

	priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
	q.push({ 0, {0,0} });
	visited[0][0] = 1;

	while (!q.empty()) {
		pair<int,pair<int,int>> curr = q.top();
		q.pop();
		int r = curr.second.first;
		int c = curr.second.second;
		int w = curr.first;

		if (r == n - 1 && c == m - 1) {
			cout << w;
			return 0;
		}

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
			if (visited[nr][nc] == 1) continue;

			visited[nr][nc] = 1;
			if (map[nr][nc] == 0)
				q.push({ w, {nr,nc}});
			else
				q.push({ w + 1, {nr,nc} });

		}

	}
}