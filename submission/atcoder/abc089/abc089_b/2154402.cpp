// URL: https://atcoder.jp/contests/abc089/submissions/2154402
// Date: Sun, 04 Mar 2018 21:05:16 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  string S[100];
  cin>> N;
  for(int i=0;i<N;i++)cin>> S[i];

  string ret;
  bool P=false,W=false,G=false,Y=false;

  for(int i=0;i<N;i++)
  {
    if(S[i]=="P")P=true;
    if(S[i]=="W")W=true;
    if(S[i]=="Y")G=true;
    if(S[i]=="G")Y=true;
  }
  int cou=0;
  if(P)cou++;
  if(W)cou++;
  if(G)cou++;
  if(Y)cou++;
  if(cou==3)ret="Three";
  else ret="Four";
  cout<< ret<< endl;

  return 0;
}
