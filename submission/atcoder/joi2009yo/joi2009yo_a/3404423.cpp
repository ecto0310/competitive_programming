// URL: https://atcoder.jp/contests/joi2009yo/submissions/3404423
// Date: Sun, 14 Oct 2018 18:20:09 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a[2][3] = {}, b[2][3] = {}, c[2][3] = {};
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			cin >> a[i][j];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			cin >> b[i][j];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			cin >> c[i][j];
	int as = a[1][0] * 3600 + a[1][1] * 60 + a[1][2] - (a[0][0] * 3600 + a[0][1] * 60 + a[0][2]);
	int bs = b[1][0] * 3600 + b[1][1] * 60 + b[1][2] - (b[0][0] * 3600 + b[0][1] * 60 + b[0][2]);
	int cs = c[1][0] * 3600 + c[1][1] * 60 + c[1][2] - (c[0][0] * 3600 + c[0][1] * 60 + c[0][2]);
	cout << as / 3600 << " " << as / 60 % 60 << " " << as % 60 << endl;
	cout << bs / 3600 << " " << bs / 60 % 60 << " " << bs % 60 << endl;
	cout << cs / 3600 << " " << cs / 60 % 60 << " " << cs % 60 << endl;

	return 0;
}
