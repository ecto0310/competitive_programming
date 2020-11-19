// URL: https://atcoder.jp/contests/arc080/submissions/2443739
// Date: Tue, 01 May 2018 22:05:01 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	double count = 0;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if(a % 4 == 0)count++;
		else if(a % 2 == 0)count += 0.5;
	}
	if(n / 2 <= count)cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
