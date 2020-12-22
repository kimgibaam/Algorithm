#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp == 1 || temp == 0) continue;
		for (int k = 2; k < temp; k++) {
			if (temp % k == 0) {
				cnt--;
				break;
			}
		}
		cnt++;
	}
	cout << cnt;

	return 0;
}