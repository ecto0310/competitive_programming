// URL: https://atcoder.jp/contests/abc091/submissions/2376789
// Date: Thu, 19 Apr 2018 00:00:17 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

bool red_sort(const pair<int, int>&f, const pair<int, int>&s)
{
	return f.second > s.second;
}

bool blue_sort(const pair<int, int>&f, const pair<int, int>&s)
{
	return f.first < s.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> red, blue;
	for(int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		red.push_back(pair<int, int>(a, b));
	}
	for(int i = 0; i < n; i++)
	{
		int c, d;
		cin >> c >> d;
		blue.push_back(pair<int, int>(c, d));
	}
	int ret = 0;
	sort(red.begin(), red.end(), red_sort);
	sort(blue.begin(), blue.end(), blue_sort);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < (int)red.size(); j++)
		{
			if(blue[i].first > red[j].first&&blue[i].second > red[j].second)
			{
				red.erase(red.begin() + j);
				ret++;
				break;
			}
		}
	cout << ret << endl;

	return 0;
}
