// URL: https://atcoder.jp/contests/intro-heuristics/submissions/14818065
// Date: Sun, 28 Jun 2020 22:30:29 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

const int timeLimit = 1980;

i64 xor128()
{
  static i64 x = 123456789, y = 362436069, z = 521288629, w = 88675123;
  i64 t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

i64 D;
i64 c[26];
i64 s[365][26];
vector<i64> ans;

i64 eval(vector<i64> &ans)
{
  i64 score = 0;
  i64 last[26] = {};
  for (i64 i = 0; i < D; i++)
  {
    score += s[i][ans[i]];
    last[ans[i]] = i + 1;
    for (i64 j = 0; j < 26; j++)
      score -= c[j] * (i + 1 - last[j]);
  }
  return score;
}

void solve()
{
  chrono::system_clock::time_point start = chrono::system_clock::now();
  i64 bestScore = -1e18, nowScore = -1e18, loop = 0;
  double C = timeLimit * 100, forceLine;
  i64 currentTime;
  vector<i64> now = ans;
  i64 t[10][3];
  while ((currentTime = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - start).count() / 1000) < timeLimit)
  {
    forceLine = (timeLimit - currentTime) / C;
    i64 cCount = max(1LL, (i64)(forceLine * 1000));
    for (i64 i = 0; i < cCount; i++)
    {
      t[i][0] = xor128() % D;
      t[i][1] = xor128() % 26;
      t[i][2] = now[t[i][0]];
      now[t[i][0]] = t[i][1];
    }
    i64 score = eval(now);
    if (bestScore < score)
    {
      ans = now;
      bestScore = score;
    }
    if (nowScore < score || forceLine * 1000 > rand() % 1000)
    {
      nowScore = score;
    }
    else
    {
      for (i64 i = cCount - 1; 0 <= i; i--)
        now[t[i][0]] = t[i][2];
    }
    loop++;
  }
  cerr << "score: " << bestScore + (i64)(1e6) << endl
       << "loop: " << loop << endl;
}

void input()
{
  cin >> D;
  for (i64 i = 0; i < 26; i++)
    cin >> c[i];
  for (i64 i = 0; i < D; i++)
    for (i64 j = 0; j < 26; j++)
      cin >> s[i][j];
  ans.resize(D);
}

void output()
{
  for (i64 i = 0; i < D; i++)
    cout << ans[i] + 1 << endl;
}

int main()
{
  input();
  solve();
  output();
  return 0;
}
