// URL: https://atcoder.jp/contests/past202005-open/submissions/14062158
// Date: Sat, 06 Jun 2020 18:05:11 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<queue<pair<i64, i64>>> T1(N), T2(N);
  vector<i64> K1(N), K2(N);
  vector<set<i64>> buy(N);
  for (i64 i = 0; i < N; i++)
  {
    cin >> K1[i];
    K2[i] = K1[i];
    for (i64 j = 0; j < K1[i]; j++)
    {
      i64 tmp;
      cin >> tmp;
      T1[i].push({tmp, j});
      T2[i].push({tmp, j});
    }
  }
  priority_queue<pair<pair<i64, i64>, i64>> que1, que2;
  vector<pair<i64, i64>> now1(N);
  for (i64 i = 0; i < N; i++)
  {
    que1.push({T1[i].front(), i});
    now1[i] = T1[i].front();
    K1[i]--;
    T1[i].pop();
    que2.push({T2[i].front(), i});
    K2[i]--;
    T2[i].pop();
    que2.push({T2[i].front(), i});
    K2[i]--;
    T2[i].pop();
  }
  i64 M;
  cin >> M;
  for (i64 i = 0; i < M; i++)
  {
    i64 a;
    cin >> a;
    if (a == 1)
    {
      pair<pair<i64, i64>, i64> p = que1.top();
      que1.pop();
      while (buy[p.second].count(p.first.second))
      {
        p = que1.top();
        que1.pop();
      }
      cout << p.first.first << endl;
      buy[p.second].insert(p.first.second);
      if (0 < K1[p.second])
      {
        while (0 < K1[p.second] && buy[p.second].count(T1[p.second].front().second))
        {
          T1[p.second].pop();
          K1[p.second]--;
        }
        que1.push({T1[p.second].front(), p.second});
        now1[p.second] = T1[p.second].front();
        K1[p.second]--;
        T1[p.second].pop();
      }
      if (0 < K2[p.second])
      {
        while (0 < K2[p.second] && buy[p.second].count(T2[p.second].front().second))
        {
          T2[p.second].pop();
          K2[p.second]--;
        }
        que2.push({T2[p.second].front(), p.second});
        K2[p.second]--;
        T2[p.second].pop();
      }
    }
    else
    {
      pair<pair<i64, i64>, i64> p = que2.top();
      que2.pop();
      while (buy[p.second].count(p.first.second))
      {
        p = que2.top();
        que2.pop();
      }
      cout << p.first.first << endl;
      buy[p.second].insert(p.first.second);
      if (now1[p.second] == p.first && 0 < K1[p.second])
      {
        while (0 < K1[p.second] && buy[p.second].count(T1[p.second].front().second))
        {
          T1[p.second].pop();
          K1[p.second]--;
        }
        que1.push({T1[p.second].front(), p.second});
        now1[p.second] = T1[p.second].front();
        K1[p.second]--;
        T1[p.second].pop();
      }
      if (0 < K2[p.second])
      {
        while (0 < K2[p.second] && buy[p.second].count(T2[p.second].front().second))
        {
          T2[p.second].pop();
          K2[p.second]--;
        }
        que2.push({T2[p.second].front(), p.second});
        K2[p.second]--;
        T2[p.second].pop();
      }
    }
  }
  return 0;
}
