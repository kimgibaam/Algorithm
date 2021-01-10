#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

#define red 1
#define blue 2

vector<int> g[20001];
int visited[20001];
int v, e;

void dfs(int curr) {
	if (visited[curr] == 0)
		visited[curr] = red;
	
	for (int i = 0; i < g[curr].size(); i++) {
		int next = g[curr][i];
		if (visited[next] == 0) {
			if (visited[curr] == red) {
				visited[next] = blue;
				dfs(next);
			}
			else {
				visited[next] = red;
				dfs(next);
			}
		}
	}
}

bool checking() {
	// 반복문 index 주의
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			int next = g[i][j];
			if (visited[i] == visited[next])
				return false;
		}
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> v >> e;
		for (int j = 0; j < e; j++) {
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

        //하나도 연결안된 노드 처리
		for(int k = 1; k <=v ;k++)
			if(visited[k] == 0)
				dfs(k);

		if (checking())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		memset(visited, 0, sizeof(visited));
		for (int k = 1; k <= v; k++)
			g[k].clear();
	}

	return 0;
}