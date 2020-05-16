#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

//find()로 부모 검색.
//Merge 때, 이미 연결된 적 있는 노드는 parent끼리만 바꾸면 됨(parent에 연결된 자식노드 전부 바꿀필요x) 

vector<vector<int>> edges;
vector<int> parent;

bool Less(const vector<int> left, const vector<int>& right) {
	return left[2] < right[2];
}

int Find(int v) {
	if (parent[v] == v)
		return v;
	return parent[v] = Find(parent[v]);
}

bool Merge(int v1, int v2) {
	int p1 = Find(v1);
	int p2 = Find(v2);
	if (p1 == p2)
		return 0;
	parent[max(p1, p2)] = min(p1, p2);
	return 1;
}

int Kruscal() {
	int res = 0;
	for (int i = 0; i < (int)edges.size(); i++)	
		if (Merge(edges[i][0], edges[i][1]))
			res += edges[i][2];		//v_con, e_con 설정 없이 모든 edge 탐색하면 코드 짧아지긴함.
	return res;
}

int main() {
	int v, e;
	scanf("%d %d", &v, &e);
	edges = vector<vector<int>>(e, vector<int>(3));
	parent = vector<int>(v + 1);
	for (int i = 0; i < e; i++)
		scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
	for (int i = 1; i < (int)parent.size(); i++)
		parent[i] = i;
	sort(edges.begin(), edges.end(), Less);
	printf("%d", Kruscal());
	return 0;
}

/*
6 9
1 2 6
2 3 5
1 4 4
2 4 3
2 5 7
2 6 8
3 6 8
4 5 9
5 6 11
//정답 3+4+5+7+8 = 27
*/