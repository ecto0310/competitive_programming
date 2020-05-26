// URL: https://atcoder.jp/contests/joi2011yo/submissions/3389151
// Date: Sat, 13 Oct 2018 00:33:01 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int t;
		cin >> t;
		sum += t;
	}
	cout << sum / 60 << endl
			 << sum % 60 << endl;

	return 0;
}
