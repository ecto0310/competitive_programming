// URL: https://atcoder.jp/contests/yahoo-procon2019-qual/submissions/4220479
// Date: Sun, 10 Feb 2019 05:17:47 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  long long K, A, B;
  cin >> K >> A >> B;
  long long ans;
  if (B - A <= 2)
    ans = K + 1;
  else
    ans = A + max(0LL, (K - A + 1)) / 2 * (B - A) + max(0LL, (K - A + 1)) % 2;
  cout << ans << endl;
  return 0;
}
