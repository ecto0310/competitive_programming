// URL: https://atcoder.jp/contests/agc023/submissions/2542063
// Date: Mon, 21 May 2018 01:45:33 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n;
	string s[300];
	cin >> n;
	for(int i = 0; i < n; i++)cin >> s[i];
	int ans = 0;
	for(int mx = 0; mx < n; mx++)
	{
		bool ok = true;
		for(int x = 0; x < n; x++)
		{
			for(int y = 0; y < n; y++)
			{
				if(s[(x + mx) % n][y] != s[(y + mx) % n][x])ok = false;
			}
		}
		if(ok)ans++;
	}
	cout << ans * n << endl;

	return 0;
}
