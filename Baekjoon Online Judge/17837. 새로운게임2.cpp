#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct piece {
	int r, c, d, layer;
};

int N, K;
int Map[12][12];
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0, };
piece pieces[10];

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int solve() {
	for (int t = 1; t <= 1000; t++) {

		for (int k = 0; k < K; k++) {

			int nr = pieces[k].r + dr[pieces[k].d], nc = pieces[k].c + dc[pieces[k].d];
			if (Map[nr][nc] == 2 || nr < 0 || nr > N - 1 || nc < 0 || nc > N - 1) {
				if (pieces[k].d == 0 || pieces[k].d == 2)
					pieces[k].d++;
				else pieces[k].d--;

				nr = pieces[k].r + dr[pieces[k].d], nc = pieces[k].c + dc[pieces[k].d];
				if (Map[nr][nc] == 2 || nr < 0 || nr > N - 1 || nc < 0 || nc > N - 1)
					continue;
				else k--;
			}
			else if (Map[nr][nc] == 0) {
				int cnt = 0;
				for (int a = 0; a < K; a++) {
					if (pieces[a].r == nr && pieces[a].c == nc)
						cnt++;
				}
				int temp = cnt - pieces[k].layer;
				for (int a = 0; a < K; a++) {
					if (pieces[a].r == pieces[k].r && pieces[a].c == pieces[k].c && pieces[a].layer > pieces[k].layer) {
						pieces[a].r = nr, pieces[a].c = nc, pieces[a].layer += temp;
					}
				}
				pieces[k].r = nr, pieces[k].c = nc, pieces[k].layer = cnt;
			}
			else if (Map[nr][nc] == 1) {
				int cnt = 0;
				for (int a = 0; a < K; a++) {
					if (pieces[a].r == nr && pieces[a].c == nc)
						cnt++;
				}
				int temp = cnt - pieces[k].layer;
				for (int a = 0; a < K; a++) {
					if (pieces[a].r == pieces[k].r && pieces[a].c == pieces[k].c && pieces[a].layer > pieces[k].layer) {
						pieces[a].r = nr, pieces[a].c = nc, pieces[a].layer += temp;
					}
				}
				pieces[k].r = nr, pieces[k].c = nc, pieces[k].layer = cnt;

				vector<pair<int, int>> layer;
				for (int a = 0; a < K; a++) {
					if (pieces[a].r == nr && pieces[a].c == nc && pieces[a].layer >= cnt) {
						layer.push_back(make_pair(pieces[a].layer, a));
					}
				}
				sort(layer.begin(), layer.end(), comp);
				for (int a = 0; a < layer.size(); a++) {
					pieces[layer[a].second].layer = cnt + a;
				}

			}

			for (int a = 0; a < K; a++) {
				if (pieces[a].layer >= 3) return t;
			}
		}

	}

	return -1;
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int r, c, d;
		cin >> r >> c >> d;
		pieces[i] = { r - 1,c - 1,d - 1,0};
	}

	cout << solve() << endl;

	return 0;
}