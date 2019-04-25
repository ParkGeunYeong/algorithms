#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	int n;
	string input;
	cin >> n;
	vector<pair<string,int>> b(n);
	map<char, char> match;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i].first;
		b[i].second = size(b[i].first);
		for (char j : b[i].first) {
			if (match.find(j) == match.end())
				match[j] = 0;
		}
	}


	return 0;
}