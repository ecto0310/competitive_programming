// URL: https://atcoder.jp/contests/abc022/submissions/2547666
// Date: Tue, 22 May 2018 17:46:05 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int ax[100000], ay[100000];
int bx[100000], by[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	double ax_ave = 0, ay_ave = 0, bx_ave = 0, by_ave = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> ax[i] >> ay[i];
		ax_ave += ax[i];
		ay_ave += ay[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> bx[i] >> by[i];
		bx_ave += bx[i];
		by_ave += by[i];
	}
	ax_ave /= n;
	ay_ave /= n;
	bx_ave /= n;
	by_ave /= n;
	double a_range = 0, b_range = 0;
	for(int i = 0; i < n; i++)a_range = max(a_range, sqrt(pow((ax_ave - ax[i]), 2) + pow(abs(ay_ave - ay[i]), 2)));
	for(int i = 0; i < n; i++)b_range = max(b_range, sqrt(pow((bx_ave - bx[i]), 2) + pow(abs(by_ave - by[i]), 2)));
	cout << fixed << setprecision(7) << b_range / a_range << endl;

	return 0;
}
