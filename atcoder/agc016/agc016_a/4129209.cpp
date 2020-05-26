// URL: https://atcoder.jp/contests/agc016/submissions/4129209
// Date: Wed, 30 Jan 2019 23:35:57 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  string s;
  cin >> s;
  int ans = 1e9;
  for (char i = 'a'; i <= 'z'; i++)
  {
    string tmp[2] = {s, ""};
    int cnt = 0;
    while (true)
    {
      int size = tmp[0].size();
      bool ok = true;
      for (int j = 0; j < size; j++)
        if (tmp[0][j] != i)
          ok = false;
      if (ok)
        break;
      tmp[1] = "";
      for (int j = 0; j < size - 1; j++)
        if (tmp[0][j] == i || tmp[0][j + 1] == i)
          tmp[1] += i;
        else
          tmp[1] += tmp[0][j];
      tmp[0] = tmp[1];
      cnt++;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;

  return 0;
}
