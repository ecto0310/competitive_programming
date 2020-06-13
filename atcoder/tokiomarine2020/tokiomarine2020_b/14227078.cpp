// URL: https://atcoder.jp/contests/tokiomarine2020/submissions/14227078
// Date: Sat, 13 Jun 2020 21:08:31 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 A, V, B, W, T;
  cin >> A >> V >> B >> W >> T;
  if ((V - W) * T < abs(A - B))
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
