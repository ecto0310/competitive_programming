// URL: https://atcoder.jp/contests/abc033/submissions/2860458
// Date: Tue, 17 Jul 2018 21:36:36 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string n;
	cin >> n;
	if (n[0] == n[1] && n[1] == n[2] && n[2] == n[3])
		cout << "SAME" << endl;
	else
		cout << "DIFFERENT" << endl;

	return 0;
}
