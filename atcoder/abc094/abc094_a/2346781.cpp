// URL: https://atcoder.jp/contests/abc094/submissions/2346781
// Date: Sat, 14 Apr 2018 21:11:25 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int A,B,X;
	cin>> A>> B>> X;

	if(A<=X&&A+B>=X)cout<< "YES"<< endl;
	else cout<< "NO"<< endl;

	return 0;
}
