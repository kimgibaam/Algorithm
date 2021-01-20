#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int R, C;
char map[20][20];
bool alpha[26];
int ans = 0;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void dfs(int r, int c, int d) {
	ans = max(ans, d);

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
		if (alpha[map[nr][nc] - 'A'] == true) continue;

		alpha[map[nr][nc] - 'A'] = true;
		dfs(nr, nc, d + 1);
		alpha[map[nr][nc] - 'A'] = false;
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	alpha[map[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << ans;

	return 0;
}