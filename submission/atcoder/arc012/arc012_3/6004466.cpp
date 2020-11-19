// URL: https://atcoder.jp/contests/arc012/submissions/6004466
// Date: Tue, 18 Jun 2019 07:59:13 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

bool check(vector<string> &b, char h)
{
  for (i64 i = 0; i < 19; i++)
    for (i64 j = 0; j < 19; j++)
      if (b[i][j] == h)
      {
        if (i < 15 && b[i + 1][j] == h && b[i + 2][j] == h && b[i + 3][j] == h && b[i + 4][j] == h)
          return false;
        if (j < 15 && b[i][j + 1] == h && b[i][j + 2] == h && b[i][j + 3] == h && b[i][j + 4] == h)
          return false;
        if (i < 15 && j < 15 && b[i + 1][j + 1] == h && b[i + 2][j + 2] == h && b[i + 3][j + 3] == h && b[i + 4][j + 4] == h)
          return false;
        if (i < 15 && 3 < j && b[i + 1][j - 1] == h && b[i + 2][j - 2] == h && b[i + 3][j - 3] == h && b[i + 4][j - 4] == h)
          return false;
      }
  return true;
}

int main()
{
  vector<string> b(19);
  for (i64 i = 0; i < 19; i++)
    cin >> b[i];
  i64 cnto = 0, cntx = 0;
  for (i64 i = 0; i < 19; i++)
    for (i64 j = 0; j < 19; j++)
      if (b[i][j] == 'o')
        cnto++;
      else if (b[i][j] == 'x')
        cntx++;
  if (cnto != cntx && cnto != cntx + 1)
  {
    cout << "NO" << endl;
    return 0;
  }
  char h1 = (cnto == cntx ? 'o' : 'x'), h2 = (cnto == cntx ? 'x' : 'o');
  if (!check(b, h1))
  {
    cout << "NO" << endl;
    return 0;
  }
  i64 cnt = 0;
  for (i64 i = 0; i < 19; i++)
    for (i64 j = 0; j < 19; j++)
      if (b[i][j] == h2)
      {
        b[i][j] = '.';
        if (check(b, h2))
        {
          cout << "YES" << endl;
          return 0;
        }
        cnt++;
        b[i][j] = h2;
      }
  if (cnt == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
