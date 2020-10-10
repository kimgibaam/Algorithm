#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, B, C;
vector<int> room;
long long answer = 0;

void solve() {
	for (int i = 0; i < room.size(); i++) {
		int person = room[i];
		person -= B;
		answer++;

		if (person <= 0) continue;
		else {
			int div = person / C;
			if (person % C != 0) div += 1;
			answer += div;
		}

	}
}

int main() {
	cin >> N;
	int temp;
	for (int i = 0; i < N;i++) {
		cin >> temp;
		room.push_back(temp);
	}
	cin >> B >> C;

	solve();
	cout << answer << endl;

	return 0;
}