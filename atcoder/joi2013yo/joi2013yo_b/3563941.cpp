// URL: https://atcoder.jp/contests/joi2013yo/submissions/3563941
// Date: Thu, 08 Nov 2018 19:36:22 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int[4]> v(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> v[i][j];
	for (int i = 0; i < 3; i++)
	{
		int p[101] = {};
		for (int j = 0; j < n; j++)
			p[v[j][i]]++;
		for (int j = 0; j < n; j++)
			if (p[v[j][i]] == 1)
				v[j][3] += v[j][i];
	}
	for (int i = 0; i < n; i++)
		cout << v[i][3] << endl;

	return 0;
}
