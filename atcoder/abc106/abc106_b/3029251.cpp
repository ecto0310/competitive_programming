// URL: https://atcoder.jp/contests/abc106/submissions/3029251
// Date: Sat, 18 Aug 2018 21:04:00 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i += 2)
	{
		int tmp = 0;
		for (int j = 1; j <= n; j++)
			if (i % j == 0)
				tmp++;
		if (tmp == 8)
			ans++;
	}
	cout << ans << endl;

	return 0;
}
