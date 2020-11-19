#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 N;
  string S;
  cin >> N >> S;
  i64 ans = 0;
  for (i64 i = 0; i < N; i++)
    if (S[i] == 'a' || S[i] == 'i' || S[i] == 'u' || S[i] == 'e' || S[i] == 'o')
      ans++;
  cout << ans << endl;
  return 0;
}
