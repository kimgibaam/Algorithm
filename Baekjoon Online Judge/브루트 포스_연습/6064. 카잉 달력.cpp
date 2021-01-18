#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int max_year = lcm(m,n);

		while (x < max_year) {
			int yp = x % n;
			if (yp == 0) yp = n;
			if (yp == y) break;

			x += m;
		}
		if (x >= max_year) cout << -1 << endl;
		else cout << x << endl;
		
	}

	return 0;
}