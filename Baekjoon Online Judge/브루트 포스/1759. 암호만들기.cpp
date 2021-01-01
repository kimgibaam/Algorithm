#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int l,c;
char arr[15];
vector<char> picked;

void solve(int cnt, int idx) {
	if (cnt == l) {
		int a = 0, b = 0;
		string s = "";
		for (int i = 0; i < l; i++) {
			if (picked[i] == 'a' || picked[i] == 'e' || picked[i] == 'i' || picked[i] == 'o' || picked[i] == 'u') {
				a++;
			}
			else b++;
			s = s + picked[i];
		}
		if (a >= 1 && b >= 2) cout << s << endl;
		return;
	}

	for (int i = idx; i < c; i++) {
		picked.push_back(arr[i]);
		solve(cnt + 1, i + 1);
		picked.pop_back();
	}
}

int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + c);
	solve(0, 0);

	return 0;
}