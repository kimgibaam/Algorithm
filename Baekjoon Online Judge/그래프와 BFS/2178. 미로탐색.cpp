#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

struct point {
	int r, c, d;
};

int dr[] = { -1,1,0,0 };
int dc[] = { 0, 0, -1,1 };
int n, m;
int map[100][100];
int visited[100][100];
int answer = 0;

void bfs(int r, int c) {
	queue<point> q;
	q.push({ r,c,1 });
	while (!q.empty()) {
		point curr = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = curr.r + dr[i];
			int nc = curr.c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
			if (visited[nr][nc] == 1) continue;
			if (map[nr][nc] == 0) continue;

			visited[nr][nc] = 1;
			q.push({ nr,nc,curr.d + 1 });

			if (nr == n - 1 && nc == m - 1)
				answer = curr.d + 1;
		}
	}
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

	bfs(0,0);
	cout << answer;

	return 0;
}