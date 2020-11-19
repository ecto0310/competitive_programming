// URL: https://atcoder.jp/contests/abc094/submissions/2352951
// Date: Sat, 14 Apr 2018 21:57:03 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	vector<int> v;
	cin>> N;
	for(int i=0;i<N;i++)
	{
		int X;
		cin>> X;
		v.push_back(X);
	}

	vector<int> t;
	for(int i=0;i<N;i++)t.push_back(v[i]);
	sort(t.begin(),t.end());
	int s=t.size()+1;
	int c=t[s/2];
	for(int i=0;i<N;i++)
	{
		int ret;
		if(c>v[i])ret=t[s/2];
		else ret=t[s/2-1];
		cout<< ret<< endl;
	}

	return 0;
}
