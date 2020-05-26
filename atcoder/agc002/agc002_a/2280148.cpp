// URL: https://atcoder.jp/contests/agc002/submissions/2280148
// Date: Fri, 30 Mar 2018 20:35:13 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a,b;
	cin>> a>> b;

	string ret="Positive";
	if(a<=0&&0<=b)ret="Zero";
	else if(a<0&&(b-a)%2==0)ret="Negative";
	cout<< ret<< endl;

	return 0;
}
