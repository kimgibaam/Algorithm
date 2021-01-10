#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

struct point {
	int d, b, t;
};

int visited[1001][1001]; // display, board

int main() {
	int s;
	cin >> s;

	queue<point> q;
	q.push({ 1,0,0 });
	visited[1][0] = 1;

	while (!q.empty()) {
		point curr = q.front();
		q.pop();

		if (curr.d == s) {
			cout << curr.t;
			return 0;
		}

		// 클립보드에 저장
		if (visited[curr.d][curr.d] == 0) {
			q.push({ curr.d, curr.d, curr.t + 1 });
			visited[curr.d][curr.d] = 1;
		}

		// 붙여넣기
		if (curr.d + curr.b < 1001 && curr.b > 0) {
			if (visited[curr.d + curr.b][curr.b] == 0) {
				q.push({ curr.d + curr.b, curr.b, curr.t + 1 });
				visited[curr.d + curr.b][curr.b] = 1;
			}
		}

		// 이모티콘 한개 제거
		if (curr.d - 1 > 0) {
			if (visited[curr.d - 1][curr.b] == 0) {
				q.push({ curr.d - 1, curr.b, curr.t + 1 });
				visited[curr.d - 1][curr.b] = 1;
			}
		}
	}

	return 0;
}