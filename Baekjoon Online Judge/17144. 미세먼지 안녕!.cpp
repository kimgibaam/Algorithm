#include<bits/stdc++.h>

using namespace std;

int R, C, T;
int arr[50][50];
int cleaner;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0 , 0 , -1 , 1 };

void print() {
	cout << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {  // position of cleaner
				cleaner = i;
			}
		}
	}

	for (int t = 0; t < T; t++) {
		int diff[50][50];
		memset(diff, 0, sizeof(diff));
		
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (arr[i][j] > 0) {   // spread
					for (int dir = 0; dir < 4; dir++) {
						int nr = i + dr[dir], nc = j + dc[dir];

						if (nr < 0 || nr >= R || nc < 0 || nc >= C || arr[nr][nc] == -1) {
							continue;
						}

						diff[nr][nc] += arr[i][j] / 5;
						diff[i][j] -= arr[i][j] / 5;
					}
				}
			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				arr[i][j] += diff[i][j];
			}
		}    // complete spread

		//print();

		for (int i = cleaner - 2; i > 0 ; i--) {
			arr[i][0] = arr[i - 1][0];
		}
		for (int i = 0; i < C - 1; i++) {
			arr[0][i] = arr[0][i + 1];
		}
		for (int i = 0; i < cleaner - 1; i++) {
			arr[i][C - 1] = arr[i + 1][C - 1];
		}
		for (int i = C - 1; i > 1; i--) {
			arr[cleaner - 1][i] = arr[cleaner -1][i - 1];
		}
		arr[cleaner - 1][1] = 0;

		for (int i = cleaner + 1; i < R - 1; i++) {
			arr[i][0] = arr[i + 1][0];
		}
		for (int i = 0; i < C - 1; i++){
			arr[R - 1][i] = arr[R - 1][i + 1];
		}
		for (int i = R - 1; i > cleaner; i--) {
			arr[i][C - 1] = arr[i - 1][C - 1];
		}
		for (int j = C - 1; j > 1; j--) {
			arr[cleaner][j] = arr[cleaner][j - 1];
		}
		arr[cleaner][1] = 0;
	}
	int sum = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] > 0)
				sum += arr[i][j];
		}
	}
	cout << sum << endl;

	return 0;
}