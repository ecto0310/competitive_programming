// URL: https://atcoder.jp/contests/abc089/submissions/2160237
// Date: Sun, 04 Mar 2018 22:42:08 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

string S[100000];

int main()
{
  int N;
  cin>> N;
  for(int i=0;i<N;i++)cin>> S[i];

  unsigned long long ret=0;
  unsigned long long M=0,A=0,R=0,C=0,H=0;
  for(int i=0;i<N;i++)
  {
    if(S[i][0]=='M')M++;
    else if(S[i][0]=='A')A++;
    else if(S[i][0]=='R')R++;
    else if(S[i][0]=='C')C++;
    else if(S[i][0]=='H')H++;
  }
  ret+=R*C*H;
  ret+=A*C*H;
  ret+=A*R*H;
  ret+=A*R*C;
  ret+=M*C*H;
  ret+=M*R*H;
  ret+=M*R*C;
  ret+=M*A*H;
  ret+=M*A*C;
  ret+=M*A*R;
  
  cout<< ret<< endl;

  return 0;
}
