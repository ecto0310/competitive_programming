// URL: https://atcoder.jp/contests/abc113/submissions/3535986
// Date: Sun, 04 Nov 2018 21:21:13 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

struct data
{
	int p, y, n, x = -1;

	bool operator<(const data &right) const
	{
		return x == -1 ? y < right.y : n < right.n;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	vector<data> v;
	for (int i = 0; i < m; i++)
	{
		int p, y;
		cin >> p >> y;
		data t = {p, y, i + 1};
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	map<int, int> ma;
	for (int i = 0; i < m; i++)
	{
		v[i].x = ma[v[i].p] + 1;
		ma[v[i].p]++;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++)
		cout << setfill('0') << setw(6) << right << v[i].p << setfill('0') << setw(6) << right << v[i].x << endl;
	;

	return 0;
}
