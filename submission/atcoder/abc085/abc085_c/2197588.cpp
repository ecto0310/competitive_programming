// URL: https://atcoder.jp/contests/abc085/submissions/2197588
// Date: Tue, 13 Mar 2018 00:41:57 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N,Y;
  cin>> N>> Y;

  string ret="-1 -1 -1";
  for(int i=0;i<=N;i++)
  for(int j=0;j<=N-i;j++)
  {
    if(i*10000+j*5000+(N-i-j)*1000==Y)ret=to_string(i)+" "+to_string(j)+" "+to_string(N-i-j);
  }
  cout<< ret<< endl;

  return 0;
}
