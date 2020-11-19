// URL: https://atcoder.jp/contests/agc015/submissions/2453018
// Date: Fri, 04 May 2018 13:47:22 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int a[200000], b[200000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int len = s.length();
	long long ret = 0;
	for(int i = 0; i < len; i++)
	{
		if(s[i] == 'U')ret += i * 2 + len - i - 1;
		else ret += i + (len - i - 1) * 2;
	}
	cout << ret << endl;

	return 0;
}
