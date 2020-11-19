// URL: https://atcoder.jp/contests/pakencamp-2019-day3/submissions/9526813
// Date: Thu, 16 Jan 2020 00:29:36 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<string> s(n);
  for (i64 i = 0; i < n; i++)
    cin >> s[i];
  i64 cnt[2] = {};
  for (i64 i = 0; i < n; i++)
    if (s[i] == "black")
      cnt[0]++;
    else
      cnt[1]++;
  if (cnt[0] < cnt[1])
    cout << "white" << endl;
  else
    cout << "black" << endl;
  return 0;
}
