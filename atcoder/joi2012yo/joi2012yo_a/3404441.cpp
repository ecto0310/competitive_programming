// URL: https://atcoder.jp/contests/joi2012yo/submissions/3404441
// Date: Sun, 14 Oct 2018 18:24:30 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int p[3], d[2];
	for (int i = 0; i < 3; i++)
		cin >> p[i];
	for (int i = 0; i < 2; i++)
		cin >> d[i];
	cout << min({p[0], p[1], p[2]}) + min(d[0], d[1]) - 50 << endl;

	return 0;
}
