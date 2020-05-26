// URL: https://atcoder.jp/contests/agc031/submissions/4600257
// Date: Sat, 16 Mar 2019 22:01:38 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
  int N;
  cin >> N;
  vector<int> C;
  int size = 0;
  for (int i = 0; i < N; i++)
  {
    int tmp;
    cin >> tmp;
    if (size == 0 || C[size - 1] != tmp)
    {
      C.push_back(tmp);
      size++;
    }
  }
  vector<int> cnt(2e5 + 1, 0);
  long long ans = 0;
  for (int i : C)
  {
    int t = ans;
    ans = (ans + cnt[i]) % MOD;
    cnt[i] = (cnt[i] + t + 1) % MOD;
  }
  cout << (ans + 1) % MOD << endl;

  return 0;
}
