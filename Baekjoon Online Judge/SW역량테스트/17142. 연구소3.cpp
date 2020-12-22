#include<iostream>
#include<algorithm>
#include<queue>
#include<bits/stdc++.h>

using namespace std;

struct point {
	int r, c, d;
};

int n, m;
int arr[50][50];

point virus[10];
int visited[10];

int viruscnt = 0;
int answer = 987654321;

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void solve(vector<int> picked);
void print(int temp[50][50]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void dfs(int cnt, int idx, vector<int> picked) {
	if (cnt == m) {   // 모든 조합들에 대해
		//print(picked);
		solve(picked);
		return;
	}

	for (int i = idx; i < viruscnt; i++) {
		if (visited[i] == 1) continue;
		picked.push_back(i);
		visited[i] = 1;
		dfs(cnt + 1, i, picked);
		picked.pop_back();
		visited[i] = 0;
	}
}

void solve(vector<int> picked) {
	int temp[50][50];
	memcpy(temp, arr, sizeof(arr));

	queue<point> q;
	for (int i = 0; i < picked.size(); i++) 
		q.push({ virus[picked[i]].r, virus[picked[i]].c });

	int dist = 0;
	while (!q.empty()) {
		point curr = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = curr.r + dr[i], nc = curr.c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
			if (temp[nr][nc] != 0 && temp[nr][nc] != 2) continue;
			if(temp[nr][nc] != 2)
				dist = max(dist, curr.d + 1);
			temp[nr][nc] = 3;
			q.push({ nr,nc,curr.d + 1});
			
		}
		//print(temp);
		//cout << dist << " " << curr.r << " " << curr.c << endl;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (temp[i][j] == 0)
				return;
		}
	}

	answer = min(answer, dist);

}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				virus[viruscnt++] = { i,j };
		}
	}
	vector<int> v;
	dfs(0,0,v);

	if (answer == 987654321) answer = -1;
	cout << answer << endl;
	return 0;
}