#include <vector>
#include <set>
#include <queue>
#include <cstdio>
using namespace std;

vector<set<int>> edges;
vector<bool> visited;

void dfs(int v) {
	visited[v] = 1;
	printf("%d", v);
	for (int i : edges[v])
		if (!visited[i])
			dfs(i);
}

void bfs(int start) {
	queue<int> q;
	int now = start;
	q.push(now);
	visited[now] = 1;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int i : edges[now])
			if (!visited[i]) {
				visited[i] = 1;
				q.push(i);
				printf("%d ", i);
			}
	}
}

int main() {
	int v, e, start, v1, v2;
	scanf("%d %d %d", &v, &e, &start);
	edges = vector<set<int>>(v + 1);
	for (int i = 0; i < e; i++) {
		scanf("%d %d", &v1, &v2);
		edges[v1].insert(v2);
		edges[v2].insert(v1);
	}
	visited = vector<bool>(v + 1);
	dfs(start);
	printf("\n");
	visited = vector<bool>(v + 1);
	bfs(start);

	return 0;
}