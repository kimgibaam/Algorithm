#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[1000];
int dp[1000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	
	for (int i = 1; i < n; i++) {
		int Max = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[j] < Max)
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(dp[i], ans);

	vector<int> answer;
	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] == ans) {
			ans--;
			answer.push_back(arr[i]);
		}
	}
	reverse(answer.begin(), answer.end());

	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
		
	return 0;
}