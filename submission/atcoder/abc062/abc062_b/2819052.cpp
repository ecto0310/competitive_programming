// URL: https://atcoder.jp/contests/abc062/submissions/2819052
// Date: Mon, 09 Jul 2018 23:09:41 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < w + 2; i++)
		cout << "#";
	cout << endl;
	for (int i = 0; i < h; i++)
	{
		string a;
		cin >> a;
		cout << "#" << a << "#" << endl;
	}
	for (int i = 0; i < w + 2; i++)
		cout << "#";
	cout << endl;

	return 0;
}
