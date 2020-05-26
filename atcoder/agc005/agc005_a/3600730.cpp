// URL: https://atcoder.jp/contests/agc005/submissions/3600730
// Date: Thu, 15 Nov 2018 00:54:11 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string x;
	cin >> x;
	for (int i = x.size() - 2; 0 <= i; i--)
		if (x.substr(i, 2) == "ST")
			x.erase(i, 2);
	cout << x.size() << endl;

	return 0;
}
