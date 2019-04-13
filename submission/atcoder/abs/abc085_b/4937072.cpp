// URL: https://atcoder.jp/contests/abs/submissions/4937072
// Date: Sat, 13 Apr 2019 19:46:39 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  int d[100];
  cin>> N;
  for(int i=0;i<N;i++)cin>> d[i];

  set<int> s;
  for(int i=0;i<N;i++)
  {
    s.insert(d[i]);
  }
  cout<< s.size()<< endl;

  return 0;
}
