// URL: https://atcoder.jp/contests/abc161/submissions/11548488
// Date: Sat, 04 Apr 2020 22:55:14 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  set<i64> ans;
  ans.insert(2);
  ans.insert(N);
  if (2 < N)
    ans.insert(N - 1);
  for (i64 i = 2; i * i <= N; i++)
  {
    if ((N - 1) % i == 0)
    {
      ans.insert(i);
      ans.insert((N - 1) / i);
    }
    i64 n = N;
    while (i <= n)
      if (n % i == 0)
        n /= i;
      else
        n %= i;
    if (n == 1)
      ans.insert(i);
  }
  cout << ans.size() << endl;
  return 0;
}
