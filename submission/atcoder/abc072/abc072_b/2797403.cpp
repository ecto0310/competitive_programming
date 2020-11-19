// URL: https://atcoder.jp/contests/abc072/submissions/2797403
// Date: Fri, 06 Jul 2018 21:40:48 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int size = s.size();
	for (int i = 0; i < size; i += 2)
		cout << s[i];
	cout << endl;

	return 0;
}
