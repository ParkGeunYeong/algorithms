#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> apples = { 24,92,38,0,79,45 };

bool desc(int a, int b) {
	return a > b;
}

int solution(vector<int> apples) {
	int ret = 0;
	sort(apples.begin(), apples.end(), desc);
	for (int i = 0; i < apples.size(); i++)
	{
		ret = max(apples[i] * (i + 1), ret);
	}

	return ret;
}


int main() {
	cout << solution(apples);

	return 0;
}