#include <vector>
#include <cstdio>
#define NIL -1
#define MAX 1000000000
using namespace std;
/* 
implement Floyd Warshall algorithm.
=========INPUTS==========
1st line : number of nodes(v), number of edges(e)
from 2nd line : edge from node1(v1) to node2(v2) with weight(w).

==========OUTPUTS==========
all minimum weight path between node i to node j
*/
typedef pair<int, int> pr;

vector<vector<pr>> fw;

int main() {
	int v, e, v1, v2, w;
	scanf("%d %d", &v, &e);
	fw = vector<vector<pr>>(v + 1, vector<pr>(v + 1, pr(NIL, MAX)));
	for (int i = 1; i <= v; i++)
		fw[i][i] = pr(i, 0);
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &v1, &v2, &w);
		if (fw[v1][v2].second > w)
			fw[v1][v2] = pr(v1, w);
	}

	for (int k = 1; k <= v; k++)
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++)
				if (fw[i][j].second > fw[i][k].second + fw[k][j].second) {
					fw[i][j].second = fw[i][k].second + fw[k][j].second;
					fw[i][j].first = k;
				}

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (fw[i][j].second == MAX)
				printf("MAX\t");
			else
				printf("%d\t", fw[i][j].second);
		}
		printf("\n");
	}

	return 0;
}

/*=====test input
5
14
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
3 5 10
3 1 8
1 4 2
5 1 7
3 4 2
5 2 4
=====answer below
0 2 3 1 4
12 0 15 2 5
8 5 0 1 1
10 7 13 0 3
7 4 10 6 0
*/