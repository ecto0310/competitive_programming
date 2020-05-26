// URL: https://atcoder.jp/contests/abc085/submissions/2197621
// Date: Tue, 13 Mar 2018 00:52:53 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int a[100000];
int b[100000];

int main()
{
  int N,H;
  cin>> N>> H;
  for(int i=0;i<N;i++)cin>> a[i]>> b[i];

  int ret=0;
  int at=0;
  int am=0;
  for(int i=0;i<N;i++)am=max(am,a[i]);
  sort(b,b+N,greater<int>());
  for(int i=0;i<N;i++)
  {
    if(am<=b[i])
    {
      ret++;
      at+=b[i];
    }
    else break;
    if(at>=H)break;
  }
  if(at<H)ret+=(H-at)/am+((H-at)%am?1:0);
  cout<< ret<< endl;

  return 0;
}
