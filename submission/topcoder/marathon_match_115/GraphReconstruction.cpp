#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 INF = 1e4;

const i64 cyclePerSec = 2800000000;
const double timeLimit = 9.5;
const double fireTimeLimit = timeLimit * 0.8;

i64 getCycle()
{
  i64 low, high;
  __asm__ volatile("rdtsc"
                   : "=a"(low), "=d"(high));
  return ((i64)low) | ((i64)high << 32);
}

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

struct Path
{
  i64 start, end, distance;
};

class GraphReconstruction
{
  i64 getScore(vector<vector<i64>> &edge, vector<Path> &paths)
  {
    i64 ret = 0;
    for (Path i : paths)
      if (i.distance == 1)
        continue;
      else
        ret += (edge[i.start][i.end] - i.distance) * (i.distance == -1 ? 2 : 1);
    return ret;
  }

public:
  vector<string> findSolution(i64 N, double C, i64 K, i64 P, vector<Path> paths)
  {
    long long baseTime = getCycle();
    i64 bestScore = INF * INF * INF, currentScore = INF * INF * INF;
    vector<vector<i64>> bestAns, currentAns(N, vector<i64>(N, INF));
    i64 tmp = N * (N - 1) / 2 * max(0.01, (C - 0.05));
    vector<vector<bool>> notChange(N, vector<bool>(N, false));
    for (Path &i : paths)
    {
      if (i.distance == 1)
      {
        notChange[i.start][i.end] = notChange[i.end][i.start] = true;
        currentAns[i.start][i.end] = currentAns[i.end][i.start] = 1;
        tmp--;
      }
      if (i.distance == -1)
        notChange[i.start][i.end] = notChange[i.end][i.start] = true;
    }
    bestAns = currentAns;
    bestScore = currentScore = getScore(currentAns, paths);
    vector<string> ret(N, string(N, '0'));
    for (i64 i = 0; i < N; i++)
      for (i64 j = 0; j < N; j++)
        if (bestAns[i][j] == 1)
          ret[i][j] = '1';
    return ret;
  }
};

int main()
{
  GraphReconstruction prog;
  i64 N, K, P;
  double C;
  cin >> N;
  cin >> C;
  cin >> K;
  cin >> P;
  vector<Path> paths(P);
  for (int i = 0; i < P; i++)
  {
    cin >> paths[i].start >> paths[i].end >> paths[i].distance;
    if (paths[i].end < paths[i].start)
      swap(paths[i].end, paths[i].start);
  }

  vector<string> ret = prog.findSolution(N, C, K, P, paths);

  cout << ret.size() << endl;
  for (int i = 0; i < (int)ret.size(); ++i)
    cout << ret[i] << endl;
  cout.flush();
}
