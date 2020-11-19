// URL: https://codeforces.com/contest/1287/submission/68280194
// Date: Mon, 06 Jan 2020 02:02:28 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  cin >> n >> k;
  vector<string> s(n);
  for (i64 i = 0; i < n; i++)
    cin >> s[i];
  map<string, i64> cnt;
  for (i64 i = 0; i < n; i++)
    cnt[s[i]]++;
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    for (i64 j = i+1; j < n; j++)
    {
      string t;
      for (i64 l = 0; l < k; l++)
        if (s[i][l] == s[j][l])
          t += s[i][l];
        else
          t += (char)('S'+'T'+'E' - s[i][l] - s[j][l]);
      ans += cnt[t];
    }
  cout << ans / 3 << "\n";
  return 0;
}
