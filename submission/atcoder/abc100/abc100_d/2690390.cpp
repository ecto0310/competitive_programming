// URL: https://atcoder.jp/contests/abc100/submissions/2690390
// Date: Sun, 17 Jun 2018 00:02:30 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

struct cake
{
	long long x, y, z;
};

int i, j, k;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<cake> v;
	for(int i = 0; i < n; i++)
	{
		long long x, y, z;
		cin >> x >> y >> z;
		v.push_back(cake{x,y,z});
	}
	long long ans = -10000000000000;
	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
			for(k = 0; k < 2; k++)
			{
				sort(v.begin(), v.end(),
						 [](const cake&l, const cake&r)
						 {
							 long long left = (i == 0 ? -1 : 1)*l.x + (j == 0 ? -1 : 1)*l.y + (k == 0 ? -1 : 1)*l.z;
							 long long right = (i == 0 ? -1 : 1)*r.x + (j == 0 ? -1 : 1)*r.y + (k == 0 ? -1 : 1)*r.z;
							 return left < right;
						 });
				long long tmp[3] = {};
				for(int l = 0; l < m; l++)
				{
					tmp[0] += v[l].x;
					tmp[1] += v[l].y;
					tmp[2] += v[l].z;
				}
				ans = max(ans, (long long)abs(tmp[0]) + abs(tmp[1]) + abs(tmp[2]));
			}
	cout << ans << endl;

	return 0;
}
