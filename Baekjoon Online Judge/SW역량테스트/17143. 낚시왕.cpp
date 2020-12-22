#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

struct shark {
	int s, d, z;
};

shark Map[100][100];
shark temp[100][100];
int dr[5] = {0, -1,1,0,0 };
int dc[5] = {0, 0,0,1,-1 };
int R, C, M;
int answer = 0;

void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << Map[i][j].z << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void solve() {
	for (int j = 0; j < C; j++) {
		for (int i = 0; i < R; i++) {  // 낚시
			if (Map[i][j].z != 0) {
				answer += Map[i][j].z;
				Map[i][j].z = 0;
				break;
			}
		}

		memset(temp, 0, sizeof(temp));  // 이동 후를 저장할 배열
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if (Map[r][c].z != 0) {   // 상어가 있으면 이동
					int nr = r + dr[Map[r][c].d] * Map[r][c].s;
					int nc = c + dc[Map[r][c].d] * Map[r][c].s;
					int dir = Map[r][c].d;
					if (nr < 0) {
						nr *= -1;
						dir = 2;
					}
					if (nr > R - 1) {
						int a = nr / (R - 1);
						int b = nr % (R - 1);
						if (a % 2 == 0) {  
							nr = b;
						}
						else {
							nr = R - 1 - b;
							dir = 1;
						}
					}

					if (nc < 0) {
						nc *= -1;
						dir = 3;
					}
					if (nc > C - 1) {
						int a = nc / (C - 1);
						int b = nc % (C - 1);
						if (a % 2 == 0) {
							nc = b;
						}
						else {
							nc = C - 1 - b;
							dir = 4;
						}
					}
					if (temp[nr][nc].z < Map[r][c].z) {
						temp[nr][nc] = Map[r][c];
						temp[nr][nc].d = dir;
					}
				}
			}
		}
		memcpy(Map, temp, sizeof(temp));
		//print();
	}
}

int main() {
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		Map[r - 1][c - 1] = { s,d,z };
	}
	solve();
	cout << answer << endl;

	return 0;
}