#include <iostream>

using namespace std;
int map[101][101] = { 0, };
int total[101][101] = { 0, };

int main(void) {
	int n = 0, m = 0;
	int a = 0, b = 0, cost = 0;;
	cin >> n;
	cin >> m;

	for (int i = 1; i < n + 1; i++) { // 100001로 초기화
		for (int j = 1; j < n + 1; j++) {
			if (i != j)
				total[i][j] = 20000002;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> cost;
		if (total[a][b] > cost)
			total[a][b] = cost;
	}

	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (total[i][j] > (total[i][k] + total[k][j])) {
					total[i][j] = (total[i][k] + total[k][j]);
				}
			}
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (total[i][j] == 20000002) {
				total[i][j] = 0;
			}
			cout << total[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}