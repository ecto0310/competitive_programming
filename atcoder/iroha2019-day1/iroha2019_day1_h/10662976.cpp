// URL: https://atcoder.jp/contests/iroha2019-day1/submissions/10662976
// Date: Sun, 08 Mar 2020 17:19:08 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  string n;
  cin >> n;
  i64 sum = 0;
  for (i64 i = 0; i < n.size(); i++)
    sum += (n[i] - '0');
  string ans;
  while (0 < sum)
  {
    ans = to_string(min(sum, 9LL)) + ans;
    sum -= 9;
  }
  if (ans == n)
  {
    if (ans.length() == 1)
    {
      ans = to_string(stoll(ans) + 9);
    }
    else
    {
      if (ans[0] == '9')
      {
        ans[0] = '8';
        ans = "1" + ans;
      }
      else
      {
        ans[0]++;
        ans[1]--;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
