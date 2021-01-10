#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int map[50][50];
int visited[50][50];
int w, h;
int dr[] = { -1,-1,-1,0,1,1,1,0 };
int dc[] = { -1,0,1,1,1,0,-1,-1 };

void dfs(int r, int c) {
	for (int k = 0; k < 8; k++) {
		int nr = r + dr[k];
		int nc = c + dc[k];
		if (nr >= h || nr < 0 || nc >= w || nc < 0) continue;
		if (visited[nr][nc] == 1) continue;
		if (map[nr][nc] == 0) continue;

		visited[nr][nc] = 1;
		dfs(nr, nc);
	}
}

int main() {
	vector<int> answers;
	do {
		cin >> w >> h;
		// 반복문에 h ,w 순서 잘 체크할것
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		int answer = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (visited[i][j] == 0 && map[i][j] == 1) {
					answer++;
					visited[i][j] = 1;
					dfs(i, j);
				}
			}
		}
		
		answers.push_back(answer);
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));

	} while (!(w == 0 && h == 0));

	for (int i = 0; i < answers.size() - 1; i++) {
		cout << answers[i] << endl;
	}

	return 0;
}