#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, end=0, ans = 0;
	cin >> n;
	vector<pair<int,int>> meeting(n);
	for (int i = 0; i < n; i++)
	{
		cin >> meeting[i].first >> meeting[i].second;
	}
	sort(meeting.begin(), meeting.end(), cmp);
	for (auto i : meeting) {
		if (end <= i.first) {
			end = i.second;
			ans++;
		}
	}
	cout << ans;
	return 0;
}