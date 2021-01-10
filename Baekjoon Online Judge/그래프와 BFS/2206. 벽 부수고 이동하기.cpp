#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int map[1000][1000];
int visited[1000][1000][2];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
int n, m;

int bfs() {

	queue<pair<int, pair<int, int>>> q;
	q.push({ 0,{0,0} });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		pair<int, pair<int, int>> curr = q.front();
		q.pop();

		int r = curr.second.first;
		int c = curr.second.second;
		int b = curr.first;

		if (r == n - 1 && c == m - 1) {
			return visited[r][c][b];
		}

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

			// 벽이 있고 아직 안뚫었다
			if (map[nr][nc] == 1 && b == 0) {
				visited[nr][nc][b + 1] = visited[r][c][b] + 1;
				q.push({ b + 1, {nr,nc} });
			}
			// 벽이 없고 방문안했다
			else if (visited[nr][nc][b] == 0 && map[nr][nc] == 0) {
				visited[nr][nc][b] = visited[r][c][b] + 1;
				q.push({ b, {nr,nc} });
			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
		}
	}
	cout << bfs();

	return 0;
}