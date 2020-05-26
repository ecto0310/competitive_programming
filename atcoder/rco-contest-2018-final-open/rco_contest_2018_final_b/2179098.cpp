// URL: https://atcoder.jp/contests/rco-contest-2018-final-open/submissions/2179098
// Date: Sat, 10 Mar 2018 17:43:29 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N,M,Q;
  cin>> N>> M>> Q;
  for(int i=0;i<N;i++)cout<< "a";
  cout<< endl;
  cout<< (float)(rand()%9)/10+1<< endl;
  string q;
  for(int i=0;i<Q;i++)cin>> q;

  for(int i=0;i<Q;i++)cout<< rand()%N<< endl;
  return 0;
}
