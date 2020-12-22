#include<iostream>
#include<algorithm>

using namespace std;

int solve(int a, int b) {
	if (b == 0) return a;
	return solve(b, a % b);
}

int main() {
	int A, B;
	cin >> A >> B;

	cout << solve(A, B) << endl;
	cout << (A * B) / solve(A, B) << endl;

	return 0;
}