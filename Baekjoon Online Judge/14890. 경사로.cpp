#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int N, L;
int Map[200][100];
int answer;

void solve() {
	for (int i = 0; i < 2 * N; i++) {
		int dist = 1;
		int j;
		for (j = 0; j < N - 1; j++) {
			if (Map[i][j] == Map[i][j + 1]) dist++;
			else if (abs(Map[i][j] - Map[i][j + 1]) > 1) break;
			else if (Map[i][j] - Map[i][j + 1] == 1) {
				if (dist < 0) break;
				dist = 1 - L;
			}
			else if (Map[i][j] - Map[i][j + 1] == -1) {
				if (dist < L) break;
				else dist = 1;
			}
		}
		if (j < N - 1 || dist < 0) {
		//	cout << i << endl;
			answer--;
		}
	}
}

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Map[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Map[N + i][j] = Map[j][i];
		}
	}

	answer = 2 * N;
	solve();
	cout << answer << endl;
	return 0;
}