#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,ans = 0;
	cin >> n;
	vector<int> mnum, pnum;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp <= 0) mnum.push_back(temp);
		else if (temp == 1) ans++;
		else pnum.push_back(temp);
	}
	sort(mnum.begin(), mnum.end());
	sort(pnum.begin(), pnum.end());
	reverse(pnum.begin(), pnum.end());
	if (mnum.size() > 0) {
		if (mnum.size() % 2 == 1) ans += mnum[mnum.size() - 1];
		for (int i = 0; i < mnum.size() / 2; i++)ans += mnum[i * 2] * mnum[i * 2 + 1];
	}
	if (pnum.size() > 0) {
		if (pnum.size() % 2 == 1) ans += pnum[pnum.size() - 1];
		for (int i = 0; i < pnum.size() / 2; i++)ans += pnum[i * 2] * pnum[i * 2 + 1];
	}

	cout << ans;
	return 0;
}