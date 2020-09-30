#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

class EllysDifferentPrimes
{
  bool prime(int n)
  {
    if (n <= 1)
      return false;
    int s = sqrt(n);
    for (int i = 2; i <= s; i++)
      if (n % i == 0)
        return false;
    int bit = 0;
    while (n)
    {
      if (bit & (1 << (n % 10)))
        return false;
      bit |= (1 << (n % 10));
      n /= 10;
    }
    return true;
  }

public:
  int getClosest(int N)
  {
    for (int i = 0;; i++)
    {
      if (prime(N - i))
        return N - i;
      if (prime(N + i))
        return N + i;
    }
    return 2;
  }

  // BEGIN CUT HERE
public:
  void run_test(int Case)
  {
    if ((Case == -1) || (Case == 0))
      test_case_0();
    if ((Case == -1) || (Case == 1))
      test_case_1();
    if ((Case == -1) || (Case == 2))
      test_case_2();
    if ((Case == -1) || (Case == 3))
      test_case_3();
  }

private:
  template <typename T>
  string print_array(const vector<T> &V)
  {
    ostringstream os;
    os << "{ ";
    for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter)
      os << '\"' << *iter << "\",";
    os << " }";
    return os.str();
  }
  void verify_case(int Case, const int &Expected, const int &Received)
  {
    cerr << "Test Case #" << Case << "...";
    if (Expected == Received)
      cerr << "PASSED" << endl;
    else
    {
      cerr << "FAILED" << endl;
      cerr << "\tExpected: \"" << Expected << '\"' << endl;
      cerr << "\tReceived: \"" << Received << '\"' << endl;
    }
  }
  void test_case_0()
  {
    int Arg0 = 100;
    int Arg1 = 97;
    verify_case(0, Arg1, getClosest(Arg0));
  }
  void test_case_1()
  {
    int Arg0 = 123457;
    int Arg1 = 123457;
    verify_case(1, Arg1, getClosest(Arg0));
  }
  void test_case_2()
  {
    int Arg0 = 6661337;
    int Arg1 = 6701459;
    verify_case(2, Arg1, getClosest(Arg0));
  }
  void test_case_3()
  {
    int Arg0 = 42424242;
    int Arg1 = 42398701;
    verify_case(3, Arg1, getClosest(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main()
{
  EllysDifferentPrimes ___test;
  ___test.run_test(-1);
  return 0;
}
// END CUT HERE
