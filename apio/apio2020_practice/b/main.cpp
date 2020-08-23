// URL: *
// Date: Mon, 10 Aug 2020 15:57:18 +0900
// Language: C++11 (G++)
#include <bits/stdc++.h>
#include "party.h"
using namespace std;
using i64 = long long;
#define endl "\n"

int findUnusualGuest(int N, int M, int Q)
{
  vector<int> query;
  for (i64 i = 0; i < N + M; i++)
    query.push_back(i);
  vector<int> res = ask(query);
  if (res.size() != N + M)
  {
    for (i64 i = 0; i < N + M; i++)
      if (find(res.begin(), res.end(), i) == res.end())
        return i;
  }
  i64 ok, ng;
  if (N < M)
  {
    ok = 0;
    ng = N;
  }
  else
  {
    ok = N;
    ng = N + M;
  }
  while (ng != ok)
  {
    i64 mid = (ok + ng) / 2;
    query.clear();
    for (i64 i = ok; i <= mid; i++)
      query.push_back(i);
    vector<int> res = ask(query);
    if (res.size() == mid - ok + 1)
      ok = mid + 1;
    else
      ng = mid;
  }
  return ng;
}
