// URL: https://atcoder.jp/contests/arc079/submissions/4012337
// Date: Mon, 14 Jan 2019 11:56:22 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long> a(N);
  for (int i = 0; i < N; i++)
    cin >> a[i];
  long long ans = 0;
  while (true)
  {
    long long tmp = 0;
    bool ok = false;
    for (int i = 0; i < N; i++)
    {
      tmp += a[i] / N;
      if (N <= a[i])
        ok = true;
    }
    if (!ok)
      break;
    ans += tmp;
    for (int i = 0; i < N; i++)
      a[i] = a[i] % N + tmp - a[i] / N;
  }
  cout << ans << endl;

  return 0;
}
