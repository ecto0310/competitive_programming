// URL: https://atcoder.jp/contests/m-solutions2020/submissions/15417480
// Date: Sat, 25 Jul 2020 21:05:34 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 A, B, C, K;
  cin >> A >> B >> C >> K;
  while (1 <= K && B <= A)
  {
    B *= 2;
    K--;
  }
  while (1 <= K && C <= B)
  {
    C *= 2;
    K--;
  }
  if (A < B && B < C)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
