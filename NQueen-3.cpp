#include <iostream>
#include <vector>
using namespace std;

//점에 대해 마스킹하지 않고 행, 열, 대각선 2개에 대해서 마스킹.
//따라서 빠룸빠룸

vector<bool> rflag;
vector<bool> cflag;
vector<bool> rdflag;
vector<bool> ldflag;
int cnt = 0;
//i_ldflag = row + col,
//i_rdflag = n-1 + row - col?

void NQ(int row, int n) {
	if (row == n) {
		cnt++;
		return;
	}
	for(int i=0; i<n; i++)
		if (!rflag[i] && !cflag[i] && !rdflag[row + i] && !ldflag[n - 1 + row - i]) {
			rflag[i] = 1;
			cflag[i] = 1;
			rdflag[row + i] = 1;
			ldflag[n - 1 + row - i] = 1;
			NQ(row + 1, n);
			rflag[i] = 0;
			cflag[i] = 0;
			rdflag[row + i] = 0;
			ldflag[n - 1 + row - i] = 0;
		}
}

int main() {
	int N;
	cin >> N;
	rflag = vector<bool>(N);
	cflag = vector<bool>(N);
	rdflag = vector<bool>(2 * N - 1);
	ldflag = vector<bool>(2 * N - 1);

	NQ(0, N);
	cout << cnt;

	return 0;
}