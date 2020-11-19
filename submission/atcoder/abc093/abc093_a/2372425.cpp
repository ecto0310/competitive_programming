// URL: https://atcoder.jp/contests/abc093/submissions/2372425
// Date: Tue, 17 Apr 2018 21:01:15 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	sort(s.begin(), s.end());
	if( s == "abc" )cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
