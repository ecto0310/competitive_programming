// URL: https://atcoder.jp/contests/abc181/submissions/18354229
// Date: Mon, 23 Nov 2020 01:53:00 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string S;
  cin >> S;
  vector<i64> cnt(10);
  for (char i : S)
    cnt[i - '0']++;
  for (i64 i = 0; i < 10000; i++)
  {
    if (i % 8 != 0)
      continue;
    vector<i64> tmp(10);
    i64 t = i;
    for (i64 j = 0; j < min(4UL, S.size()); j++)
    {
      tmp[t % 10]++;
      t /= 10;
    }
    bool ok = true;
    for (i64 j = 0; j < 10; j++)
      if (cnt[j] < tmp[j])
        ok = false;
    if (ok)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
