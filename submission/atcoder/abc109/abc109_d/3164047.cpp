// URL: https://atcoder.jp/contests/abc109/submissions/3164047
// Date: Sat, 08 Sep 2018 23:06:35 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int h, w, a[500][500];
  cin >> h >> w;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> a[i][j];
  vector<string> ans;
  for (int i = 0; i < h - 1; i++)
    for (int j = 0; j < w; j++)
      if (a[i][j] % 2 == 1)
      {
        ans.push_back(to_string(i + 1) + " " + to_string(j + 1) + " " + to_string(i + 2) + " " + to_string(j + 1));
        a[i + 1][j]++;
      }
  for (int i = 0; i < w - 1; i++)
    if (a[h - 1][i] % 2 == 1)
    {
      ans.push_back(to_string(h) + " " + to_string(i + 1) + " " + to_string(h) + " " + to_string(i + 2));
      a[h - 1][i + 1]++;
    }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << endl;

  return 0;
}
