// URL: https://atcoder.jp/contests/abc046/submissions/2818934
// Date: Mon, 09 Jul 2018 22:43:36 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int ans = 0;
	bool buy[101] = {};
	for (int i = 0; i < 3; i++)
	{
		int tmp;
		cin >> tmp;
		if (!buy[tmp])
			ans++;
		buy[tmp] = true;
	}
	cout << ans << endl;

	return 0;
}
