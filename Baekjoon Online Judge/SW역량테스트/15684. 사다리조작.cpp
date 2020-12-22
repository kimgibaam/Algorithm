#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define RIGHT 1
#define LEFT 2
#define INF 987654321

int N, M, H;
int Map[30][10];
int answer = INF;

void print() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			cout << Map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool check() {
	for (int i = 0; i < N; i++) {
		int r = 0, c = i;
		while (r < H) {
			if (Map[r][c] == RIGHT)
				c++;
			else if (Map[r][c] == LEFT)
				c--;
			r++;
		}
		if (c != i) return false;
	}
	return true;
}

void solve(int cnt, int pos) {
	if (cnt == 3 || pos >= N * H) {
		if (check())
			answer = min(answer, cnt);
		//print();
		//cout << cnt << endl;
		return;
	}
	int r = pos / N, c = pos % N;
	if (c < N - 1 && Map[r][c] == 0 && Map[r][c + 1] == 0) {
		Map[r][c] = RIGHT;
		Map[r][c + 1] = LEFT;
		solve(cnt + 1, pos + 2);
		Map[r][c] = Map[r][c + 1] = 0;
	}
	solve(cnt, pos + 1);
}


int main() {
	memset(Map, 0, sizeof(Map));
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int r, c;
		cin >> r >> c;
		Map[r - 1][c - 1] = RIGHT;
		Map[r - 1][c] = LEFT;
	}

	solve(0,0);
	if (answer == INF)
		cout << -1 << endl;
	else
		cout << answer << endl;
	
	return 0;
}