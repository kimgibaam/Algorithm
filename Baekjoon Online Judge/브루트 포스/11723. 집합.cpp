#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n;
int arr[20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		int num;
		cin >> str;
		if (str != "all" && str != "empty") {
			cin >> num;
			num -= 1;
		}

		if (str == "add") {
			arr[num] = 1;
		}
		else if (str == "check") {
			cout << arr[num] << "\n";
		}
		else if (str == "remove") {
			arr[num] = 0;
		}
		else if (str == "toggle") {
			arr[num] = (arr[num] + 1) % 2;
		}
		else if (str == "all") {
			for (int i = 0; i < 20; i++)
				arr[i] = 1;
		}
		else if (str == "empty") {
			for (int i = 0; i < 20; i++)
				arr[i] = 0;
		}
	}

	return 0;
}