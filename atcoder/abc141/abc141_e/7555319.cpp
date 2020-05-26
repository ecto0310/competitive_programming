// URL: https://atcoder.jp/contests/abc141/submissions/7555319
// Date: Mon, 16 Sep 2019 13:13:15 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

struct RollingHash
{
  i64 base1 = 1009, base2 = 1007;
  i64 mod1 = 1000000007, mod2 = 1000000009;
  vector<i64> hash1, hash2;
  vector<i64> pow1, pow2;
  void init(string s)
  {
    i64 n = s.size();
    hash1.resize(n + 1, 0);
    hash2.resize(n + 1, 0);
    pow1.resize(n + 1, 1);
    pow2.resize(n + 1, 1);
    for (i64 i = 0; i < n; i++)
    {
      hash1[i + 1] = (hash1[i] + s[i]) * base1 % mod1;
      hash2[i + 1] = (hash2[i] + s[i]) * base2 % mod2;
      pow1[i + 1] = pow1[i] * base1 % mod1;
      pow2[i + 1] = pow2[i] * base2 % mod2;
    }
  }

  pair<i64, i64> get(i64 l, i64 r)
  {
    i64 t1 = ((hash1[r] - hash1[l] * pow1[r - l]) % mod1 + mod1) % mod1;
    i64 t2 = ((hash2[r] - hash2[l] * pow2[r - l]) % mod2 + mod2) % mod2;
    return {t1, t2};
  }
};

RollingHash rh;

bool check(i64 l, i64 n, string s)
{
  set<pair<i64, i64>> c;
  for (i64 i = 0; i <= n - l - l; i++)
  {
    c.insert(rh.get(i, i + l));
    if (c.count(rh.get(i + l, i + l * 2)))
      return true;
  }
  return false;
}

int main()
{
  i64 n;
  string s;
  cin >> n >> s;
  rh.init(s);
  i64 l = 0, r = n;
  while (1 < r - l)
  {
    i64 mid = (r + l) / 2;
    if (check(mid, n, s))
      l = mid;
    else
      r = mid;
  }
  cout << l << endl;
  return 0;
}
