#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
#define INF 987654321
#define BLUE 1
#define RED 0

struct ball {
	int r, c;
	bool out;
};

int N, M;
int Map[10][10];
int answer = INF;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
ball balls[2];

bool check() {
	return balls[RED].out || balls[BLUE].out;
}

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << Map[i][j];
		}
		cout << endl;
	}
	cout << endl; 
}

void move(int dir) {
	bool escR = false, escB = false;
	int nr, nc;
	while (escR == false || escB == false) {
		if (escR == false) {
			nr = balls[RED].r + dr[dir];
			nc = balls[RED].c + dc[dir];
			if (Map[nr][nc] == 1) {
				escR = true;
			}
			else if (Map[nr][nc] == 4) {
				escR = true;
				balls[RED].out = true;
				Map[balls[RED].r][balls[RED].c] = 0;
			}
			else if (Map[nr][nc] == 3 && escB == true) {
				escR = true;
			}
			else if (Map[nr][nc] == 0) {
				Map[balls[RED].r][balls[RED].c] = 0;
				Map[nr][nc] = 2;
				balls[RED].r = nr;
				balls[RED].c = nc;
			}
		}
		//cout << nr << " " << nc << endl;

		if (escB == false) {
			nr = balls[BLUE].r + dr[dir];
			nc = balls[BLUE].c + dc[dir];
			if (Map[nr][nc] == 1) {
				escB = true;
			}
			else if (Map[nr][nc] == 4) {
				escB = true;
				balls[BLUE].out = true;
				Map[balls[BLUE].r][balls[BLUE].c] = 0;
				return;
			}
			else if (Map[nr][nc] == 2 && escR == true) {
				escB = true;
			}
			else if (Map[nr][nc] == 0) {
				Map[balls[BLUE].r][balls[BLUE].c] = 0;
				Map[nr][nc] = 3;
				balls[BLUE].r = nr;
				balls[BLUE].c = nc;
			}
		}
		//cout << nr << " " << nc << endl;
	}
	//print();
	//cout << dir << endl << endl << endl;
}

void solve(int cnt, int pre) {
	if (cnt == 10 || check()) {
		if (balls[RED].out == true && balls[BLUE].out == false) {
			answer = min(answer, cnt);
		}
		return;
	}

	int backup[10][10];
	ball backup_ball[2];
	memcpy(backup, Map, sizeof(Map));
	memcpy(backup_ball, balls, sizeof(balls));
	for (int i = 0; i < 4; i++) {
		if (pre == i) continue;
		move(i);
		solve(cnt + 1, i);
		memcpy(Map, backup, sizeof(Map));
		memcpy(balls, backup_ball, sizeof(balls));
	}
}

int main() {
	cin >> N >> M;
	char temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp;
			if (temp == '#')
				Map[i][j] = 1;
			else if (temp == '.')
				Map[i][j] = 0;
			else if (temp == 'R') {
				Map[i][j] = 2;
				balls[RED] = { i,j,false };
			}
			else if (temp == 'B') {
				Map[i][j] = 3;
				balls[BLUE] = { i,j,false };
			}
			else if (temp == 'O')
				Map[i][j] = 4;
		}
	}

	solve(0,-1);
	if (answer == INF)
		cout << -1 << endl;
	else
		cout << answer << endl;

	return 0;
}