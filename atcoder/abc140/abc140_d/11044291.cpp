// URL: https://atcoder.jp/contests/abc140/submissions/11044291
// Date: Sat, 21 Mar 2020 19:32:23 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, K;
  string S;
  cin >> N >> K >> S;
  i64 h = 0, l = 0, r = 0;
  while (l < N)
  {
    while (S[l] == S[r] && r < N)
      r++;
    h += r - l - 1;
    l = r;
  }
  cout << min(N - 1, h + 2 * K) << endl;
  return 0;
}
