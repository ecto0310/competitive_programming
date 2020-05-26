// URL: https://atcoder.jp/contests/abc012/submissions/3600301
// Date: Wed, 14 Nov 2018 23:19:33 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << setfill('0') << setw(2) << n / 3600 << ":" << setfill('0') << setw(2) << n / 60 % 60 << ":" << setfill('0') << setw(2) << n % 60 << endl;

	return 0;
}
