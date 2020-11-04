#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, T;
// 반지름 2~50인 원판 2~50개의 숫자
vector<vector<int>> board;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void del(int r, int c, int num) {
	board[r][c] = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i], nc = c + dc[i];
		if (nc < 0) nc = M - 1;
		else if (nc > M - 1) nc = 0;

 		if (nr < 0 || nr > N - 1) continue;
		if (board[nr][nc] == num) del(nr, nc, num);
	}
}

void check() {
	bool change = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) continue;
			int r = i, c = j;
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i], nc = c + dc[i];
				if (nc < 0) nc = M - 1;
				else if (nc > M - 1) nc = 0;

				if (nr < 0 || nr > N - 1) continue;
				if (board[r][c] == board[nr][nc]) {
					del(r, c, board[r][c]);
					change = true;
					break;
				}
			}
		}
	}

	if (change == true) return;
	else {
		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] != 0) {
					cnt++;
					sum += board[i][j];
				}
			}
		}
		double aver = (double)sum / (double)cnt;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == 0) continue;
				if (board[i][j] < aver )
					board[i][j]++;
				else if (board[i][j] > aver)
					board[i][j]--;
			}
		}
	}
}

int main() {
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		vector<int> v;
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		board.push_back(v);

	}
	for (int i = 0; i < T; i++) {
		int x, d, k;
		cin >> x >> d >> k;
		for (int num = 1; num * x <= N; num++) {
			int idx = num * x - 1;

			if (d == 0) {
				for (int a = 0; a < k; a++) {
					int temp = board[idx].back();
					board[idx].pop_back();
					board[idx].insert(board[idx].begin(), temp);
				}
			}
			else {
				for (int a = 0; a < k; a++) {
					int temp = board[idx].front();
					board[idx].erase(board[idx].begin());
					board[idx].push_back(temp);
				}
			}
		}
		// 회전끝
		check();
	}
	int sum = 0;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			sum += board[i][j];
		}
	}
	cout << sum << endl;
	return 0;
}