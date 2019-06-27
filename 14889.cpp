#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int ability[20][20];

int calc_ability(vector<int>& team) {
	vector<int> team_a, team_b;
	for (int i = 0; i < team.size(); i++)
	{
		if (team[i] == 0) team_a.push_back(i);
		else team_b.push_back(i);
	}
	int team_a_ability = 0;
	for (int i : team_a) for (int j : team_a) team_a_ability += ability[i][j];
	int team_b_ability = 0;
	for (int i : team_b) for (int j : team_b) team_b_ability += ability[i][j];
	return abs(team_a_ability - team_b_ability);
}

int main() {
	int n;
	cin >> n;
	vector<int> team;
	for (int i = 0; i < n; i++)
	{
		team.push_back(i / (n / 2));
		for (int j = 0; j < n; j++)
		{
			cin >> ability[i][j];
		}
	}
	int min = 987654321;
	do {
		int calc_abiltiy_ab = calc_ability(team);
		if (min > calc_abiltiy_ab) min = calc_abiltiy_ab;
	} while (next_permutation(team.begin(), team.end()));

	cout << min;

	return 0;
}