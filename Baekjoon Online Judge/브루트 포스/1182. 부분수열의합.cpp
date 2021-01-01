#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int arr[20];
int n, s;
vector<int> picked;
int answer = 0;

void solve(int cnt) {
	if (cnt == n) {
		if (picked.size() == 0) return;

		int sum = 0;
		for (int i = 0; i < picked.size(); i++) {
			sum += picked[i];
		}
		if (sum == s) answer++;

		return;
	}

	picked.push_back(arr[cnt]);
	solve(cnt + 1);
	picked.pop_back();

	solve(cnt + 1);
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	solve(0);
	cout << answer;

	return 0;
}