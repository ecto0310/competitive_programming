// URL: https://codeforces.com/contest/1077/submission/72478186
// Date: Thu, 05 Mar 2020 09:07:00 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 a[200000], cnt[1000001];

int main()
{
  i64 n;
  cin >> n;
  i64 sum = 0;
  for (i64 i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i];
    cnt[a[i]]++;
  }
  vector<i64> ans;
  for (i64 i = 0; i < n; i++)
    if ((sum - a[i]) % 2 == 0 && (sum - a[i]) / 2 <= 1000000 && (((sum - a[i]) / 2 == a[i] && 1 < cnt[(sum - a[i]) / 2] || ((sum - a[i]) / 2 != a[i] && 0 < cnt[(sum - a[i]) / 2]))))
      ans.push_back(i + 1);
  i64 size = ans.size();
  cout << size << "\n";
  if (0 < size)
    for (i64 i = 0; i < size; i++)
      cout << ans[i] << " \n"[i+1==size];
  return 0;
}
