// URL: https://codeforces.com/contest/1077/submission/72478214
// Date: Thu, 05 Mar 2020 09:08:04 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct data_t
{
  i64 cnt, num, use = 0;

  bool operator<(const data_t &right) const
  {
    return cnt / (use + 1) < right.cnt / (right.use + 1);
  }
};

int main()
{
  i64 n, k;
  cin >> n >> k;
  vector<i64> s(n), tmp(200001, 0);
  for (i64 i = 0; i < n; i++)
  {
    cin >> s[i];
    tmp[s[i]]++;
  }
  priority_queue<data_t> cnt;
  for (i64 i = 0; i <= 200000; i++)
    if (tmp[i] != 0)
      cnt.push(data_t{tmp[i], i});
  vector<i64> ans(k);
  i64 size = cnt.size();
  for (i64 i = 0; i < k; i++)
  {
    data_t t = cnt.top();
    cnt.pop();
    ans[i] = t.num;
    t.use++;
    cnt.push(t);
  }
  for (i64 i = 0; i < k; i++)
    cout << ans[i] << " \n"[i + 1 == k];
  return 0;
}
