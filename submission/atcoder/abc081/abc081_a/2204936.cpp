// URL: https://atcoder.jp/contests/abc081/submissions/2204936
// Date: Wed, 14 Mar 2018 21:10:55 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  cin>> s;

  int ret=0;
  if(s[0]=='1')ret++;
  if(s[1]=='1')ret++;
  if(s[2]=='1')ret++;
  cout<< ret<< endl;

  return 0;
}
