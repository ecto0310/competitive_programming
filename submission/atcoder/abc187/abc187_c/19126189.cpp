// URL: https://atcoder.jp/contests/abc187/submissions/19126189
// Date: Sat, 02 Jan 2021 21:09:43 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<string> S(N);
  for (i64 i = 0; i < N; i++)
    cin >> S[i];
  set<string> s;
  for (i64 i = 0; i < N; i++)
    s.insert(S[i]);
  for (i64 i = 0; i < N; i++)
    if (s.count("!" + S[i]))
    {
      cout << S[i] << endl;
      return 0;
    }
  cout << "satisfiable" << endl;
  return 0;
}
