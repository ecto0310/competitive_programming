// URL: https://atcoder.jp/contests/nikkei2019-ex/submissions/4311727
// Date: Mon, 18 Feb 2019 17:23:18 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  string S;
  cin >> S;
  vector<int> cnt(26, 0);
  for (char t : S)
    cnt[t - 'a']++;
  int all = 0, rest = 0;
  for (int i = 0; i < 26; i++)
  {
    all += cnt[i] / 2 * 2;
    if (cnt[i] % 2 == 1)
      rest++;
  }
  if (1 <= rest)
  {
    all++;
    rest--;
  }
  cout << (long long)all * all + rest << endl;

  return 0;
}
