// URL: https://atcoder.jp/contests/abc092/submissions/2255000
// Date: Sun, 25 Mar 2018 21:01:14 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int A,B,C,D;
  cin>> A>> B>> C>> D;

  int ret=min(A,B)+min(C,D);
  cout<< ret<< endl;
  
  return 0;
}
