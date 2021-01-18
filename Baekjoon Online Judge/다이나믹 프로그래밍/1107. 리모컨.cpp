#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int broken[10];

// 누를수 있는가
bool check(int i) {
	if (i == 0) {
		if (broken[0] == 1)
			return false;
		else return true;
	}

	while (i != 0) {
		if (broken[i % 10] == 1)
			return false;
		i /= 10;
	}
	return true;
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		broken[temp] = 1;
	}

	int ans = abs(100 - N);
	for (int i = 0; i <= 10000000; i++) {
		int temp = 0;
		if (check(i))
			temp = abs(N - i);
		else continue;

		int offset;
		if (i >= 10000000) offset = 8;
		else if (i >= 1000000) offset = 7;
		else if (i >= 100000) offset = 6;
		else if (i >= 10000) offset = 5;
		else if (i >= 1000) offset = 4;
		else if (i >= 100) offset = 3;
		else if (i >= 10) offset = 2;
		else offset = 1;

		temp += offset;
		ans = min(ans, temp);
	}

	cout << ans;

	return 0;
}