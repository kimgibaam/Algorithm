#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

int visited[4];
vector<vector<int>> wheels;

void turning(int num, int dir) {
	visited[num] = 1;
	if (num -1 >= 0 && wheels[num][6] != wheels[num - 1][2] && visited[num - 1] == 0) {
		turning(num - 1, dir == 1 ? -1 : 1);
	}
	if (num + 1 < 4 && wheels[num][2] != wheels[num + 1][6] && visited[num + 1] == 0) {
		turning(num + 1, dir == 1 ? -11 : 1);
	}

	if (dir == 1) {  // 시계방향
		int temp = wheels[num].back();
		wheels[num].erase(wheels[num].end() - 1);
		wheels[num].insert(wheels[num].begin(), temp);
	}
	else {
		int temp = wheels[num].front();
		wheels[num].erase(wheels[num].begin());
		wheels[num].push_back(temp);
	}
}

int main() {
	string temp;
	for (int i = 0; i < 4; i++) {
		cin >> temp;
		vector<int> wheel;
		for (int i = 0; i < 8; i++) {
			wheel.push_back(temp[i] - '0');
		}
		wheels.push_back(wheel);
	}
	int turn;
	cin >> turn;
	for (int i = 0; i < turn; i++) {
		int num, dir;
		cin >> num >> dir;

		memset(visited, 0, sizeof(visited));
		turning(num - 1, dir);
	}
	int answer = 0;
	if (wheels[0][0] == 1) answer += 1;
	if (wheels[1][0] == 1) answer += 2;
	if (wheels[2][0] == 1) answer += 4;
	if (wheels[3][0] == 1) answer += 8;
	cout << answer << endl;

	return 0;
}