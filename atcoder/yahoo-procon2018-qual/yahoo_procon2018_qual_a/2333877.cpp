// URL: https://atcoder.jp/contests/yahoo-procon2018-qual/submissions/2333877
// Date: Wed, 11 Apr 2018 00:39:04 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	cin>> S;

	string ret="NO";
	if(S.substr(0,3)=="yah"&&S[3]==S[4])ret="YES";
	cout<< ret<< endl;

	return 0;
}
