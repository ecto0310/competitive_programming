// URL: https://atcoder.jp/contests/rco-contest-2018-final-open/submissions/2509833
// Date: Sun, 13 May 2018 21:35:31 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++)cout << (char)('a' + rand() % 26);
	cout << endl;
	cout << 1 + rand() % 9 + (double)(rand() % 9) / 10 << endl;
	string qs;
	for(int i = 0; i < q; i++)cin >> qs;
	for(int i = 0; i < q; i++)cout << rand() % n << endl;

	return 0;
}
