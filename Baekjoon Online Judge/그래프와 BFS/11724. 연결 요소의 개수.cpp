#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int arr[1001][1001];
int visited[1001];
int answer = 0;
int n, m;

void bfs(int start) {
	if (visited[start] == 1) return;

	queue<int> q;
	q.push(start);
	visited[start] = 1;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (arr[curr][i] == 0) continue;
			if (visited[i] == 1) continue;
			visited[i] = 1;
			q.push(i);
		}
	}
	answer++;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		bfs(i);
	}

	cout << answer;

	return 0;
}