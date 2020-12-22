#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

int N;
int Map[20][20];
int answer = 0;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void check() {
	int num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Map[i][j] > num)
				num = Map[i][j];
		}
	}
	answer = max(answer, num);
}

void go(int merged[20][20], int r, int c, int dir) {
	int nr, nc;
	while (1) {
		nr = r + dr[dir];
		nc = c + dc[dir];
		if (nr < 0 || nr > N - 1 || nc < 0 || nc > N - 1) break;
		if (Map[nr][nc] == Map[r][c]) {
			if (merged[nr][nc] == 0) {
				Map[nr][nc] += Map[r][c];
				Map[r][c] = 0;
				merged[nr][nc] = 1;
			}
			break;
		}
		else if (Map[nr][nc] == 0) {
			Map[nr][nc] = Map[r][c];
			Map[r][c] = 0;
		}
		else if (Map[nr][nc] != Map[r][c]) {
			break;
		}
		r = nr, c = nc;
	}
}

void move(int dir) {
	int merged[20][20] = { 0 };
	if (dir == 0) {
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (Map[i][j] == 0) continue;
				go(merged, i, j, dir);
			}
		}
	}
	else if (dir == 1) {
		for (int i = N-1; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				if (Map[i][j] == 0) continue;
				go(merged, i, j, dir);
			}
		}
	}
	else if (dir == 2) {
		for (int j = 1; j < N; j++) {
			for (int i = 0; i < N; i++) {
				if (Map[i][j] == 0) continue;
				go(merged, i, j, dir);
			}
		}
	}
	else if (dir == 3) {
		for (int j = N - 1; j >= 0; j--) {
			for (int i = 0; i < N; i++) {
				if (Map[i][j] == 0) continue;
				go(merged, i, j, dir);
			}
		}
	}
}

void solve(int cnt) {
	if (cnt == 5) {
		check();
		return;
	}

	int backup[20][20];
	memcpy(backup, Map, sizeof(Map));
	for (int i = 0; i < 4; i++) {
		move(i);
		solve(cnt + 1);
		memcpy(Map, backup, sizeof(Map));
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
		}
	}
	solve(0);
	cout << answer << endl;
	return 0;
}