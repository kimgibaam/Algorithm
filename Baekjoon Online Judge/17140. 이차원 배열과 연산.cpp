#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int r, c, k;
int arr[100][100];

void print() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int solve() {
	int rsize = 3; 
	int csize = 3;
	for (int t = 0; t <= 100; t++) {
		if (arr[r][c] == k) return t;

		if (rsize >= csize) {   // r 연산
			for (int i = 0; i < rsize; i++) {
				int cnt[101] = { 0 };
				for (int j = 0; j < csize; j++) {
					cnt[arr[i][j]]++;
				}
				vector<pair<int, int>> v;
				for (int idx = 1; idx < 101; idx++) {
					if (cnt[idx] != 0) {
						v.push_back(make_pair(cnt[idx], idx));
					}
				}
				sort(v.begin(), v.end());
				int idx = 0;
				for (int a = 0; a < v.size();a++) {
					arr[i][idx++] = v[a].second;
					arr[i][idx++] = v[a].first;
					if (idx >= 99) break;
				}

				csize = max(csize, idx);
				for (; idx < 100; idx++) {
					arr[i][idx] = 0;
				}
			}

		}
		else {   // c 연산
			for (int j = 0; j < csize; j++) {
				int cnt[101] = { 0 };
				for (int i = 0; i < rsize; i++) {
					cnt[arr[i][j]]++;
				}
				vector<pair<int, int>> v;
				for (int idx = 1; idx < 101; idx++) {
					if (cnt[idx] != 0) {
						v.push_back(make_pair(cnt[idx], idx));
					}
				}
				sort(v.begin(), v.end());
				int idx = 0;
				for (int a = 0; a < v.size(); a++) {
					arr[idx++][j] = v[a].second;
					arr[idx++][j] = v[a].first;
					if (idx >= 99) break;
				}

				rsize = max(rsize, idx);
				for (; idx < 100; idx++) {
					arr[idx][j] = 0;
				}
			}
		}
		//print();

	}
	return -1;
}


int main() {
	cin >> r >> c >> k;
	r--;  c--;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	cout << solve() << endl;

	return 0;
}