#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int mini = 1000000000;
int maxi = -1000000000;

int N;
int num[11];
int calc[4];

void solve(vector<int> picked, int cnt) {
	if (cnt == 0) {
		int answer = num[0];
		for (int i = 0; i < N - 1; i++) {
			if (picked[i] == 0)
				answer += num[i + 1];
			else if (picked[i] == 1)
				answer -= num[i + 1];
			else if (picked[i] == 2)
				answer *= num[i + 1];
			else if (picked[i] == 3)
				answer /= num[i + 1];
		}
		mini = min(mini, answer);
		maxi = max(maxi, answer);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (calc[i] == 0) continue;
		calc[i]--;
		picked.push_back(i);
		solve(picked, cnt - 1);

		calc[i]++;
		picked.pop_back();
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> calc[i];
	}
	vector<int> v;
	solve(v,N - 1);
	cout << maxi << endl;
	cout << mini << endl;
	return 0;
}