#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

class AveragePrice
{
public:
  double nonDuplicatedAverage(vector<int> prices)
  {
    i64 sum = 0;
    set<i64> s;
    for (int i : prices)
      s.insert(i);
    for (i64 i : s)
      sum += i;
    return (double)sum / s.size();
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
  void verify_case(int Case, const double &Expected, const double &Received)
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
    int Arr0[] = {10, 20, 10};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    double Arg1 = 15.0;
    verify_case(0, Arg1, nonDuplicatedAverage(Arg0));
  }
  void test_case_1()
  {
    int Arr0[] = {1, 2, 3, 4, 5};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    double Arg1 = 3.0;
    verify_case(1, Arg1, nonDuplicatedAverage(Arg0));
  }
  void test_case_2()
  {
    int Arr0[] = {10, 10, 10, 10, 10, 10};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    double Arg1 = 10.0;
    verify_case(2, Arg1, nonDuplicatedAverage(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main()
{
  AveragePrice ___test;
  ___test.run_test(-1);
  return 0;
}
// END CUT HERE
