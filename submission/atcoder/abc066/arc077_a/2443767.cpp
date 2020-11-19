// URL: https://atcoder.jp/contests/abc066/submissions/2443767
// Date: Tue, 01 May 2018 22:13:17 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	deque<int> d;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if((n % 2 == 0 && i % 2 == 0) || (n % 2 == 1 && i % 2 == 1))d.push_back(a);
		else d.push_front(a);
	}
	for(int i = 0; i < n; i++)cout << d[i] << (i != n - 1 ? " " : "");
	cout << endl;

	return 0;
}
