// URL: https://atcoder.jp/contests/code-festival-2018-qualb/submissions/4407029
// Date: Thu, 28 Feb 2019 00:45:08 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, X;
  cin >> N >> X;
  int ans = 0, m = 0;
  for (int i = 0; i < N; i++)
  {
    int a, b;
    cin >> a >> b;
    ans += a * b;
    m = max(m, b);
  }
  cout << ans + X * m << endl;

  return 0;
}
