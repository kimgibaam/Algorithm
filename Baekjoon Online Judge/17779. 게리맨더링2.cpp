#include<iostream>
#include<algorithm>

using namespace std;

int n;
int arr[21][21];
int answer = 999999999;

void print(int map[21][21]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void fill(int map[21][21], int i, int j, int num) {
	map[i][j] = num;

	if (i - 1 >= 1 && map[i - 1][j] == 0) fill(map, i - 1, j, num);
	if (i + 1 <= n && map[i + 1][j] == 0) fill(map, i + 1, j, num);
	if (j - 1 >= 1 && map[i][j - 1] == 0) fill(map, i, j - 1, num);
	if (j + 1 <= n && map[i][j + 1] == 0) fill(map, i, j + 1, num);
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int x = 1; x < n - 1; x++) {
		for (int y = 2; y < n; y++) {
			for (int d1 = 1; y - d1 >= 1; d1++) {
				for (int d2 = 1; x + d1 + d2 <= n && y + d2 <= n; d2++){
					int place[21][21] = { 0 };

					for (int a = 0; a <= d1; a++) {
						place[x + a][y - a] = 5;
						place[x + d2 + a][y + d2 - a] = 5;
					}
					for (int a = 0; a <= d2; a++) {
						place[x + a][y + a] = 5;
						place[x + d1 + a][y - d1 + a] = 5;
					}
					for (int a = 1; x - a >= 1; a++) {
						place[x - a][y] = 1;
					}
					for (int a = 1; y + d2 + a <= n; a++) {
						place[x + d2][y + d2 + a] = 2;
					}
					for (int a = 1; y - d1 - a >= 1; a++) {
						place[x + d1][y - d1 - a] = 3;
					}
					for (int a = 1; x + d1 + d2 + a <= n; a++) {
						place[x + d1 + d2 + a][y - d1 + d2] = 4;
					}

					fill(place, 1, 1, 1);
					fill(place, 1, n, 2);
					fill(place, n, 1, 3);
					fill(place, n, n, 4);

					//print(place);

					int people[6] = { 0 };
					for (int i = 1; i <= n; i++) {
						for (int j = 1; j <= n; j++) {
							people[place[i][j]] += arr[i][j];
						}
					}
					people[5] += people[0];
					people[0] = 0;

					sort(people, people + 6);

					int temp = people[5] - people[1];
					answer = min(temp, answer);
					
				}
			}
		}
	}
	cout << answer;

	return 0;
}