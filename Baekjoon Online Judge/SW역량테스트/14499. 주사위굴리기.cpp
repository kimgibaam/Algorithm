#include<iostream>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;

int N, M;
int x, y;
int Map[20][20];
int commandCnt;
vector<int> dice(6,0);
int dr[] = { 0,0,0,-1,1 };  // 1번부터 동서북남
int dc[] = { 0,1,-1,0,0 };

void moving(int fix1, int fix2, int dir) {
	list<int> move;
	int temp;
	for (int i = 0; i < 6; i++) {
		if (i == fix1 || i == fix2) continue;
		move.push_back(dice[i]);
	}
	if (dir == 1 || dir == 3) {
		temp = move.back();
		move.pop_back();
		move.push_front(temp);
	}
	else {
		temp = move.front();
		move.pop_front();
		move.push_back(temp);
	}

	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		if (i == fix1 || i == fix2) continue;
		dice[i] = move.front();
		move.pop_front();
	}
}

int main() {
	cin >> N >> M;
	cin >> x >> y >> commandCnt;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}
	int dir;
	for (int i = 0; i < commandCnt; i++) {
		cin >> dir;
		int nr = x + dr[dir], nc = y + dc[dir];
		if (nr < 0 || nr > N - 1 || nc < 0 || nc > M - 1) continue;
		x = nr;
		y = nc;

		// 주사위 움직임
		if (dir == 1) {  // 동쪽
			moving(0, 4, dir);
		}
		else if (dir == 2) {
			moving(0, 4, dir);
		}
		else if (dir == 3) {
			moving(1, 3, dir);
		}
		else if (dir == 4) {
			moving(1, 3, dir);
		}

		if (Map[nr][nc] == 0) {
			Map[nr][nc] = dice[5];
		}
		else {
			dice[5] = Map[nr][nc];
			Map[nr][nc] = 0;
		}

		cout << dice[2] << endl;
	}
	return 0;
}