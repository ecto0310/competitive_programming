// URL: https://atcoder.jp/contests/abc067/submissions/2799621
// Date: Sat, 07 Jul 2018 15:05:18 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	if(a%3==0||b%3==0||(a+b)%3==0)cout<< "Possible"<< endl;
	else cout<<"Impossible"<< endl;

	return 0;
}
