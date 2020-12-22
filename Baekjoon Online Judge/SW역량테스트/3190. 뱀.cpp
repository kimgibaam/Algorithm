#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Snake {
	int head_r, head_c, tail_r, tail_c;
};

int dr[] = { 0,-1,0,1 };
int dc[] = { -1,0,1,0 };  // 좌상우하 -> 시계방향 회전
int N, K, L;
int Map[102][102];
int Dir_Map[102][102];
vector<pair<int,char>> turning;
int r, c;

void print() {
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			cout << Map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int solve() {
	Snake snake = { 1,1,1,1 };
	Map[snake.head_r][snake.head_c] = 3;
	int dir = 2; // 첫방향은 오른쪽

	int t = 0;
	while (1) {
		if (!turning.empty() && turning[0].first == t) {
			if (turning[0].second == 'D') // 오른쪽
				dir++;
			else
				dir--;
			if (dir > 3) dir = 0;
			if (dir < 0) dir = 3;
			turning.erase(turning.begin());
		}
		t++;
		int nr = snake.head_r + dr[dir], nc = snake.head_c + dc[dir];
		if (Map[nr][nc] == 2) {  // 사과가 있다.
			Map[nr][nc] = 3;
			Dir_Map[snake.head_r][snake.head_c] = dir;
			snake.head_r = nr, snake.head_c = nc;
			// 꼬리는 그대로
		}
		else if (Map[nr][nc] == 0) {  // 빈곳
			Map[nr][nc] = 3;
			Dir_Map[snake.head_r][snake.head_c] = dir;
			snake.head_r = nr, snake.head_c = nc;

			Map[snake.tail_r][snake.tail_c] = 0;
			int r = snake.tail_r, c = snake.tail_c;
			snake.tail_r += dr[Dir_Map[r][c]], snake.tail_c += dc[Dir_Map[r][c]];

		}
		else if (Map[nr][nc] == 1 || Map[nr][nc] == 3) { // 벽이거나 자기몸
			break;
		}
	}

	return t;
}

int main() {
	cin >> N >> K;
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			if (i == 0 || i == N + 1 || j == 0 || j == N + 1)
				Map[i][j] = 1;
			else Map[i][j] = 0;
		}
	}
	int x, y;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		Map[x][y] = 2;
	}
	cin >> L;
	int t;
	char d;
	for (int i = 0; i < L; i++) {
		cin >> t >> d;
		turning.push_back(make_pair(t, d));
	}

	cout << solve() << endl;

	return 0;
}