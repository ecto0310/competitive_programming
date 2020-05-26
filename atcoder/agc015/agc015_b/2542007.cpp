// URL: https://atcoder.jp/contests/agc015/submissions/2542007
// Date: Mon, 21 May 2018 01:26:11 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int len = s.length();
	long long ans = 0;
	for(int i = 0; i < len; i++)
	{
		if(s[i] == 'U')ans += i * 2 + len - i - 1;
		else ans += i + (len - i - 1) * 2;
	}
	cout << ans << endl;

	return 0;
}
