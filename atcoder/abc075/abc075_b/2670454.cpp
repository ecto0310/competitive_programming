// URL: https://atcoder.jp/contests/abc075/submissions/2670454
// Date: Fri, 15 Jun 2018 20:45:09 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int dx[8] = {-1,-1,-1,0,0,1,1,1}, dy[8] = {-1,0,1,-1,1,-1,0,1};

int main()
{
	int h, w;
	string s[50];
	cin >> h >> w;
	for(int i = 0; i < h; i++)cin >> s[i];
	for(int x = 0; x < h; x++)
		for(int y = 0; y < w; y++)
		{
			if(s[x][y] != '#')
			{
				int tmp = 0;
				for(int i = 0; i < 8; i++)
				{
					if(-1 < x + dx[i] && x + dx[i] < h&&-1 < y + dy[i] && y + dy[i] < w && s[x + dx[i]][y + dy[i]] == '#')tmp++;
				}
				s[x][y] = '0' + tmp;
			}
		}
	for(int i = 0; i < h; i++)cout << s[i] << endl;

	return 0;
}
