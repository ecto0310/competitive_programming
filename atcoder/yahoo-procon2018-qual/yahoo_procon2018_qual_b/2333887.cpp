// URL: https://atcoder.jp/contests/yahoo-procon2018-qual/submissions/2333887
// Date: Wed, 11 Apr 2018 00:41:52 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int X,K;
	cin>> X>> K;

	for(int i=0;i<K;i++)X/=10;
	X++;
	for(int i=0;i<K;i++)X*=10;
	cout<< X<< endl;

	return 0;
}
