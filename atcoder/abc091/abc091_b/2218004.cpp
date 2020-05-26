// URL: https://atcoder.jp/contests/abc091/submissions/2218004
// Date: Sat, 17 Mar 2018 21:10:35 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N,M;
  string s[100];
  string t[100];
  cin>> N;
  for(int i=0;i<N;i++)cin>> s[i];
  cin>> M;
  for(int i=0;i<M;i++)cin>> t[i];

  int ret=0;
  for(int i=0;i<N;i++){
    string ser=s[i];
    int sum=0;
    for(int j=0;j<N;j++)if(s[j]==ser)sum++;
    for(int j=0;j<M;j++)if(t[j]==ser)sum--;
    if(sum>ret)ret=sum;
  }
  cout<< ret<< endl;
  return 0;
}
