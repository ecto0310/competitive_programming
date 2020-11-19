// URL: https://atcoder.jp/contests/hokudai-hitachi2018/submissions/4274523
// Date: Sat, 16 Feb 2019 13:39:31 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

struct Item
{
  int d, c;
  vector<int> v;
};

int main()
{
  int N, K;
  cin >> N >> K;
  vector<Item> item;
  for (int i = 0; i < K; i++)
  {
    int d, c;
    cin >> d >> c;
    vector<int> v(d);
    for (int j = 0; j < d; j++)
      cin >> v[j];
    item.push_back({d, c, v});
  }

  vector<Item> ans;
  int sum = 0;
  for (int i = 0; i < K; i++)
    if (0 < item[i].d && item[i].d <= 2)
      ans.push_back(item[i]);
    else
      sum += max(0, item[i].c);
  ans.push_back({0, max(1, sum), vector<int>()});
  cout << N << " " << ans.size() << endl;
  for (Item i : ans)
  {
    cout << i.d << " " << i.c;
    for (int j : i.v)
      cout << " " << j;
    cout << endl;
  }

  return 0;
}
