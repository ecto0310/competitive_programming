// URL: https://atcoder.jp/contests/abc062/submissions/3618350
// Date: Sat, 17 Nov 2018 22:02:40 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	for (int i = 0; i < h; i++)
		cin >> a[i];
	for (int i = 0; i < w + 2; i++)
		cout << "#" << (i == w + 1 ? "\n" : "");
	for (int i = 0; i < h;i++)
		cout << "#" << a[i] << "#" << endl;
	for (int i = 0; i < w + 2; i++)
		cout << "#" << (i == w + 1 ? "\n" : "");

	return 0;
}
