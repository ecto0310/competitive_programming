// URL: https://atcoder.jp/contests/abc054/submissions/2452919
// Date: Fri, 04 May 2018 13:31:58 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	if(a == 1)a = 14;
	if(b == 1)b = 14;
	if(a == b)cout << "Draw" << endl;
	else if(a > b)cout << "Alice" << endl;
	else cout << "Bob" << endl;

	return 0;
}
