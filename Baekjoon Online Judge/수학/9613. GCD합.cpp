#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int solve(int a, int b) {
	if (b == 0) return a;
	return solve(b, a % b);
}

int main() {
	int n;
	cin >> n;
	vector<long long> v;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		int arr[100];
		for (int j = 0; j < temp; j++) {
			cin >> arr[j];
		}
		long long sum = 0;
		for (int a = 0; a < temp; a++) {
			for (int b = a + 1; b < temp; b++) {
				sum += solve(arr[a], arr[b]);
			}
		}
		v.push_back(sum);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}