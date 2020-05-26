// URL: https://codeforces.com/contest/1263/submission/65975712
// Date: Sat, 30 Nov 2019 00:27:06 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct UnionFind
{
  vector<int> data;
  UnionFind(int size) : data(size, -1) {}
  bool unionSet(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x != y)
    {
      if (data[y] < data[x])
        swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y)
  {
    return root(x) == root(y);
  }
  int root(int x)
  {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x)
  {
    return -data[root(x)];
  }
};

int main()
{
  i64 n;
  cin >> n;
  vector<string> s(n);
  for (i64 i = 0; i < n; i++)
    cin >> s[i];
  UnionFind uf(n + 26);
  for (i64 i = 0; i < n; i++)
    for (char j : s[i])
      uf.unionSet(i, n + j - 'a');
  set<i64> se;
  for (i64 i = 0; i < n; i++)
    se.insert(uf.root(i));
  cout << se.size() << endl;
  return 0;
}
