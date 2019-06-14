#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	if (m + k - 1 <= n && n <= m * k) {
		vector<int> s;
		for (int i = k; i > 0; i--)
		{
			s.push_back(i);
		}
		vector<int> num(m - 1,0);
		for (int i = 0; i < n - k; i++)
		{
			num[i % num.size()]++;
		}
		vector<int> temp;
		int index = 0;
		for (int i = k+1; i <= n; i++)
		{
			num[index]--;
			temp.push_back(i);
			if (num[index] == 0) {
				reverse(temp.begin(), temp.end());
				for(int t : temp) s.push_back(t);
				temp.clear();
				index++;
			}
		}
		for (int i : s) cout << i << ' ';
	}
	else {
		cout << -1;
	}

	return 0;
}