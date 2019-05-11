#include<iostream>
#include<queue>
using namespace std;
queue<pair<int, int>> q;
int board[1001][1001];
int check[1001][1001];
int moveTo[4][2] = { {0,1},{0,-1} ,{1,0} ,{-1,0} };
int R, C;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> C >> R;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == -1) check[i][j] = -1;
			if (board[i][j] == 1) {
				q.push(make_pair(i, j));
				check[i][j] = 1;
			}
		}
	}
	while (!q.empty()) {
		int cur_hongSi_r = q.front().first;
		int cur_hongSi_c = q.front().second;
		q.pop();
		for (int j = 0; j < 4; j++)
		{
			int move_r = cur_hongSi_r + moveTo[j][0];
			int move_c = cur_hongSi_c + moveTo[j][1];
			if (move_r < 1 || move_c < 1 || move_r > R || move_c > C ||
				check[move_r][move_c] == -1 || check[move_r][move_c] >= 1) continue;
			q.push(make_pair(move_r, move_c));
			check[move_r][move_c] = check[cur_hongSi_r][cur_hongSi_c] + 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (check[i][j] == 0) {
				cout << -1 << '\n';
				return 0;
			}
			if (check[i][j] > ans) ans = check[i][j];
		}
	}
	cout << ans - 1 << '\n';

	return 0;
}