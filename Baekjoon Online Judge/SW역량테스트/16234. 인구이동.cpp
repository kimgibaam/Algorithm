#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int N, L, R;
int Map[50][50];
int visited[50][50];
int total;
int cnt;

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << Map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void move() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 1) {
				Map[i][j] = total / cnt;
				visited[i][j] = 2;
			}
		}
	}
}

void visiting(int r, int c, int value) {
	if (r < 0 || r > N - 1 || c < 0 || c > N - 1) return;
	if (visited[r][c] != 0) return;

	if (value != -1) {
		int temp = abs(value - Map[r][c]);
		if (temp < L || temp > R) return;
	}

	visited[r][c] = 1;
	total += Map[r][c];
	cnt += 1;
	visiting(r + 1, c, Map[r][c]);
	visiting(r - 1, c, Map[r][c]);
	visiting(r , c + 1 , Map[r][c]);
	visiting(r , c - 1, Map[r][c]);

}

int solve() {
	int answer = 0;
	bool flag;
	do {
		//print();
		memset(visited, 0, sizeof(visited));
		flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == 0) {
					total = 0;
					cnt = 0;
					visiting(i, j, -1);
					if (cnt > 1){
						flag = true;
                        move();
					}
                    else{
                        visited[i][j] = 2;
                    }
				}
			}
		}
		if(flag) answer++;
	} while (flag);


	return answer;
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
		}
	}

	cout << solve() << endl;

	return 0;
}