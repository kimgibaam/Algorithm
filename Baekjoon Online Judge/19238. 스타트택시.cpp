#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define INF 987654321

struct custom {
	int sr, sc, er, ec;
};
struct point {
	int r, c, d;
};

int N, M, power;
int Map[20][20];
int dist[20][20];
vector<custom> customs;
queue<point> q;
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

void init(int arr[20][20]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = INF;
		}
	}
}

void print(int arr[20][20]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int solve(int r, int c) {
	while (customs.size() > 0) {
		init(dist);
		q.push({ r,c,0 });
		dist[r][c] = 0;
		while (!q.empty()) {
			point curr = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nr = curr.r + dr[i], nc = curr.c + dc[i];
				if (nr < 0 || nr > N - 1 || nc < 0 || nc > N - 1 || Map[nr][nc] == 1 || dist[nr][nc] != INF) continue;

				dist[nr][nc] = curr.d + 1;
				q.push({ nr,nc,curr.d + 1 });
			}
			
		}
		
		int texi_num = 0;
		point minPt{ r,c,INF };
		for (int i = 0; i < M; i++) {
			if (dist[customs[i].sr][customs[i].sc] < minPt.d) {
				minPt = { customs[i].sr ,customs[i].sc ,dist[customs[i].sr][customs[i].sc] };
				texi_num = i;
			}
			else if (dist[customs[i].sr][customs[i].sc] == minPt.d) {
				if (customs[i].sr < minPt.r) {
					minPt = { customs[i].sr ,customs[i].sc ,dist[customs[i].sr][customs[i].sc] };
					texi_num = i;
				}
				else if (customs[i].sr == minPt.r) {
					if (customs[i].sc < minPt.c) {
						minPt = { customs[i].sr ,customs[i].sc ,dist[customs[i].sr][customs[i].sc] };
						texi_num = i;
					}
				}
			}
		}

		power -= minPt.d;   // 가장 가까운 손님
		r = minPt.r;
		c = minPt.c;
		if (power <= 0) return -1;    
		//print(dist);

		init(dist);
		q.push({ r,c,0 });
		dist[r][c] = 0;
		while (!q.empty()) {
			point curr = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nr = curr.r + dr[i], nc = curr.c + dc[i];
				if (nr < 0 || nr > N - 1 || nc < 0 || nc > N - 1 || Map[nr][nc] == 1 || dist[nr][nc] != INF) continue;

				dist[nr][nc] = curr.d + 1;
				q.push({ nr,nc,curr.d + 1 });
			}
			
		}
		
		if (power - dist[customs[texi_num].er][customs[texi_num].ec] < 0) return -1;
		power += dist[customs[texi_num].er][customs[texi_num].ec];

		r = customs[texi_num].er;
		c = customs[texi_num].ec;
		
		customs.erase(customs.begin() + texi_num, customs.begin() + texi_num + 1);
		M--;
		
		//print(dist);

	}

	return power;
}

int main() {
	cin >> N >> M >> power;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
		}
	}
	int tr, tc;
	cin >> tr >> tc;
	int sr, sc, er, ec;
	for (int i = 0; i < M; i++) {
		cin >> sr >> sc >> er >> ec;
		customs.push_back({ sr - 1,sc - 1,er - 1,ec - 1});
	}
	cout << solve(tr - 1,tc - 1) << endl;

	return 0;
}