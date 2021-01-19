#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

vector<char> input;
vector<int> picked;
int visited[10];
int k;
string Max = "0";
// 10자리의 9가 최대
string Min = "9999999999";

void dfs(int cnt) {
	if (cnt == k + 1) {
		for (int i = 0; i < k; i++) {
			if (input[i] == '<') {
				if (picked[i] >= picked[i + 1]) return;
			}
			else if (input[i] == '>') {
				if (picked[i] <= picked[i + 1]) return;
			}
		}

		string s = "";
		for (int i = 0; i < picked.size(); i++)
			s += to_string(picked[i]);

		// 10자리수는 int 에서 넘칠수 있음
		if (stoll(Max) < stoll(s)) Max = s;
		if (stoll(Min) > stoll(s)) Min = s;

		return;
	}

	for (int i = 0; i < 10; i++) {
		if (visited[i] == 1) continue;
		visited[i] = 1;
		picked.push_back(i);

		dfs(cnt + 1);

		visited[i] = 0;
		picked.pop_back();
	}
}



int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		char temp;
		cin >> temp;
		input.push_back(temp);
	}

	dfs(0);
	cout << Max << endl;
	cout << Min << endl;

	return 0;
}