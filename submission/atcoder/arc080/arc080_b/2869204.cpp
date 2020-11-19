// URL: https://atcoder.jp/contests/arc080/submissions/2869204
// Date: Thu, 19 Jul 2018 22:26:12 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int h, w, n, a[10000];
	cin >> h >> w >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int now = 0, cnt = 0;
	int c[100][100];
	for (int i = 0; i < h; i++)
		for (int j = (i % 2 == 0 ? 0 : w - 1); - 1 < j && j < w; (i % 2 == 0 ? j++ : j--))
		{
			c[i][j] = now;
			cnt++;
			if (cnt >= a[now])
			{
				now++;
				cnt = 0;
			}
		}
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			cout << c[i][j] + 1;
			if (j == w - 1)
				cout << endl;
			else
				cout << " ";
		}

	return 0;
}
