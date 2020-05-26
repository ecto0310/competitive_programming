// URL: https://atcoder.jp/contests/abc105/submissions/2998063
// Date: Sun, 12 Aug 2018 18:17:16 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	bool ok = false;
	for (int i = 0; i * 4 <= n; i++)
		if ((n - i * 4) % 7 == 0)
			ok = true;
	if (ok)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
