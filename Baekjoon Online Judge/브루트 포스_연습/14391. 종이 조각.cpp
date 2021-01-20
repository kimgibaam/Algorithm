#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int n, m;
int map[4][4];
int dir[4][4];   // 가로 1, 세로 2
bool visited[4][4];
int ans = 0;

int sum(int r, int c, int curr) {
	visited[r][c] = true;

	// 가로일 때
	if (dir[r][c] == 1) {
		if (c + 1 < m && dir[r][c + 1] == 1 && visited[r][c + 1] == false) 
			return sum(r, c + 1, (curr + map[r][c]) * 10);
		else 
			return curr + map[r][c];
	}
	else {
		if (r + 1 < n && dir[r + 1][c] == 2 && visited[r + 1][c] == false)
			return sum(r + 1, c, (curr + map[r][c]) * 10);
		else
			return curr + map[r][c];
	}
}

void recur(int cnt) {
	if (cnt == n * m) {
		memset(visited, 0, sizeof(visited));
		int temp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == false) temp += sum(i, j, 0);
			}
		}
		ans = max(ans, temp);
		return;
	}

	int r = cnt / m;
	int c = cnt % m;

	dir[r][c] = 1;
	recur(cnt + 1);
	dir[r][c] = 2;
	recur(cnt + 1);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		// 붙어있는 숫자 입력 방법
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
		}
	}

	recur(0);
	cout << ans;

	return 0;
}