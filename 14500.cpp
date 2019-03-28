#include <iostream>
#include <vector>
using namespace std;
int  tetromino[19][3][2] = {
	{{0,1}, {0,2}, {0,3}},
	{{1,0}, {2,0}, {3,0}},
	{{1,0}, {1,1}, {1,2}},
	{{0,1}, {1,0}, {2,0}},
	{{0,1}, {0,2}, {1,2}},
	{{1,0}, {2,0}, {2,-1}},
	{{0,1}, {0,2}, {-1,2}},
	{{1,0}, {2,0}, {2,1}},
	{{0,1}, {0,2}, {1,0}},
	{{0,1}, {1,1}, {2,1}},
	{{0,1}, {1,0}, {1,1}},
	{{0,1}, {-1,1}, {-1,2}},
	{{1,0}, {1,1}, {2,1}},
	{{0,1}, {1,1}, {1,2}},
	{{1,0}, {1,-1}, {2,-1}},
	{{0,1}, {0,2}, {-1,1}},
	{{0,1}, {0,2}, {1,1}},
	{{1,0}, {2,0}, {1,1}},
	{{1,0}, {2,0}, {1,-1}},
};

int main() {
	int n, m, map_input;
	cin >> n >> m;
	vector<vector<int>> map(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map_input;
			map[i].push_back(map_input);
		}
	}
	int sum = 0, max = 0;;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			
			for (int k = 0; k < 19; k++)
			{
				sum = map[i][j];
				for (int l = 0; l < 3; l++)
				{
					int x = i + tetromino[k][l][0];
					int y = j + tetromino[k][l][1];
					if (x >= 0 && x < n && y >= 0 && y < m) {
						sum += map[x][y];
						
					}
					else {
						sum = 0;
						break;
					}
				}
				if (max < sum) max = sum;
			}
		}
	}

	cout << max << '\n';



	return 0;
}