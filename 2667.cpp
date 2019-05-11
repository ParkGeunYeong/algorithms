#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int board[25][25];
int check[25][25];
int moveTo[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int n;

int go(int r, int c) {
	if (check[r][c] == 1) return 0;
	check[r][c] = 1;
	//cout << r << ' ' << c << '\n';
	int ret = 1;
	for (int i = 0; i < 4; i++)
	{
		int goR = r + moveTo[i][0], goC = c + moveTo[i][1];
		if (goR < 0 || goC < 0 || goR >= n || goC >= n) continue;
		if (board[goR][goC] == 1) ret += go(goR, goC);
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++)
		{
			board[i][j] = temp[j] - '0';
			if (board[i][j] == 0) check[i][j] = -1;
		}
	}
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check[i][j] != -1 && check[i][j] == 0) {
				ans.push_back(go(i, j));
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i : ans) cout << i << '\n';

	return 0;
}