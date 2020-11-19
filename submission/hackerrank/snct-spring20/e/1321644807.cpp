#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> X(N);
  for (i64 i = 0; i < N; i++)
    cin >> X[i];
  sort(X.begin(), X.end());
  X.erase(std::unique(X.begin(), X.end()), X.end());
  N = X.size();
  vector<i64> ans(10);
  for (i64 i = 0; i < N; i++)
  {
    string t = to_string(X[i]);
    i64 h = t[0] - '0', b = t.back() - '0';
    ans[b] = max(ans[b], ans[h] + X[i]);
  }
  cout << *max_element(ans.begin(), ans.end()) << endl;
  return 0;
}
