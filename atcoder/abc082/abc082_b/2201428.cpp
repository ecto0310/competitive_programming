// URL: https://atcoder.jp/contests/abc082/submissions/2201428
// Date: Wed, 14 Mar 2018 00:47:42 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  string s,t;
  cin>> s>> t;

  string ret="No";
  sort(s.begin(),s.end());
  sort(t.begin(),t.end(),greater<int>());
  if(s<t)ret="Yes";
  cout<< ret<< endl;

  return 0;
}
