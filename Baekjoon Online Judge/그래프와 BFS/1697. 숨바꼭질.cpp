#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

struct point {
	int n, t;
};

int visited[100001];

int main() {
	int n, k;
	cin >> n >> k;

	if (n == k) {
		cout << "0";
		return 0;
	}

	queue<point> q;

	q.push({ n,0 });
	visited[n] = -1;

	while (!q.empty()) {
		point curr = q.front();
		q.pop();

		if (curr.n + 1 <= 100000 && visited[curr.n + 1] == 0) {
			q.push({ curr.n + 1, curr.t + 1 });
			visited[curr.n + 1] = curr.t + 1;
		}
		if (curr.n - 1 >= 0 && visited[curr.n - 1] == 0) {
			q.push({curr.n - 1, curr.t + 1});
			visited[curr.n - 1] = curr.t + 1;
		}
		if (curr.n * 2 <= 100000 && visited[curr.n * 2] == 0) {
			q.push({ curr.n * 2, curr.t + 1 });
			visited[curr.n * 2] = curr.t + 1;
		}
		
	}
	cout << visited[k];

	return 0;
}