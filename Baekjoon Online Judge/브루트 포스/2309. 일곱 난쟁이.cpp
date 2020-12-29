#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[10];
vector<int> picked;
vector<int> v;

void check() {
	int sum = 0;
	for (int i = 0; i < picked.size(); i++) {
		sum += picked[i];
	}
	if (sum == 100) v = picked;
	else return;
}

void solve(int cnt, int idx) {
	if (cnt == 7) {
		check();
		return;
	}

	for (int i = idx; i < 9; i++) {
		picked.push_back(arr[i]);
		solve(cnt + 1, i + 1);
		picked.pop_back();
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	solve(0,0);
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	return 0;
}