#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int board[101][101];
int check[101][101];
int moveTo[4][2] = { {0,1},{0,-1} ,{1,0} ,{-1,0} };
queue<pair<int,int>> q;
int N, M;

int go(int r, int c) {
	check[r][c] = 1;
	q.push(make_pair(r,c));
	while (!q.empty()) {
		int goR = q.front().first, goC = q.front().second;
		for (int i = 0; i < 4; i++){
			int moveGoR = goR + moveTo[i][0], moveGoC = goC + moveTo[i][1];
			if (moveGoR > N || moveGoC > M || moveGoR < 1 || moveGoC < 1 ||
				check[moveGoR][moveGoC] == -1 || check[moveGoR][moveGoC] >= 1) continue;
			q.push({ moveGoR, moveGoC });
			check[moveGoR][moveGoC] = check[goR][goC] + 1;
		}
		q.pop();
	}
	return check[N][M];
}


int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 1; j <= M; j++)
		{
			board[i][j] = temp[j - 1] - '0';
			if (board[i][j] == 0) check[i][j] = -1;
		}
	}

	cout << go(1, 1) << '\n';
	
	return 0;
}