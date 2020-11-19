// URL: https://atcoder.jp/contests/cf16-final/submissions/3720755
// Date: Wed, 05 Dec 2018 15:32:07 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			string s;
			cin >> s;
			if (s == "snuke")
				cout << (char)('A' + j) << i + 1 << endl;
		}

	return 0;
}
