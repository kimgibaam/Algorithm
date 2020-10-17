#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

struct Shark {
	int curr;
	int dir[4][4];
};

struct Map {
	int shark, smell, cnt;
};

int N, M, K;
Map map[20][20];
int temp[20][20];
vector<Shark> sharks;

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j].shark << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int solve() {
	int t = 0;
	int m;
	do {
		memset(temp, 0, sizeof(temp));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j].shark != 0) {
					bool moved = false;
					int num = map[i][j].shark;
					int curr = sharks[num].curr;
					for (int k = 0; k < 4; k++) {
						int dir = sharks[num].dir[curr][k];
						int nr = i + dr[dir], nc = j + dc[dir];
						if (nr < 0 || nr > N - 1 || nc < 0 || nc > N - 1 || map[nr][nc].smell != 0) continue;
						moved = true;
						map[i][j].shark = 0;
						sharks[num].curr = dir;
						if(temp[nr][nc] == 0)
							temp[nr][nc] = num;
						else if(temp[nr][nc] > num)
							temp[nr][nc] = num;
						break;
					}
					if (moved == false){					
						for (int k = 0; k < 4; k++) {
							int dir = sharks[num].dir[curr][k];
							int nr = i + dr[dir], nc = j + dc[dir];
							if (nr < 0 || nr > N - 1 || nc < 0 || nc > N - 1 || map[nr][nc].smell != num) continue;
							moved = true;
							map[i][j].shark = 0;
							sharks[num].curr = dir;
							if (temp[nr][nc] == 0)
								temp[nr][nc] = num;
							else if (temp[nr][nc] > num)
								temp[nr][nc] = num;
							break;
						}
					}
					if (moved == false) {
						temp[i][j] = num;
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j].smell != 0) {
					map[i][j].cnt--;
					if (map[i][j].cnt == 0)
						map[i][j].smell = 0;
				}
			}
		}

		m = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (temp[i][j] != 0) {
					map[i][j].shark = temp[i][j];
					map[i][j].smell = temp[i][j];
					map[i][j].cnt = K;
					m++;
				}
			}
		}
		t++;
		if (t > 1000) {
			t = -1;
			break;
		}
	} while (m > 1);

	return t;
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j].shark;
			if (map[i][j].shark != 0) {
				map[i][j].cnt = K;
				map[i][j].smell = map[i][j].shark;
			}
		}
	}
	vector<Shark> temp(M + 1);
	for (int i = 1; i <= M; i++) {
		cin >> temp[i].curr;
		temp[i].curr--;
	}
	sharks = temp;

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				int temp;
				cin >> temp;
				sharks[i].dir[j][k] = temp - 1;
			}
		}
	}

	cout << solve() << endl;

	return 0;
}