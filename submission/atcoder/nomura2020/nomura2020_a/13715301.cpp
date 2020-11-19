// URL: https://atcoder.jp/contests/nomura2020/submissions/13715301
// Date: Sat, 30 May 2020 21:02:02 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 H1, M1, H2, M2, K;
  cin >> H1 >> M1 >> H2 >> M2 >> K;
  cout << H2 * 60 + M2 - (H1 * 60 + M1) - K << endl;
  return 0;
}
