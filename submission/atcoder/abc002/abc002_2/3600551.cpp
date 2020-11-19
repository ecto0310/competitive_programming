// URL: https://atcoder.jp/contests/abc002/submissions/3600551
// Date: Thu, 15 Nov 2018 00:14:35 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string w;
	cin >> w;
	for (int i = 0; i < w.size(); i++)
		if (w[i] != 'a' && w[i] != 'i' && w[i] != 'u' && w[i] != 'e' && w[i] != 'o')
			cout << w[i];
	cout << endl;

	return 0;
}
