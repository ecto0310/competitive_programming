// URL: https://atcoder.jp/contests/abc107/submissions/3074914
// Date: Sat, 25 Aug 2018 21:26:59 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	for (int i = 0; i < h; i++)
		cin >> a[i];
	for (int i = 0; i < a.size(); i++)
	{
		bool del = true;
		for (int j = 0; j < w; j++)
			if (a[i][j] == '#')
				del = false;
		if (del)
		{
			a.erase(a.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < a[0].length(); i++)
	{
		bool del = true;
		for (int j = 0; j < a.size(); j++)
			if (a[j][i] == '#')
				del = false;
		if (del)
		{
			for (int k = 0; k < a.size(); k++)
				a[k].erase(a[k].begin() + i);
			i--;
		}
	}
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << endl;

	return 0;
}
