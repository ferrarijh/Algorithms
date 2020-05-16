#include <vector>
#include <iostream>
#include <queue>
using namespace std;

/* Dajikstra - length of shortest path for each nodes.
1¡ÂV¡Â20,000, 1¡ÂE¡Â300,000 and each weight(w) of each edge is w¡Â10.
==========INPUT==========
1st line : number of nodes(v), number of edges(e), starting node(start).
from 2nd line : edge between node1(v1) and node2(v2) with weight(w).
==========OUTPUT==========
length(weight sum) of shortest path to each nodes, line by line.
*/

#define INF 3000000
typedef pair<int, int> pr;

vector<vector<pr>> edges;
vector<bool> visited;
vector<int> dist;

class Greater {
public:
	bool operator()(const pr& left, const pr& right) {
		return left.second > right.second;
	}
};

void daj(int start) {
	priority_queue<pr, vector<pr>, Greater> pq;
	int now = start;
	dist[now] = 0;
	pq.push(pr(now, 0));
	while (!pq.empty()) {
		now = pq.top().first;
		visited[now] = 1;
		pq.pop();
		for(pr ipr : edges[now])
			if (!visited[ipr.first])
				if (dist[ipr.first] > dist[now] + ipr.second) {
					dist[ipr.first] = dist[now] + ipr.second;
					pq.push(pr(ipr.first, dist[ipr.first]));
				}
	}
}

int main() {
	int v, e, start, v1, v2, w;
	cin >> v >> e >> start;
	edges = vector<vector<pr>>(v + 1);
	visited = vector<bool>(v + 1);
	dist = vector<int>(v + 1, INF);
	for (int i = 0; i < e; i++) {
		cin >> v1 >> v2 >> w;
		edges[v1].push_back(pr(v2, w));
	}
	daj(start);
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF)
			cout << "INF" << "\n";
		else
			cout << dist[i] << "\n";
	}
	return 0;
}

/*====test input====
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
=== answer below
0
2
3
7
INF
===

*/