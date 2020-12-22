#include<iostream>
#include<queue>

using namespace std;

#define INF 987654321

struct point {
	int r, c, d;
};

int N;
int Map[20][20];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << Map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int solve(int sr, int sc) {
	int answer = 0;
	int size = 2, cnt = 2;

	point minPt = { sr,sc,INF };
	queue<point> q;

	do {
	//	print();
		minPt.d = INF;
		q.push({ minPt.r,minPt.c,0 });
		bool visited[20][20] = { false };

		while (!q.empty()) {
			point curr = q.front();
			q.pop();

			if (Map[curr.r][curr.c] > size) continue;
			if (Map[curr.r][curr.c] < size && Map[curr.r][curr.c] != 0) {
				if (curr.d == minPt.d) {
					if (curr.r < minPt.r)
						minPt = curr;
					else if (curr.r == minPt.r)
						if (curr.c < minPt.c)
							minPt = curr;
				}
				else if (curr.d < minPt.d)
					minPt = curr;
			}

			for (int i = 0; i < 4; i++) {
				int nr = curr.r + dr[i], nc = curr.c + dc[i];
				if (nr < 0 || nr > N - 1 || nc < 0 || nc > N - 1) continue;
				if (visited[nr][nc] == true) continue;

				visited[nr][nc] = true;
				q.push({ nr,nc,curr.d + 1 });

			}
		}
		if (minPt.d != INF) {
			Map[minPt.r][minPt.c] = 0;
			answer += minPt.d;
			cnt--;
			if (cnt == 0) {
				size++;
				cnt = size;
			}
		}

	} while (minPt.d != INF);



	return answer;
}

int main() {
	cin >> N;
	int sr, sc;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 9) {
				sr = i;
				sc = j;
				Map[i][j] = 0;
			}
		}
	}

	cout << solve(sr,sc) << endl;

	return 0;
}