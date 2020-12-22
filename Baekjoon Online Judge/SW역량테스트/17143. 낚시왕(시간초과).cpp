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
			cout << Map[i][j].d << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void move(int r, int c) {
	int move_cnt = Map[r][c].s;
	int dir = Map[r][c].d;
	int size = Map[r][c].z;

	int nr = r, nc = c;
	for (int i = 0; i < move_cnt; i++) {
		if (dir == 1 || dir == 2) {  // 상하
			if (nr + dr[dir] < R && nr + dr[dir] >= 0)
				nr += dr[dir];
			else {
				if (dir == 1) dir = 2;
				else if (dir == 2) dir = 1;
				nr += dr[dir];
			}

		}
		else {    // 좌우
			if (nc + dc[dir] <C && nc + dc[dir] >= 0)
				nc += dc[dir];
			else {
				if (dir == 3) dir = 4;
				else if (dir == 4) dir = 3;
				nc += dc[dir];
			}
		}
		
	}

	if (temp[nr][nc].z < Map[r][c].z) {
		temp[nr][nc] = Map[r][c];
		temp[nr][nc].d = dir;
	}

}

void solve() {
	for (int j = 0; j < C; j++) {
		//print();
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
					move(r,c);
				}
			}
		}
		memcpy(Map, temp, sizeof(temp));
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