#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int E, S, M;
	cin >> E >> S >> M;
	E = E - 1;
	S = S - 1;
	M = M - 1;

	int e = 0, s = 0, m = 0;
	int count = 1;

	while (e != E || s != S || m != M) {
		e = (e + 1) % 15;
		s = (s + 1) % 28;
		m = (m + 1) % 19;

		count++;
	}
	cout << count;

	return 0;
}