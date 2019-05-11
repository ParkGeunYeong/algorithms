#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int N;
int map[100][100];
int checked_map[100][100];
int check_min_bridge[100][100];
int moveTo[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int n_island = 0;
vector<pair<pair<int, int>,pair<int,int>>> todo;

void check_map(int r, int c) {
	if (checked_map[r][c] >= 1) return;
	checked_map[r][c] = n_island;
	for (int i = 0; i < 4; i++)
	{
		int move_r = r + moveTo[i][0], move_c = c + moveTo[i][1];
		if (move_r < 0 || move_c < 0 || move_r >= N || move_c >= N) continue;
		if (map[move_r][move_c] == 1) check_map(move_r, move_c);
	}
}

int min_bridge_in_here(int i, int j, int from_i, int from_j) {
	memset(check_min_bridge, 0, sizeof(check_min_bridge));
	queue<pair<int, int>> q;
	int n_pre_island = checked_map[from_i][from_j];
	int min_bridge = 0;
	check_min_bridge[i][j] = 1;
	q.push(make_pair(i, j));
	while (!q.empty()) {
		int r = q.front().first, c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int move_r = r + moveTo[i][0], move_c = c + moveTo[i][1];
			if (move_r < 0 || move_c < 0 || move_r >= N || move_c >= N || check_min_bridge[move_r][move_c] >= 1) continue;
			if (checked_map[move_r][move_c] >= 1 && checked_map[move_r][move_c] != n_pre_island) {
				return check_min_bridge[r][c];
			}
		}
		for (int i = 0; i < 4; i++)
		{
			int move_r = r + moveTo[i][0], move_c = c + moveTo[i][1];
			if (move_r < 0 || move_c < 0 || move_r >= N || move_c >= N || check_min_bridge[move_r][move_c] >= 1) continue;
			if (map[move_r][move_c] == 0) {
				check_min_bridge[move_r][move_c] = check_min_bridge[r][c] + 1;
				q.push(make_pair(move_r, move_c));
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0) checked_map[i][j] = -1;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (checked_map[i][j] == 0) {
				n_island++;
				check_map(i, j);
			}
			if (map[i][j] == 1) {
				for (int i = 0; i < 4; i++)
				{
					int move_r = i + moveTo[i][0], move_c = j + moveTo[i][1];
					if (move_r < 0 || move_c < 0 || move_r >= N || move_c >= N) continue;
					if (map[move_r][move_c] == 0) todo.push_back(make_pair(make_pair(move_r, move_c), make_pair(i, j)));
				}
			}
		}
	}

	int min_bridge = 987654321;
	for (auto i : todo) {
		int mb = min_bridge_in_here(i.first.first, i.first.second, i.second.first, i.second.second);
		if (min_bridge > mb) min_bridge = mb;
	}

	cout << min_bridge << '\n';

	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << check_min_bridge[i][j] << ' ';
		}
		cout << '\n';
	}
}