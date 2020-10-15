#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int Map[500][500];
int visited[500][500];
int answer = 0;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void bfs(int r, int c, int sum) {
	int cnt = 0;
	int mini = 987654321;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i], nc = c + dc[i];
		if (nr < 0 || nr > N - 1 || nc < 0 || nc > M - 1) continue;
		cnt++;
		mini = min(mini, Map[nr][nc]);
		sum += Map[nr][nc];
	}

	if (cnt == 3) {
		answer = max(answer, sum);
	}
	else if (cnt == 4) {
		answer = max(answer, sum - mini);
	}
	else {
		return;
	}
}

void dfs(int cnt, int r, int c, int sum) {
	if (cnt == 3) {
		answer = max(answer, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {

		int nr = r + dr[i], nc = c + dc[i];
		if (nr < 0 || nr > N - 1 || nc < 0 || nc > M - 1 || visited[nr][nc] == 1) continue;
		visited[nr][nc] = 1;
		sum += Map[nr][nc];

		dfs(cnt + 1, nr, nc, sum);

		visited[nr][nc] = 0;
		sum -= Map[nr][nc];
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 1;
			dfs(0,i,j,Map[i][j]);
			bfs(i, j, Map[i][j]);
			visited[i][j] = 0;
		}
	}
	cout << answer << endl;
	return 0;
}