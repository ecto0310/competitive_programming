// URL: https://atcoder.jp/contests/rco-contest-2018-final-open/submissions/2179361
// Date: Sat, 10 Mar 2018 18:15:42 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N,K;
  cin>> N>> K;
  
  for(int i=0;i<K;i++)
  {
    if(N>K)cout<< N/2<< " "<< i+1<< endl;
    else cout<< "-1 -1"<< endl;
    i++;
    if(i>=K)break;
    if(N>K)cout<< i+1<< " "<< N/2<< endl;
    else cout<< "-1 -1"<< endl;
  }
  return 0;
}
