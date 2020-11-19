// URL: https://atcoder.jp/contests/abc001/submissions/3600606
// Date: Thu, 15 Nov 2018 00:25:57 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int m;
	cin >> m;
	if (m < 100)
		cout << "00" << endl;
	else if (m <= 5000)
		cout << setw(2) << setfill('0') << m * 10 / 1000 << endl;
	else if (m <= 30000)
		cout << m / 1000 + 50 << endl;
	else if (m <= 70000)
		cout << (m / 1000 - 30) / 5 + 80 << endl;
	else
		cout << "89" << endl;

	return 0;
}
