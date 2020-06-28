// URL: https://atcoder.jp/contests/intro-heuristics/submissions/14819418
// Date: Sun, 28 Jun 2020 22:40:30 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

const int timeLimit = 1985;

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
  while ((currentTime = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - start).count() / 1000) < timeLimit)
  {
    i64 t[3] = {xor128() % D, xor128() % 26};
    t[2] = now[t[0]];
    now[t[0]] = t[1];
    i64 score = eval(now);
    forceLine = (timeLimit - currentTime) / C;
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
      now[t[0]] = t[2];
    }
    loop++;
  }
  cerr << "score: " << bestScore + (i64)(1e6) << endl
       << "loop: " << loop << endl;
}

void init()
{
  for (i64 i = 0; i < D; i++)
    ans[i] = xor128() % 26;
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
  init();
  solve();
  output();
  return 0;
}
