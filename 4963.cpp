#include<iostream>
#include<cstring>
using namespace std;
int board[50][50];
int check[50][50];
int moveTo[8][2] = { {0,1},{0,-1},{1,0},{-1,0}, {1,1},{1,-1}, {-1,1}, {-1,-1} };
int C, R;

void go(int r, int c) {
	if (check[r][c] == 1) return ;
	check[r][c] = 1;
	for (int i = 0; i < 8; i++)
	{
		int goR = r + moveTo[i][0], goC = c + moveTo[i][1];
		if (goR < 0 || goC < 0 || goR >= R || goC >= C) continue;
		if (board[goR][goC] == 1) go(goR, goC);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (cin >> C >> R) {
		if (C == 0 && R == 0) return 0;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == 0) check[i][j] = -1;
			}
		}
		int ans = 0;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (check[i][j] != -1 && check[i][j] == 0) {
					go(i, j); ans++;
				}
			}
		}
		cout << ans << '\n';
		memset(board, 0, sizeof(board));
		memset(check, 0, sizeof(check));
	}

	

	return 0;
}