#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

class EllysWhatDidYouGet
{
public:
  int getCount(int N)
  {
    int ans = 0;
    for (int x = 1; x <= 50; x++)
      for (int y = 1; y <= 50; y++)
        for (int z = 1; z <= 50; z++)
        {
          int num = (1 * x + y) * z;
          int sum = 0;
          while (num)
          {
            sum += num % 10;
            num /= 10;
          }
          bool ok = true;
          for (int i = 1; i <= N; i++)
          {
            num = (i * x + y) * z;
            int t = 0;
            while (num)
            {
              t += num % 10;
              num /= 10;
            }
            if (sum != t)
              ok = false;
          }
          if (ok)
            ans++;
        }
    return ans;
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
    int Arg0 = 9;
    int Arg1 = 952;
    verify_case(0, Arg1, getCount(Arg0));
  }
  void test_case_1()
  {
    int Arg0 = 5;
    int Arg1 = 3515;
    verify_case(1, Arg1, getCount(Arg0));
  }
  void test_case_2()
  {
    int Arg0 = 13;
    int Arg1 = 456;
    verify_case(2, Arg1, getCount(Arg0));
  }
  void test_case_3()
  {
    int Arg0 = 42;
    int Arg1 = 149;
    verify_case(3, Arg1, getCount(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main()
{
  EllysWhatDidYouGet ___test;
  ___test.run_test(-1);
  return 0;
}
// END CUT HERE
