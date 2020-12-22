#include<iostream>
#include<algorithm>
#include<list>

using namespace std;

struct tree {
	int r, c, age;
	bool alive;
};

int	N, M, K;
list<tree> trees;
int Map[10][10];
int A[10][10];
int dr[] = {-1,-1,-1,0,0,1,1,1};
int dc[] = {-1,0,1,-1,1,-1,0,1};

int solve() {
	for (int k = 0; k < K; k++) {
		for (list<tree>::iterator it = trees.begin(); it != trees.end(); it++) {
			if (Map[it->r][it->c] >= it->age) {
				Map[it->r][it->c] -= it->age;
				it->age++;
			}
			else {
				it->alive = false;
			}
		}
		for (list<tree>::iterator it = trees.begin();it != trees.end();) {
			if (it->alive) {  
				it++;
			}
			else {
				Map[it->r][it->c] += it->age / 2;
				it = trees.erase(it);
			}
		}
		for (list<tree>::iterator it = trees.begin(); it != trees.end(); it++) {
			if (it->age % 5 == 0) {
				for (int j = 0; j < 8; j++) {
					int nr = it->r + dr[j], nc = it->c + dc[j];
					if (nr < 0 || nr > N - 1 || nc < 0 || nc > N - 1) continue;

					trees.push_front({nr,nc,1,true});
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				Map[i][j] += A[i][j];
			}
		}
	}
	return trees.size();
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			Map[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int r, c, age;
		cin >> r >> c >> age;
		trees.push_back({r - 1,c - 1, age, true});
	}

	cout << solve() << endl;

	return 0;
}