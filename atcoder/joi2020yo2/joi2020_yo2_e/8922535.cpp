// URL: https://atcoder.jp/contests/joi2020yo2/submissions/8922535
// Date: Thu, 12 Dec 2019 18:17:20 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 MOD = 1e9 + 7;

vector<i64> expr(string &s, int &i);
vector<i64> term(string &s, int &i);
vector<i64> factor(string &s, int &i);
vector<i64> number(string &s, int &i);

vector<i64> expr(string &s, int &i)
{
  vector<i64> val = term(s, i);
  while (s[i] == '+' || s[i] == '-')
  {
    char op = s[i];
    i++;
    vector<i64> val2 = term(s, i), tmp(3);
    if (op == '+')
    {
      tmp[0] = (val[0] * val2[0] + val[0] * val2[1] + val[1] * val2[0]) % MOD;
      tmp[1] = (val[1] * val2[1] + val[1] * val2[2] + val[2] * val2[1]) % MOD;
      tmp[2] = (val[2] * val2[2] + val[0] * val2[2] + val[2] * val2[0]) % MOD;
    }
    else
    {
      tmp[0] = (val[0] * val2[0] + val[0] * val2[2] + val[2] * val2[0]) % MOD;
      tmp[1] = (val[1] * val2[1] + val[0] * val2[1] + val[1] * val2[0]) % MOD;
      tmp[2] = (val[2] * val2[2] + val[1] * val2[2] + val[2] * val2[1]) % MOD;
      ;
    }
    val = tmp;
  }
  return val;
}

vector<i64> term(string &s, int &i)
{
  vector<i64> val = factor(s, i);
  while (s[i] == '*' || s[i] == '/')
  {
    char op = s[i];
    i++;
    vector<i64> val2 = factor(s, i), tmp(3);
    if (op == '*')
    {
      tmp[0] = (val[0] * val2[0] + val[1] * val2[2] + val[2] * val2[1]) % MOD;
      tmp[1] = (val[1] * val2[1] + val[0] * val2[2] + val[2] * val2[0]) % MOD;
      tmp[2] = (val[2] * val2[2] + val[0] * val2[1] + val[1] * val2[0]) % MOD;
    }
    val = tmp;
  }
  return val;
}

vector<i64> factor(string &s, int &i)
{
  if (isdigit(s[i]))
    return number(s, i);
  i++;
  vector<i64> ret = expr(s, i);
  i++;
  return ret;
}

vector<i64> number(string &s, int &i)
{
  i++;
  if (s[i - 1] == '0')
    return {1, 0, 0};
  if (s[i - 1] == '1')
    return {0, 1, 0};
  if (s[i - 1] == '2')
    return {0, 0, 1};
  return {1, 1, 1};
}

int main()
{
  i64 n;
  string s, e;
  cin >> n >> s >> e;
  for (i64 i = 0; i < n; i++)
    if (s[i] == 'R')
      s[i] = '0';
    else if (s[i] == 'S')
      s[i] = '1';
    else if (s[i] == 'P')
      s[i] = '2';
    else if (s[i] == '?')
      s[i] = '3';
  i64 c = (e == "R" ? 0 : (e == "S" ? 1 : 2));
  int t = 0;
  vector<i64> ans = expr(s, t);
  cout << ans[c] << endl;
  return 0;
}
