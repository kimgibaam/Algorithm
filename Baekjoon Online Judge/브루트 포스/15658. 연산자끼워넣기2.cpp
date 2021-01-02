#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n;
int arr[11];
int calc[4];
vector<int> picked;
int maxi = -99999999999;
int mini = 99999999999;

//중복없는 순열
void solve(int cnt) {
	if (cnt == n - 1) {
		int total = arr[0];
		for (int i = 0; i < n - 1; i++) {
			if (picked[i] == 0) 
				total += arr[i + 1];
			else if (picked[i] == 1) 
				total -= arr[i + 1];
			else if (picked[i] == 2)
				total *= arr[i + 1];
			else if (picked[i] == 3)
				total /= arr[i + 1];
		}
		maxi = max(maxi, total);
		mini = min(mini, total);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (calc[i] == 0) continue;
		picked.push_back(i);
		calc[i] -= 1;

		solve(cnt + 1);

		picked.pop_back();
		calc[i] += 1;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> calc[i];
	}

	solve(0);
	cout << maxi << endl;
	cout << mini << endl;
	return 0;
}