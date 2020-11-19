// URL: https://atcoder.jp/contests/abc094/submissions/2372343
// Date: Tue, 17 Apr 2018 20:40:53 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int a[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for( int i = 0; i < n; i++ )cin >> a[i];
	sort(a, a + n);
	int r = -1;
	double mid = a[n - 1] / 2.0;
	for( int i = 0; i < n; i++ )
	{
		if( abs(a[i] - mid) < abs(r - mid) )r = a[i];
	}
	cout << a[n - 1] << " " << r << endl;

	return 0;
}
