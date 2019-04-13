// URL: https://atcoder.jp/contests/abs/submissions/4937092
// Date: Sat, 13 Apr 2019 19:47:33 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin>> N;

  string ret="Yes";
  int t[2]={0},x[2]={0},y[2]={0};
  for(int i=0;i<N;i++)
  {
    cin>> t[0]>> x[0]>> y[0];
    int ti=abs(t[0]-t[1]);
    int far=abs(x[0]-x[1])+abs(y[0]-y[1]);
    if(ti<far)ret="No";
    else
    {
      if((far-ti)%2)ret="No";
    }
    t[1]=t[0];
    x[1]=x[0];
    y[1]=y[0];
  }
  cout<< ret<< endl;

  return 0;
}
