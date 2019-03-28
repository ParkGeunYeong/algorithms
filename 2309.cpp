#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,bool>> dwarf;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int allSum = -100;
	int input;
	for (int i = 0; i < 9; i++)
	{
		cin >> input;
		dwarf.push_back(make_pair(input, true));
		allSum += input;
	}
	sort(dwarf.begin(), dwarf.end());
	for (int i = 0; i < 8; i++)
	{
		for (int j = i+1; j < 9; j++)
		{
			if (dwarf[i].first + dwarf[j].first == allSum) {
				dwarf[i].second = dwarf[j].second = false;
				i = j = 7878;
			}
		}
	}
	for (auto a : dwarf) {
		if (!a.second) continue;
		cout << a.first << '\n';
	}



	return 0;
}