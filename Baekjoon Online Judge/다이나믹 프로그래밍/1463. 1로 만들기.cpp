#include<iostream>
#include<algorithm>

using namespace std;

int arr[1000000];

int main() {
	int n;
	cin >> n;

	arr[0] = 9999999;
	for (int i = 2; i <= n; i++) {
		int t1, t2, t3;
		if (i % 3 == 0) t1 = i / 3;
		else t1 = 0;

		if (i % 2 == 0) t2 = i / 2;
		else t2 = 0;

		t3 = i - 1;

		int temp = min(min(arr[t1], arr[t2]), arr[t3]);

		arr[i] = temp + 1;
	}
	cout << arr[n];

	return 0;
}