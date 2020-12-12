// URL: https://atcoder.jp/contests/abc183/submissions/18692278
// Date: Sat, 12 Dec 2020 12:53:39 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, W;
  cin >> N >> W;
  vector<i64> s(2 * 1e5 + 2);
  for (i64 i = 0; i < N; i++)
  {
    i64 S, T, P;
    cin >> S >> T >> P;
    s[S] += P;
    s[T] -= P;
  }
  bool ans = true;
  for (i64 i = 0; i < 2 * 1e5 + 1; i++)
  {
    if (W < s[i])
      ans = false;
    s[i + 1] += s[i];
  }
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
