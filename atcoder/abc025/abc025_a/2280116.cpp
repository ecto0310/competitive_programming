// URL: https://atcoder.jp/contests/abc025/submissions/2280116
// Date: Fri, 30 Mar 2018 20:22:41 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	int N;
	cin>> S>> N;

	cout<< S[(N-1)/5]<< S[(N%5+4)%5]<< endl;
	
	return 0;
}
