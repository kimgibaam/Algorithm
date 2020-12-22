#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int N;
int Map[101][101];
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

void print() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cout << Map[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int solve() {
	int ret = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (Map[i][j] == 1 && Map[i][j + 1] == 1 && Map[i + 1][j] == 1 && Map[i + 1][j + 1] == 1) {
				ret++;
			}
		}
	}
	return ret;
}

int main() {
	cin >> N;
	memset(Map, 0, sizeof(Map));
	for (int i = 0; i < N; i++) {
		vector<int> curves;
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		curves.push_back(d);
		for (int j = 0; j < g; j++) {
			for (int k = curves.size() - 1; k >= 0; k--) {
				curves.push_back((curves[k] + 1) % 4);
			}
		}

		Map[y][x] = 1;
		for (int num = 0; num < curves.size(); num++) {
			x += dx[curves[num]], y += dy[curves[num]];
			Map[y][x] = 1;
		}
	//	print();
	}

	cout << solve() << endl;

	return 0;
}