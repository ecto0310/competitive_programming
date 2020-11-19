// URL: https://atcoder.jp/contests/agc032/submissions/4725775
// Date: Wed, 27 Mar 2019 09:34:46 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
    b[i]--;
  }
  vector<int> ans;
  while (b.size() != 0)
  {
    bool erase = false;
    for (int i = (int)b.size() - 1; 0 <= i; i--)
      if (i == b[i])
      {
        ans.push_back(i + 1);
        b.erase(b.begin() + i);
        erase = true;
        break;
      }
    if (!erase)
    {
      cout << -1 << "\n";
      return 0;
    }
  }
  for (int i = ans.size() - 1; 0 <= i; i--)
    cout << ans[i] << "\n";

  return 0;
}
