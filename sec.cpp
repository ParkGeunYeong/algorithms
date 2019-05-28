#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
vector<string> list = { "111","01","11","10","101" };


bool cmp1(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

bool cmp0(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int solution(vector<string> list, int nZ, int nO) {
	vector<pair<int, int>> pre;
	vector<pair<int, int>> pre_temp;
	for (string i : list) {
		int temp0 = 0, temp1 = 0;
		for (char j : i) {
			if (j == '0') temp0++;
			else temp1++;
		}
		pre.push_back(make_pair(temp0, temp1));
	}

	sort(pre.begin(), pre.end(), cmp0);
	int zero = nZ;
	for (int i = 0; i < pre.size(); i++)
	{
		if (zero == 0) break;
		if (pre[i].first == 0) {
			pre_temp.push_back(make_pair(pre[i].first, pre[i].second));
		}
		else {
			if (zero - pre[i].first < 0)break;
			zero -= pre[i].first;
			pre_temp.push_back(make_pair(pre[i].first, pre[i].second));
		}
	}

	sort(pre_temp.begin(), pre_temp.end(), cmp1);
	int one = nO;
	int ret1 = 0;
	for (int i = 0; i < pre_temp.size(); i++)
	{
		if (one == 0) break;
		if (pre_temp[i].second == 0) {
			ret1++;
		}
		else {
			if (one - pre_temp[i].second < 0)break;
			one -= pre_temp[i].second;
			ret1++;
		}
	}


	pre_temp.clear();

	sort(pre.begin(), pre.end(), cmp1);
	one = nO;
	for (int i = 0; i < pre.size(); i++)
	{
		if (one == 0) break;
		if (pre[i].second == 0) {
			pre_temp.push_back(make_pair(pre[i].first, pre[i].second));
		}
		else {
			if (one - pre[i].second < 0)break;
			one -= pre[i].second;
			pre_temp.push_back(make_pair(pre[i].first, pre[i].second));
		}
	}

	sort(pre_temp.begin(), pre_temp.end(), cmp0);
	zero = nZ;
	int ret2 = 0;
	for (int i = 0; i < pre_temp.size(); i++)
	{
		if (zero == 0) break;
		if (pre_temp[i].first == 0) {
			ret2++;
		}
		else {
			if (zero - pre_temp[i].first < 0)break;
			zero -= pre_temp[i].first;
			ret2++;
		}
	}
	cout << ret1 << ' ' << ret2;
	int ret = max(ret1, ret2);
	return ret;
}

int main() {
	cout << solution(list, 3, 9);

	return 0;
}