// URL: https://atcoder.jp/contests/mujin-pc-2018/submissions/3835218
// Date: Sat, 22 Dec 2018 14:59:05 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	s += "     ";
	cout << (s.substr(0, 5) == "MUJIN" ? "Yes" : "No") << endl;

	return 0;
}
