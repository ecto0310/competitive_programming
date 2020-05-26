// URL: https://atcoder.jp/contests/tenka1-2018-beginner/submissions/3478280
// Date: Sat, 27 Oct 2018 21:01:08 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	if (s.size() == 2)
		cout << s << endl;
	else
		cout << s[2] << s[1] << s[0] << endl;

	return 0;
}
