// URL: https://atcoder.jp/contests/abc084/submissions/2198747
// Date: Tue, 13 Mar 2018 14:04:21 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  int C[500],S[500],F[500];
  cin>> N;
  for(int i=0;i<N-1;i++)cin>> C[i]>> S[i]>> F[i];

  for(int i=0;i<N;i++)
  {
    cerr<< "::"<< i<< endl;
    int ret=0;
    for(int j=i;j<N-1;j++)
    {
      if(ret<=S[j])ret=S[j];
      else if(ret%F[j])ret+=F[j]-ret%F[j];
      ret+=C[j];
      cerr<< ":"<< ret<< endl;
    }
    cout<< ret<< endl;
  }

  return 0;
}
