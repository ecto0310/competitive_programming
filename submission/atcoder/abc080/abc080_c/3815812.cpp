// URL: https://atcoder.jp/contests/abc080/submissions/3815812
// Date: Mon, 17 Dec 2018 22:49:50 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> f(n, vector<int>(10)), p(n, vector<int>(11));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 10; j++)
      cin >> f[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 11; j++)
      cin >> p[i][j];
  int ans = -1e9;
  for (int bit = 1; bit < (1 << 10); bit++)
  {
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
      int cnt = 0;
      for (int j = 0; j < 10; j++)
        if (bit & (1 << j) && f[i][j] == 1)
          cnt++;
      tmp += p[i][cnt];
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;

  return 0;
}
