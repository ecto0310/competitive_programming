#include <bits/stdc++.h>
#include "BIT.hpp"
using namespace std;
using i64 = long long;
#define endl "\n"

const double timeLimit = 9.5;
const long long cyclePerSec = 2800000000;
long long baseTime;

random_device rd;
mt19937 mt(rd());

unsigned long long int getCycle()
{
  unsigned int low, high;
  __asm__ volatile("rdtsc"
                   : "=a"(low), "=d"(high));
  return ((unsigned long long int)low) | ((unsigned long long int)high << 32);
}

int N;
int K;
double X;
vector<i64> S;

vector<string> ans;

vector<i64> bestOrder, currentOrder;
i64 useOrder;

i64 reverse(vector<i64> &seq, i64 s, i64 t)
{
  for (i64 i = s, j = t; i < j; i++, j--)
    swap(seq[i], seq[j]);
  return (i64)pow(t - s + 1, X);
}

i64 eval(i64 target, i64 end)
{
  i64 score = 0;
  vector<i64> seq = S;
  for (i64 i = 0; i < N && end < target; i++)
  {
    i64 left = max(end, target - currentOrder[i] - 1);
    score += reverse(seq, left, target);
    target = left;
    useOrder = i;
  }
  BIT<i64> bit(N);
  i64 cnt = 0;
  for (i64 i = 0; i < N; i++)
  {
    cnt += i - bit.sum0(seq[i]);
    bit.add0(seq[i], 1);
  }
  score += cnt / (N - end) / 10 * (i64)pow(2, X);
  return score;
}

void solve()
{
  baseTime = getCycle();
  double currentTime;
  double C = timeLimit * 100;
  i64 count = 0;
  for (i64 i = 0; i < N; i++)
  {
    i64 bestScore = 1e9;
    i64 tmp = 1e9, target = -1;
    for (i64 j = i; j < N; j++)
      if (S[j] < tmp)
      {
        tmp = S[j];
        target = j;
      }
    if (target == i)
      continue;
    currentOrder = vector<i64>(N, N);
    useOrder = 0;
    currentTime = (double)(getCycle() - baseTime) / cyclePerSec;
    double currentTimeLimit = timeLimit * (i + 1) * (N - i + N) / 2 / (N * (N + 1) / 2);
    while (currentTime < currentTimeLimit)
    {
      i64 changeInd = mt() % (useOrder + 1), changeNum = mt() % (N - i - 1);
      swap(currentOrder[changeInd], changeNum);
      i64 currentScore = eval(target, i);
      currentTime = (double)(getCycle() - baseTime) / cyclePerSec;
      double forceLine = (timeLimit - currentTime) / C;
      if (currentScore < bestScore)
      {
        // cerr << "Update best score.(" << bestScore << " -> " << currentScore << ")" << endl;
        bestScore = currentScore;
        bestOrder = currentOrder;
      }
      if (bestScore < currentScore && forceLine < (double)mt() / mt19937::max())
        swap(currentOrder[changeInd], changeNum);
      count++;
    }
    for (i64 j = 0; j < N && i < target; j++)
    {
      i64 left = max(i, target - bestOrder[j] - 1);
      ans.push_back(to_string(left) + " " + to_string(target));
      reverse(S, left, target);
      target = left;
    }
  }

  cerr << "count: " << count << endl;
  cerr << "time: " << (double)(getCycle() - baseTime) / cyclePerSec << endl;
  return;
}

void init()
{
  return;
}

void input()
{
  cin >> N;
  cin >> K;
  cin >> X;
  S.resize(N);
  for (int i = 0; i < N; i++)
    cin >> S[i];
  return;
}

void output()
{
  cout << ans.size() << endl;
  for (string i : ans)
    cout << i << endl;
  return;
}

int main()
{
  input();
  init();
  solve();
  output();
  return 0;
}
