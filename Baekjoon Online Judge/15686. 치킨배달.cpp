#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct point {
	int r, c;
};

#define INF 987654321

int N, M;
point home[100];
point chicken[13];
int homeCnt = 0;
int chickenCnt = 0;
int answer = INF;

void print(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

void check(vector<int> picked) {
	int sum = 0;
	for (int i = 0; i < homeCnt; i++) {
		int min_dist = INF;
		for (int j = 0; j < picked.size(); j++) {
			int dist = abs(home[i].r - chicken[picked[j]].r) + abs(home[i].c - chicken[picked[j]].c);
			min_dist = min(dist, min_dist);
		}
		sum += min_dist;
	}
	answer = min(sum, answer);
}

void solve(int pos, int cnt, vector<int> picked) {
	if (pos >= chickenCnt || cnt == M) {
		if(picked.size() > 0)
			check(picked);
		return;
	}

	picked.push_back(pos);
	solve(pos + 1, cnt + 1, picked);
	picked.pop_back();

	solve(pos + 1, cnt, picked);

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			if (temp == 1) {
				home[homeCnt].r = i;
				home[homeCnt++].c = j;
			}
			else if (temp == 2) {
				chicken[chickenCnt].r = i;
				chicken[chickenCnt++].c = j;
			}
		}
	}
	vector<int> v;
	solve(0,0,v);
	cout << answer << endl;

	return 0;
}