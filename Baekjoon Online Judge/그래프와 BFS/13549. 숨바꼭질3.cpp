#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int visited[100001];

int main() {
	int n, k;
	cin >> n >> k;

	priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, n });
	visited[n] = -1;

	while (!q.empty()) {
		int time = q.top().first;
		int x = q.top().second;
		q.pop();

		if (x == k) {
			cout << time;
			return 0;
		}

		if (x * 2 <= 100000 && visited[x * 2] == 0) {
			visited[x * 2] = time;
			q.push({ time, x * 2 });
		}

		if (x + 1 <= 100000 && visited[x + 1] == 0) {
			visited[x + 1] = time + 1;
			q.push({ time + 1, x + 1 });
		}

		if (x - 1 >= 0 && visited[x - 1] == 0) {
			visited[x - 1] = time + 1;
			q.push({ time + 1, x - 1 });
		}
	}

	return 0;
}