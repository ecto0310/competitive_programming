// URL: https://atcoder.jp/contests/joi2008yo/submissions/3687090
// Date: Fri, 30 Nov 2018 01:18:30 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<bool> t(2 * n + 1, false);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		t[a] = true;
	}
	vector<int> taro, hana;
	int now = 0;
	for (int i = 1; i <= n * 2; i++)
		if (t[i])
			taro.push_back(i);
		else
			hana.push_back(i);
	for (int i = 0;; i++)
		if (taro.size() == 0 || hana.size() == 0)
			break;
		else if (i % 2 == 0)
		{
			int it = upper_bound(taro.begin(), taro.end(), now) - taro.begin();
			if (taro.size() == it)
			{
				now = 0;
				continue;
			}
			cerr << "t " << taro[it] << endl;
			now = taro[it];
			taro.erase(taro.begin() + it);
		}
		else
		{
			int it = upper_bound(hana.begin(), hana.end(), now) - hana.begin();
			if (hana.size() == it)
			{
				now = 0;
				continue;
			}
			cerr << "h " << hana[it] << endl;
			now = hana[it];
			hana.erase(hana.begin() + it);
		}
	cout << hana.size() << endl
			 << taro.size() << endl;

	return 0;
}
