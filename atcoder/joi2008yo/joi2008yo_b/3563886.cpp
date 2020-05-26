// URL: https://atcoder.jp/contests/joi2008yo/submissions/3563886
// Date: Thu, 08 Nov 2018 19:26:16 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int size = s.size();
	int joi = 0, ioi = 0;
	for (int i = 0; i < size - 2; i++)
		if (s.substr(i, 3) == "JOI")
			joi++;
		else if (s.substr(i, 3) == "IOI")
			ioi++;
	cout << joi << endl
			 << ioi << endl;

	return 0;
}
