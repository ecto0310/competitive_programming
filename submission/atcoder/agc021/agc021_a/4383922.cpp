// URL: https://atcoder.jp/contests/agc021/submissions/4383922
// Date: Mon, 25 Feb 2019 17:00:41 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  string N;
  cin >> N;
  int ans = N[0] - '0' - 1 + 9 * (N.size() - 1), tmp = 0;
  for (char t : N)
    tmp += t - '0';
  cout << max(ans, tmp) << endl;

  return 0;
}
