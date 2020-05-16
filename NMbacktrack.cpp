#include <vector>
#include <iostream>
using namespace std;

/* Permutate M numbers between 1~N (1 <= M <= N) in ascending order.
==========INPUT==========
1st line : N, M.

==========OUTPUT==========
from 1st line : all permutation results.
*/

vector<int> nums;
vector<bool> visited;
void NM(int pos, int n, int m) {
	if (pos == m) {
		for (int i : nums)
			cout << i << " ";
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
		if (!visited[i]) {
			visited[i] = 1;
			nums[pos] = i;
			NM(pos + 1, n, m);
			visited[i] = 0;
		}
}

int main() {
	int n, m;
	cin >> n >> m;
	nums = vector<int>(m);
	visited = vector<bool>(n + 1);
	NM(0, n, m);

	return 0;
}

/*====test input====
4 2
=== answer below
1 2
1 3
1 4
2 1
2 3
2 4
3 1
3 2
3 4
4 1
4 2
4 3
===

*/