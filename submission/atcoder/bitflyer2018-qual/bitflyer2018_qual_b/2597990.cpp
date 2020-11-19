// URL: https://atcoder.jp/contests/bitflyer2018-qual/submissions/2597990
// Date: Sat, 02 Jun 2018 21:07:31 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int a, b, n;
	string x;
	cin >> a >> b >> n >> x;
	for(int i = 0; i < n; i++)
	{
		if(x[i] == 'S'&&a > 0)a--;
		else if(x[i] == 'C'&&b > 0)b--;
		else if(x[i] == 'E' && (a != 0 || b != 0))
		{
			if(a > b)a--;
			else if(a < b)b--;
			else a--;
		}
	}
	cout << a << " " << b << endl;

	return 0;
}
