#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int answer = 987654321;
int N;
int Map[20][20];
vector<int> start;
vector<int> link;
int visited[20];

void solve(int cnt, int idx) {
	if (cnt == N / 2) {
		for (int i = 0; i < N; i++) {
			if (visited[i] == 0) {
				link.push_back(i);
			}
		}
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < start.size(); i++) {
			for (int j = 0; j < start.size(); j++) {
				sum1 += Map[start[i]][start[j]];
				sum2 += Map[link[i]][link[j]];
			}
		}
		int diff = abs(sum1 - sum2);
		answer = min(answer, diff);
		link.clear();
		return;
	}

	for (int i = idx; i < N; i++) {
		start.push_back(i);
		visited[i] = 1;
		solve(cnt + 1, i + 1);
		start.pop_back();
		visited[i] = 0;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
		}
	}

	solve(0,0);
	cout << answer << endl;

	return 0;
}