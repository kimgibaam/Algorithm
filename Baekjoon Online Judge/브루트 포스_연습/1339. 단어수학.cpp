#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

vector<string> input;
int alpha[26];

bool comp(pair<int, char> a, pair<int, char> b) {
	return a.first > b.first;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		input.push_back(s);
	}

	for (int i = 0; i < n; i++) {
		int offset = 1;
		for (int j = input[i].size() - 1; j >= 0; j--) {
			alpha[input[i][j] - 'A'] += offset;
			offset *= 10;
		}
	}

	vector<pair<int, char>> v;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] != 0) {
			v.push_back(make_pair(alpha[i], i + 'A'));
		}
	}
	sort(v.begin(), v.end(), comp);

	int ans = 0;
	int offset = 9;
	for (int i = 0; i < v.size(); i++) {
		ans += v[i].first * offset;
		offset--;
	}

	cout << ans;

	return 0;
}