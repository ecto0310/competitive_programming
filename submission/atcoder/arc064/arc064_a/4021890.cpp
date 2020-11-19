// URL: https://atcoder.jp/contests/arc064/submissions/4021890
// Date: Wed, 16 Jan 2019 02:26:35 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  long long N, x;
  cin >> N >> x;
  vector<long long> a(N);
  for (int i = 0; i < N; i++)
    cin >> a[i];
  long long ans = 0;
  for (int i = 0; i < N; i++)
    if (x < (i == 0 ? 0 : a[i - 1]) + a[i])
    {
      ans += (i == 0 ? 0 : a[i - 1]) + a[i] - x;
      a[i] = x - (i == 0 ? 0 : a[i - 1]);
    }
  cout << ans << endl;

  return 0;
}
