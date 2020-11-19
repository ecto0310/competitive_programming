// URL: https://atcoder.jp/contests/joi2014yo/submissions/2333478
// Date: Tue, 10 Apr 2018 22:44:16 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int P;
	int ret=0;
	for(int i=0;i<5;i++)
	{
		cin>> P;
		if(P>=40)ret+=P;
		else ret+=40;
	}
	ret/=5;
	cout<< ret<< endl;

	return 0;
}
