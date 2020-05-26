// URL: https://atcoder.jp/contests/abc058/submissions/3816499
// Date: Tue, 18 Dec 2018 01:01:13 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> ans(26, 1e9);
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (int j = 0; j < s.size(); j++)
      cnt[s[j] - 'a']++;
    for (int j = 0; j < 26; j++)
      ans[j] = min(ans[j], cnt[j]);
  }
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < ans[i]; j++)
      cout << (char)('a' + i);
  cout << endl;

  return 0;
}
