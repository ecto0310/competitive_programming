// URL: https://atcoder.jp/contests/joi2008yo/submissions/6865320
// Date: Mon, 12 Aug 2019 17:30:18 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<bool> t(n * 2 + 1);
  for (i64 i = 0; i < n; i++)
  {
    i64 a;
    cin >> a;
    t[a] = true;
  }
  vector<i64> taro, hana;
  for (i64 i = 1; i <= n * 2; i++)
    if (t[i])
      taro.push_back(i);
    else
      hana.push_back(i);
  i64 now = 0;
  for (i64 i = 0;; i++)
    if (taro.size() == 0 || hana.size() == 0)
      break;
    else if (i % 2 == 0)
    {
      i64 it = upper_bound(taro.begin(), taro.end(), now) - taro.begin();
      if ((i64)taro.size() == it)
        now = 0;
      else
      {
        now = taro[it];
        taro.erase(taro.begin() + it);
      }
    }
    else
    {
      i64 it = upper_bound(hana.begin(), hana.end(), now) - hana.begin();
      if ((i64)hana.size() == it)
        now = 0;
      else
      {
        now = hana[it];
        hana.erase(hana.begin() + it);
      }
    }
  cout << hana.size() << endl
       << taro.size() << endl;
  return 0;
}
