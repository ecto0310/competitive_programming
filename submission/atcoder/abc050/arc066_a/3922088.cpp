// URL: https://atcoder.jp/contests/abc050/submissions/3922088
// Date: Thu, 03 Jan 2019 19:56:57 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

const int mod = 1e9 + 7;

int main()
{
  int n;
  cin >> n;
  map<int, int> m;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    m[a]++;
  }
  bool ok = true;
  if (n % 2 == 1 && m[0] != 1)
    ok = false;
  for (pair<int, int> t : m)
    if ((n - 1 - t.first) % 2 != 0 || (t.first != 0 && t.second != 2))
      ok = false;
  long long ans = 1;
  for (int i = 0; i < n / 2; i++)
  {
    ans *= 2;
    ans %= mod;
  }
  cout << (ok ? ans : 0) << endl;

  return 0;
}
