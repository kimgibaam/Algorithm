#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

char map[50][50];
int dist[50][50];
int r, c;
queue<pair<int, int>> water;
queue<pair<int, int>> pet;
pair<int, int> goal;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int bfs() {
	while (!pet.empty()) {
		// 사이즈 변하니까 따로 빼줘야됨
		int ws = water.size();
		for (int i = 0; i < ws; i++) {
			int x = water.front().first;
			int y = water.front().second;
			water.pop();

			for (int d = 0; d < 4; d++) {
				int nr = x + dr[d];
				int nc = y + dc[d];
				if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
				if (map[nr][nc] != '.') continue;

				map[nr][nc] = '*';
				water.push({ nr,nc });
			}
		}

		int ps = pet.size();
		for (int i = 0; i < ps; i++) {
			int x = pet.front().first;
			int y = pet.front().second;
			pet.pop();

			if (x == goal.first && y == goal.second)
				return dist[x][y] - 1;

			for (int d = 0; d < 4; d++) {
				int nr = x + dr[d];
				int nc = y + dc[d];
				if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
				if (map[nr][nc] == 'X' || map[nr][nc] == '*') continue;
				if (dist[nr][nc] != 0) continue;

				dist[nr][nc] = dist[x][y] + 1;
				pet.push({ nr,nc });
			}
		}
	}

	return -1;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			map[i][j] = s[j];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == '*')
				water.push({ i,j });
			else if (map[i][j] == 'S') {
				pet.push({ i,j });
				dist[i][j] = 1;
			}
			else if (map[i][j] == 'D')
				goal = { i,j };
		}
	}

	int result = bfs();
	if (result == -1) cout << "KAKTUS";
	else cout << result;

	return 0;
}