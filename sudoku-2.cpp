#include <cstdio>
#include <vector>
#include <list>
#pragma warning(disable:4996)
using namespace std;

//행, 열, box에 대해 flag 부여.
//행, 열, box 이차행렬은 열 크기가 9 아닌 10 이어야!

void Sudoku(int pos, vector<vector<int>>& game, int cnt);

vector<vector<int>> row_flag(9);
vector<vector<int>> col_flag(9);
vector<vector<int>> box_flag(9);
vector<pair<int, int>> zeros(81);

int main() {
	vector<vector<int>> game(9);
	int temp, cnt = 0;
	for (int i = 0; i < 9; i++) {
		game[i] = vector<int>(9);
		row_flag[i] = vector<int>(10);
		col_flag[i] = vector<int>(10);
		box_flag[i] = vector<int>(10);
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &temp);
			game[i][j] = temp;
			if (temp) {
				row_flag[i][temp] = 1;
				col_flag[j][temp] = 1;
				box_flag[i / 3 * 3 + j / 3][temp] = 1;
			}
			else
				zeros[cnt++] = pair<int, int>(i, j);
		}
	}
	Sudoku(0, game, cnt);

	return 0;
}

void Sudoku(int pos, vector<vector<int>>& game, int cnt) {
	if (pos == cnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				printf("%d ", game[i][j]);
			printf("\n");
		}
		exit(0);
	}
	int x = zeros[pos].first, y = zeros[pos].second;
	for (int i = 1; i <= 9; i++) {
		if (box_flag[x / 3 * 3 + y / 3][i])
			continue;
		if (row_flag[x][i] || col_flag[y][i])
			continue;
		game[x][y] = i;
		box_flag[x / 3 * 3 + y / 3][i] = 1;
		row_flag[x][i] = 1;
		col_flag[y][i] = 1;
		Sudoku(pos + 1, game, cnt);
		game[x][y] = 0;
		box_flag[x / 3 * 3 + y / 3][i] = 0;
		row_flag[x][i] = 0;
		col_flag[y][i] = 0;
	}
}