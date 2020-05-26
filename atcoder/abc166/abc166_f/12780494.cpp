// URL: https://atcoder.jp/contests/abc166/submissions/12780494
// Date: Sun, 03 May 2020 22:56:43 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, A, B, C;
  cin >> N >> A >> B >> C;
  vector<string> s(N);
  for (i64 i = 0; i < N; i++)
    cin >> s[i];
  string ans;
  for (i64 i = 0; i < N; i++)
  {
    if (s[i] == "AB")
    {
      if (A == 0 && B == 0)
      {
        cout << "No" << endl;
        return 0;
      }
      else if (A == B)
      {
        if (s[i + 1] == "AB" || s[i + 1] == "AC")
        {
          A++;
          B--;
          ans += 'A';
        }
        else
        {
          B++;
          A--;
          ans += 'B';
        }
      }
      else if (B < A)
      {
        B++;
        A--;
        ans += 'B';
      }
      else
      {
        A++;
        B--;
        ans += 'A';
      }
    }
    else if (s[i] == "BC")
    {
      if (C == 0 && B == 0)
      {
        cout << "No" << endl;
        return 0;
      }
      else if (C == B)
      {
        if (s[i + 1] == "BC" || s[i + 1] == "AC")
        {
          C++;
          B--;
          ans += 'C';
        }
        else
        {
          B++;
          C--;
          ans += 'B';
        }
      }
      else if (B < C)
      {
        B++;
        C--;
        ans += 'B';
      }
      else
      {
        C++;
        B--;
        ans += 'C';
      }
    }
    else
    {
      if (C == 0 && A == 0)
      {
        cout << "No" << endl;
        return 0;
      }
      else if (C == A)
      {
        if (s[i + 1] == "BC" || s[i + 1] == "AC")
        {
          C++;
          A--;
          ans += 'C';
        }
        else
        {
          A++;
          C--;
          ans += 'A';
        }
      }
      else if (A < C)
      {
        A++;
        C--;
        ans += 'A';
      }
      else
      {
        C++;
        A--;
        ans += 'C';
      }
    }
  }
  cout << "Yes" << endl;
  for (char i : ans)
    cout << i << endl;
  return 0;
}
