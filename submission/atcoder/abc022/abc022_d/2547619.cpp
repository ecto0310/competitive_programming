// URL: https://atcoder.jp/contests/abc022/submissions/2547619
// Date: Tue, 22 May 2018 17:38:32 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

struct pos
{
	int x, y;
};
pos a[100000], b[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	double ax = 0, ay = 0, bx = 0, by = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].x >> a[i].y;
		ax += a[i].x;
		ay += a[i].y;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> b[i].x >> b[i].y;
		bx += b[i].x;
		by += b[i].y;
	}
	ax /= n;
	ay /= n;
	bx /= n;
	by /= n;
	double a_range = 0, b_range = 0;
	for(int i = 0; i < n; i++)a_range = max(a_range, sqrt(pow((ax - a[i].x), 2) + pow(abs(ay - a[i].y), 2)));
	for(int i = 0; i < n; i++)b_range = max(b_range, sqrt(pow((bx - b[i].x), 2) + pow(abs(by - b[i].y), 2)));
	cout << fixed << setprecision(7) << b_range / a_range << endl;

	return 0;
}
