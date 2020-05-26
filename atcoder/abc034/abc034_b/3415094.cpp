// URL: https://atcoder.jp/contests/abc034/submissions/3415094
// Date: Tue, 16 Oct 2018 00:15:30 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n % 2 == 0)
		cout << n - 1 << endl;
	else
		cout << n + 1 << endl;

	return 0;
}
