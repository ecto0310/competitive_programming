// URL: https://atcoder.jp/contests/rcl-contest-2020-qual/submissions/10109571
// Date: Sat, 15 Feb 2020 22:19:29 +0900
// Language: C++14 (GCC 5.4.1)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 timeLimit = 1998;
const i64 fireTimeLimit = timeLimit * 0.8;

i64 randxor()
{
  static i64 x = 123456789, y = 362436069, z = 521288629, w = 88675123;
  i64 t;
  t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

struct Mono
{
  i64 color, value;
};

i64 n, w, k, v;
vector<Mono> mono;

pair<i64, i64> calc(vector<vector<i64>> &bord, vector<i64> &high)
{
  i64 h = *min_element(high.begin(), high.end());
  pair<i64, i64> ret = {0, 0};
  for (i64 i = 0; i < h; i++)
  {
    vector<i64> value(k);
    for (i64 j = 0; j < w; j++)
      value[mono[bord[j][i]].color] += mono[bord[j][i]].value;
    ret.first += *max_element(value.begin(), value.end());
    ret.second += *max_element(value.begin(), value.end()) * 2;
    for (i64 j = 0; j < k; j++)
      ret.second -= value[j] / 2;
  }
  return ret;
}

int main()
{
  chrono::system_clock::time_point start = chrono::system_clock::now();
  i64 currentTime;
  cin >> n >> w >> k >> v;
  mono.resize(n);
  for (i64 i = 0; i < n; i++)
    cin >> mono[i].color >> mono[i].value;
  pair<i64, i64> bestScore = {-1, -1}, currentScore = {-1, -1};
  vector<i64> bestAns, currentAns(n);
  for (i64 i = 0; i < n; i++)
    currentAns[i] = randxor() % w;
  bool big = true;
  while ((currentTime = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - start).count() / 1000) < timeLimit)
  {
    if (fireTimeLimit * 0.5 < currentTime)
      big = false;
    i64 c[2][20];
    for (i64 i = 0; i < (big ? 20 : 1); i++)
    {
      c[0][i] = randxor() % n;
      c[1][i] = currentAns[c[0][i]];
      currentAns[c[0][i]] = randxor() % w;
    }
    vector<vector<i64>> bord(w, vector<i64>(1000, -1));
    vector<i64> high(w);
    for (i64 i = 0; i < n; i++)
      bord[currentAns[i]][high[currentAns[i]]++] = i;
    pair<i64, i64> score = calc(bord, high);
    if (currentScore.second < score.second)
    {
      currentScore = score;
    }
    else
    {
      for (i64 i = (big ? 19 : 0); 0 <= i; i--)
      {
        currentAns[c[0][i]] = c[1][i];
      }
    }
    if (bestScore.first < score.first)
    {
      bestAns = currentAns;
      bestScore = score;
    }
  }
  cerr << bestScore.first << endl;
  for (i64 i = 0; i < n; i++)
    cout << bestAns[i] << "\n";
  return 0;
}
