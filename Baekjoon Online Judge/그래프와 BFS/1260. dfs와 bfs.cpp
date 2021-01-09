#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define max 1001

int n, m, v;
int g[max][max];
bool visited[max];
vector<int> picked;

void dfs(int node) {
	if (picked.size() > n) return;
	visited[node] = true;
	picked.push_back(node);

	for (int i = 1; i < max; i++) {
		if (g[node][i] == 1 && visited[i] == false) {
			dfs(i);
		}
	}
}

void bfs() {
	queue<int> q;
	q.push(v);
	visited[v] = true;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << " ";

		for (int i = 1; i < max; i++) {
			if (g[node][i] == 1 && visited[i] == false) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	cin >> n >> m >> v;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		g[a][b] = 1;
		g[b][a] = 1;
	}

	dfs(v);
	for (int i = 0; i < picked.size(); i++)
		cout << picked[i] << " ";
	cout << endl;

	memset(visited, false, sizeof(visited));
	bfs();

	return 0;
}