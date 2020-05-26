// URL: https://atcoder.jp/contests/abc099/submissions/2651292
// Date: Sun, 10 Jun 2018 22:26:45 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	for(int i = 1; i < 1000; i++)
	{
		if(0.5*i*(i + 1) - a > 0 && 0.5*i*(i + 1) - a == 0.5*(i + 1)*(i + 2) - b)
		{
			cout << 0.5*i*(i + 1) - a << endl;
			return 0;
		}
	}

	return 0;
}
