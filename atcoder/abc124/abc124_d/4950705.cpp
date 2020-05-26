// URL: https://atcoder.jp/contests/abc124/submissions/4950705
// Date: Sat, 13 Apr 2019 21:31:18 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  string s;
  cin >> n >> k >> s;
  vector<i64> sec;
  i64 bef = 0;
  for (i64 i = 1; i < n; i++)
    if (s[i - 1] != s[i])
    {
      sec.push_back(i - bef);
      bef = i;
    }
  sec.push_back(n - bef);
  i64 ans = 0, tmp = 0, r = 0, cnt = 0, size = sec.size();
  string now = (s[0] == '0' ? "01" : "10");
  for (i64 l = 0; l < size; l++)
  {
    while (r < size && (now[0] == '1' || (now[0] == '0' && cnt + 1 <= k)))
    {
      tmp += sec[r];
      r++;
      if (now[0] == '0')
        cnt++;
      swap(now[0], now[1]);
    }
    ans = max(ans, tmp);
    if (l == r)
      r++;
    else
    {
      tmp -= sec[l];
      if ((l % 2 == 0 && s[0] == '0') || (l % 2 == 1 && s[0] == '1'))
        cnt--;
    }
  }
  cout << ans << endl;

  return 0;
}
