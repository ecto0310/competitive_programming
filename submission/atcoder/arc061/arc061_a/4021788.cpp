// URL: https://atcoder.jp/contests/arc061/submissions/4021788
// Date: Wed, 16 Jan 2019 02:02:33 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  string S;
  cin >> S;
  long long ans = 0;
  queue<pair<long long, string>> q;
  q.push({0, S});
  while (q.size())
  {
    pair<long long, string> p = q.front();
    q.pop();
    int size = p.second.size();
    if (size == 0)
    {
      ans += p.first;
      continue;
    }
    for (int i = 1; i <= size; i++)
      q.push({p.first + stoll(p.second.substr(0, i)), p.second.substr(i, size - i)});
  }
  cout << ans << endl;

  return 0;
}
