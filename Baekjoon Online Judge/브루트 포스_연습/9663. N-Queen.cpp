#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n;
int ans = 0;
int board[15];

bool check(int level) {
	// 행이 같거나 같은 대각선상에 있으면 false
	for (int i = 0; i < level; i++) {
		if (board[i] == board[level] || abs(board[i] - board[level]) == level - i)
			return false;
	}
	return true;
}

void nqueen(int col) {
	if (col == n)
		ans++;

	for (int row = 0; row < n; row++) {
		board[col] = row;  // col 열의 row 행에 퀸 배치
		if (check(col))  // 놓을수 있다면 놓고 다음 열
			nqueen(col + 1);
		// 놓을수 없으면 다음 행
	}

}

int main() {
	cin >> n;
	nqueen(0);
	cout << ans;
	return 0;
}