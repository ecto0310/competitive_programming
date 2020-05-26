// URL: https://atcoder.jp/contests/abc093/submissions/2314226
// Date: Sat, 07 Apr 2018 21:06:28 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int A,B,K;
	cin>> A>> B>> K;
	for(int i=A;i<min(A+K,B+1);i++)cout<< i<< endl;
	for(int i=max(B-K+1,A+K);i<=B;i++)cout<< i<< endl;

	return 0;
}
