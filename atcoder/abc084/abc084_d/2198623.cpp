// URL: https://atcoder.jp/contests/abc084/submissions/2198623
// Date: Tue, 13 Mar 2018 13:30:26 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int l[100000];
int r[100000];
bool pri[100000];
int sum[100000];

int main()
{
  int Q;
  cin>> Q;
  for(int i=0;i<Q;i++)cin>> l[i]>> r[i];

  int big=0;
  for(int i=0;i<Q;i++)big=max(big,r[i]);
  for(int i=0;i<=big;i++)
  {
    pri[i]=true;
    sum[i]=0;
  }
  pri[0]=false;
  pri[1]=false;
  for(int i=2;i<=sqrt(big);i++)
  {
    if(pri[i])
    {
      for(int j=0;i*(j+2)<=big;j++)pri[i*(j+2)]=false;
    }
  }
  for(int i=0;i<=big;i++)
  {
    if(pri[i]&&pri[(i+1)/2]&&i%2)sum[i]=sum[i-1]+1;
    else sum[i]=sum[i-1];
    cerr<< ":"<< sum[i]<< endl;
  }
  for(int i=0;i<Q;i++)
  {
    cout<< sum[r[i]]-sum[l[i]-1]<< endl;
  }

  return 0;
}
