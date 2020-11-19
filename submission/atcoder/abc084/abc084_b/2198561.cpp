// URL: https://atcoder.jp/contests/abc084/submissions/2198561
// Date: Tue, 13 Mar 2018 13:03:26 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int A,B;
  string S;
  cin>> A>> B;
  cin>> S;

  string ret="Yes";
  for(int i=0;i<A;i++)if(S[i]=='-')ret="No";
  if(S[A]!='-')ret="No";
  for(int i=A+1;i<A+B+1;i++)if(S[i]=='-')ret="No";
  cout<< ret<< endl;

  return 0;
}
