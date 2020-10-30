#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

struct Cam {
	int r,c,type;
};

int N, M;
int Map[8][8];
int camCnt;
Cam cam[8];
int dr[] = { 0,-1,0,1 };   // 오른쪽 위 왼쪽 아래
int dc[] = { -1,0,1,0 };   // dir
int dcam[5][4] = { {1,0,0,0},{1,0,1,0},{0,1,1,0},{1,1,1,0},{1,1,1,1} };  // [type][dir]
int answer;

void marking(int camNum, int dir) {
	int r = cam[camNum].r, c = cam[camNum].c;
	while (1) {
		int nr = r + dr[dir], nc = c + dc[dir];
		if (nr < 0 || nr > N - 1 || nc < 0 || nc > M - 1) return;
		if (Map[nr][nc] == 6) return;
		Map[nr][nc] = 9;
		r = nr;
		c = nc;
	}
}

void solve(int camNum) {
	if (camNum == camCnt) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (Map[i][j] == 0) {
					sum++;
				}
			}
		}
		answer = min(answer, sum);
		return;
	}

	int backup[8][8];
	int type = cam[camNum].type;

	memcpy(backup, Map, sizeof(Map));
	for (int i = 0; i < 4; i++) {   // i는 시작점  -> dr,dc
		for (int j = 0; j < 4; j++) {  // j는 각 방향  -> dcam
			if (dcam[type][j] == 0) continue;
			marking(camNum, (i + j) % 4);
		}
		solve(camNum + 1);
		memcpy(Map, backup, sizeof(Map));
	}
}

int main() {
	cin >> N >> M;
	camCnt = 0;
	answer = 987654321;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
			if (Map[i][j] != 0 && Map[i][j] != 6) {
				cam[camCnt].r = i;
				cam[camCnt].c = j;
				cam[camCnt++].type = Map[i][j] - 1;
			}
		}
	}
	solve(0);
	cout << answer << endl;
	return 0;
}