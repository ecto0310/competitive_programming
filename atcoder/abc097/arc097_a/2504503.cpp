// URL: https://atcoder.jp/contests/abc097/submissions/2504503
// Date: Sat, 12 May 2018 22:46:07 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	int k;
	cin >> s >> k;
	vector<string> str;
	set<string> se;
	int len = s.length();
	for(int i = 0; i < len; i++)
		for(int j = 1; len > i + j - 1 && j<6; j++)
		{
			if(se.count(s.substr(i, j)) == 0)
			{
				str.push_back(s.substr(i, j));
				se.insert(s.substr(i, j));
			}
		}
	sort(str.begin(), str.end());;
	cout << str[k - 1] << endl;

	return 0;
}
