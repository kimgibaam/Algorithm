#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

struct point {
	int r, c, d;
};

int n, m;
int map[1000][1000];
int visited[1000][1000];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
int answer = 0;

void bfs() {
	queue<point> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {  // 중괄호 잘안쳐주면 에러남
				visited[i][j] = 1;
				q.push({ i,j,0 });
			}
		}
	}

	while (!q.empty()) {
		point curr = q.front();
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nr = curr.r + dr[d];
			int nc = curr.c + dc[d];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
			if (map[nr][nc] != 0) continue;
			if (visited[nr][nc] == 1) continue;

			visited[nr][nc] = 1;
			map[nr][nc] = curr.d + 1;
			q.push({ nr,nc,curr.d + 1 });
			answer = curr.d + 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0)
				answer = -1;
		}
	}
}

int main() {
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	bfs();

	cout << answer;

	return 0;
}