// URL: https://atcoder.jp/contests/arc081/submissions/4069389
// Date: Tue, 22 Jan 2019 21:58:15 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

const int mod = 1e9 + 7;

int main()
{
  int N;
  string S1, S2;
  cin >> N >> S1 >> S2;
  long long ans = 1;
  for (int i = 0; i < N; i++)
  {
    if (S1[i] == S2[i])
    {
      if (i == 0)
        ans *= 3;
      else if (S1[i - 1] == S2[i - 1])
        ans *= 2;
    }
    else
    {
      if (i == 0)
        ans *= 6;
      else if (S1[i - 1] == S2[i - 1])
        ans *= 2;
      else
        ans *= 3;
      i++;
    }
    ans %= mod;
  }
  cout << ans % mod << endl;

  return 0;
}
