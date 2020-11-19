// URL: https://atcoder.jp/contests/abc096/submissions/2461677
// Date: Sat, 05 May 2018 21:12:43 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;
	string s[50];
	for(int i = 0; i < h; i++)cin >> s[i];
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
		{
			if(s[i][j] == '#')
			{
				bool ok = false;
				if(i > 0 && s[i - 1][j] == '#')ok = true;
				if(i < h-1 && s[i + 1][j] == '#')ok = true;
				if(j > 0 && s[i ][j-1] == '#')ok = true;
				if(j < w-1 && s[i ][j+1] == '#')ok = true;
				if(!ok)
				{
					cout << "No" << endl;
					return 0;
				}
			}
		}
	cout << "Yes" << endl;

	return 0;
}
