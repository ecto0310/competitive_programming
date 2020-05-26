// URL: https://atcoder.jp/contests/joi2018yo/submissions/2691223
// Date: Sun, 17 Jun 2018 02:01:03 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	int a[25][25];
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
		{
			cin >> a[i][j];
		}
	int ans = 100000000;
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
		{
			int tmp = 0;
			for(int x = 0; x < h; x++)
				for(int y = 0; y < w; y++)
				{
					tmp += min(abs(i - x), abs(j - y))*a[x][y];
				}
			ans = min(ans, tmp);
		}
	cout << ans << endl;

	return 0;
}
