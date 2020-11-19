// URL: https://atcoder.jp/contests/pakencamp-2018-day2/submissions/3861068
// Date: Mon, 24 Dec 2018 13:28:35 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
  {
    bool ok = true;
    for (int j = 1; j <= n; j++)
    {
      int tmp = -1;
      for (int k = j - 1; k < n; k += i)
        if (a[k] != 0)
          if (tmp == -1)
            tmp = a[k];
          else if (tmp != a[k])
            ok = false;
    }
    if (ok)
    {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}
