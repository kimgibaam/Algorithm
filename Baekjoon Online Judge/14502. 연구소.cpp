#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int N, M;
int Map[8][8];
int answer = 0;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void check() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 0) cnt++;
		}
	}
	answer = max(answer, cnt);
}

void fill(int r, int c) {
	Map[r][c] = 2;
	if (r - 1 >= 0 && Map[r-1][c] == 0) fill(r - 1, c);
	if (r + 1 <= N - 1 && Map[r + 1][c] == 0) fill(r + 1, c);
	if (c - 1 >= 0 && Map[r][c - 1] == 0) fill(r, c - 1);
	if (c + 1 <= M - 1 && Map[r][c + 1] == 0) fill(r, c + 1);
}

void solve(int cnt, int pos) {
	if (cnt == 3 || pos >= N * M) {
		if (cnt < 3) return;

		int backup[8][8];
		memcpy(backup, Map, sizeof(Map));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (Map[i][j] == 2) {
					fill(i,j);
				}
			}
		}
		check();
		memcpy(Map, backup, sizeof(Map));
		return;
	}

	int r = pos / M, c = pos % M;
	if (Map[r][c] != 0) {
		solve(cnt, pos + 1);
	}
	else {
		Map[r][c] = 1;
		solve(cnt + 1, pos + 1);
		Map[r][c] = 0;

		solve(cnt, pos + 1);
	}
	
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}
	solve(0,0);
	cout << answer << endl;
	return 0;
}