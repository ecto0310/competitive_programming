// URL: https://atcoder.jp/contests/abc047/submissions/2855623
// Date: Mon, 16 Jul 2018 17:27:56 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int w, h, n;
	cin >> w >> h >> n;
	int x0 = 0, x1 = w, y0 = 0, y1 = h;
	for (int i = 0; i < n; i++)
	{
		int x, y, a;
		cin >> x >> y >> a;
		if (a == 1)
			x0 = max(x0, x);
		else if (a == 2)
			x1 = min(x1, x);
		else if (a == 3)
			y0 = max(y0, y);
		else
			y1 = min(y1, y);
	}
	cout << max(0, x1 - x0) * max(0, y1 - y0) << endl;

	return 0;
}
