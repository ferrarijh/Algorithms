#include <vector>
#include <set>
#include <queue>
#include <iostream>
using namespace std;

/*==========input==========
1st line : number of nodes(v), number of edges(e), starting node(start)
from 2nd line : edge between node1(v1) and node2(v2)
*/

vector<set<int>> edges;
vector<bool> visited;

void dfs(int v) {
	visited[v] = 1;
	cout << v << " ";
	for (int i : edges[v])
		if (!visited[i])
			dfs(i);
}

void bfs(int start) {
	queue<int> q;
	int now = start;
	q.push(now);
	visited[now] = 1;
	cout << now << " ";
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int i : edges[now])
			if (!visited[i]) {
				visited[i] = 1;
				q.push(i);
				cout << i << " ";
			}
	}
}

int main() {
	int v, e, start, v1, v2;
	cin >> v >> e >> start;
	edges = vector<set<int>>(v + 1);
	for (int i = 0; i < e; i++) {
		cin >> v1 >> v2;
		edges[v1].insert(v2);
		edges[v2].insert(v1);
	}
	visited = vector<bool>(v + 1);
	dfs(start);
	cout << "\n";
	visited = vector<bool>(v + 1);
	bfs(start);

	return 0;
}

/*====test input====
4 5 1
1 2
1 3
1 4
2 4
3 4
//answer
//1 2 4 3
//1 2 3 4

5 5 3
5 4
5 2
1 2
3 4
3 1
//answer
//3 1 2 5 4
//3 1 4 2 5

1000 1 1000
999 1000
//answer
//1000 999
//1000 999

*/