#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int board[9][9];

// n번 행,열,사각형에 k가 있는가?
bool col[9][9];
bool row[9][9];
bool square[9][9];

void dfs(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}

		exit(0);
	}

	int r = cnt / 9;
	int c = cnt % 9;

	if (board[r][c] != 0) {
		dfs(cnt + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			// 들어갈수 있으면 들어가고 다음 자리 dfs
			if (col[c][i] == false && row[r][i] == false && square[(r / 3) * 3 + (c / 3)][i] == false) {
				col[c][i] = true;
				row[r][i] = true;
				square[(r / 3) * 3 + (c / 3)][i] = true;
				board[r][c] = i;

				dfs(cnt + 1);

				col[c][i] = false;
				row[r][i] = false;
				square[(r / 3) * 3 + (c / 3)][i] = false;
				board[r][c] = 0;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0;j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) {
				row[i][board[i][j]] = true;
				col[j][board[i][j]] = true;
				// 사각형의 숫자가 정해지는 식
				square[(i / 3) * 3 + (j / 3)][board[i][j]] = true;
			}
		}
	}

	dfs(0);

	return 0;
}