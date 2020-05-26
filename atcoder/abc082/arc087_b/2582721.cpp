// URL: https://atcoder.jp/contests/abc082/submissions/2582721
// Date: Tue, 29 May 2018 21:19:29 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int dp[4005][32000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	int x, y;
	cin >> s >> x >> y;
	int len = s.length();
	vector<int> dx, dy;
	bool direct = true;
	int cnt = 0;
	for(int i = 0; i <= len + 1; i++)
	{
		if(i >= len || s[i] == 'T')
		{
			if(direct)dx.push_back(cnt);
			else dy.push_back(cnt);
			cnt = 0;
			direct = (direct ? false : true);
		}
		else cnt++;
	}
	int x_size = dx.size(), y_size = dy.size();
	dp[0][16000 + dx[0]] = true;
	bool ok = false;
	for(int i = 1; i < x_size; i++)
		for(int j = 8000; j <= 24000; j++)
		{
			if(dp[i - 1][j - dx[i]] || dp[i - 1][j + dx[i]])dp[i][j] = true;
		}
	if(dp[x_size - 1][16000 + x])ok = true;
  	for(int i=0;i<y_size;i++)
      	for(int j=0;j<32000;j++)
        {
          dp[i][j]=false;
        }
	dp[0][16000 + dy[0]] = true;
	dp[0][16000 - dy[0]] = true;
	for(int i = 1; i < y_size; i++)
		for(int j = 8000; j <= 24000; j++)
		{
			if(dp[i - 1][j - dy[i]] || dp[i - 1][j + dy[i]])dp[i][j] = true;
		}
	if(ok&&dp[y_size - 1][16000 + y])cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
