// URL: https://atcoder.jp/contests/intro-heuristics/submissions/14823257
// Date: Sun, 28 Jun 2020 23:12:13 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

const int timeLimit = 1985;

int xor128()
{
  static int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
  int t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

int D;
int c[26];
int s[365][26];
vector<int> ans;

int eval(vector<int> &ans)
{
  int score = 0;
  int last[26] = {};
  for (int i = 0; i < D; i++)
  {
    score += s[i][ans[i]];
    last[ans[i]] = i + 1;
    for (int j = 0; j < 26; j++)
      score -= c[j] * (i + 1 - last[j]);
  }
  return score;
}

void solve()
{
  chrono::system_clock::time_point start = chrono::system_clock::now();
  double C = timeLimit * 100, forceLine;
  int currentTime;
  vector<int> now = ans;
  int bestScore = -1e9, nowScore = -1e9, loop = 0;
  while ((currentTime = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - start).count() / 1000) < timeLimit)
  {
    int t[3] = {xor128() % D, xor128() % 26};
    t[2] = now[t[0]];
    now[t[0]] = t[1];
    int score = eval(now);
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
  cerr << "score: " << bestScore + (int)(1e6) << endl
       << "loop: " << loop << endl;
}

void init()
{
  for (int i = 0; i < D; i++)
  {
    int m = -1e9;
    for (int j = 0; j < 26; j++)
    {
      if (m < s[i][j])
      {
        m = s[i][j];
        ans[i] = j;
      }
    }
  }
}

void input()
{
  cin >> D;
  for (int i = 0; i < 26; i++)
    cin >> c[i];
  for (int i = 0; i < D; i++)
    for (int j = 0; j < 26; j++)
      cin >> s[i][j];
  ans.resize(D);
}

void output()
{
  for (int i = 0; i < D; i++)
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
