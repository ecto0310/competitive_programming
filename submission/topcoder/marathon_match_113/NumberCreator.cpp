#include <bits/stdc++.h>
#include "BigInt.cpp"

using namespace std;
using i64 = long long;

const i64 CYCLE_PER_SEC = 2500000000;

i64 getCycle()
{
  unsigned int low, high;
  __asm__ volatile("rdtsc"
                   : "=a"(low), "=d"(high));
  return ((i64)low) | ((i64)high << 32);
}

class NumberCreator
{
public:
  i64 start;
  vector<string> findSolution(int Num0, int Num1, string T)
  {
    start = getCycle();
    BigInt fin(T);
    BigInt dec(2);
    BigInt mcnt(10000), mdec;
    for (; (double)(getCycle() - start) / CYCLE_PER_SEC < 9.5; dec = dec + 1)
    {
      BigInt cnt = dec;
      BigInt tmp = fin;
      while (BigInt(0) < tmp)
      {

        if (!(tmp % dec == BigInt(0)))
          cnt = cnt + 1;
        tmp = tmp / dec;
        cnt = cnt + 1;
      }
      if (cnt < mcnt)
      {
        mcnt = cnt;
        mdec = dec;
      }
    }
    vector<string> moves;
    moves.push_back("0 / 0");
    for (BigInt i(2); i <= mdec; i = i + 1)
      moves.push_back(i.toString() + " + 2");
    vector<string> dig;
    while (BigInt(0) < fin)
    {
      dig.push_back((fin % mdec).toString());
      fin = fin / mdec;
    }
    reverse(dig.begin(), dig.end());
    BigInt now = mdec + 2;
    for (i64 i = 0; i < dig.size(); i++)
    {
      if (i == 0)
      {
        moves.push_back((BigInt(dig[i]) + 1).toString() + " * " + (mdec + 1).toString());
      }
      else
      {
        if (dig[i] != "0")
        {
          moves.push_back(now.toString() + " + " + (BigInt(dig[i]) + 1).toString());
          now = now + 1;
        }
        if (i + 1 != dig.size())
        {
          moves.push_back(now.toString() + " * " + (mdec + 1).toString());
          now = now + 1;
        }
      }
    }
    return moves;
  }
};

int main()
{
  NumberCreator nc;
  int Num0;
  int Num1;
  string T;
  cin >> Num0;
  cin >> Num1;
  cin >> T;

  vector<string> ret = nc.findSolution(Num0, Num1, T);
  cout << ret.size() << endl;
  for (int i = 0; i < (int)ret.size(); ++i)
    cout << ret[i] << endl;
  cout.flush();
}
