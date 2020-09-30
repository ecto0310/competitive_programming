#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

class ThreeNeighbors
{
public:
  vector<string> construct(int N)
  {
    vector<string> ans(50, string(50, '.'));
    for (int i = 0; i < 12; i++)
      for (int j = 0; j < 12; j++)
      {
        if (1 <= N && N != 2)
          ans[i * 4][j * 4 + 1] = 'X';
        if (1 <= N)
          ans[i * 4 + 1][j * 4] = 'X';
        if (1 <= N)
          ans[i * 4 + 1][j * 4 + 1] = 'X';
        if (2 <= N)
          ans[i * 4 + 1][j * 4 + 2] = 'X';
        if (4 <= N)
          ans[i * 4 + 2][j * 4 + 1] = 'X';
        N -= 4;
      }
    return ans;
  }

  // BEGIN CUT HERE
public:
  void
  run_test(int Case)
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
  void verify_case(int Case, const vector<string> &Expected, const vector<string> &Received)
  {
    cerr << "Test Case #" << Case << "...";
    if (Expected == Received)
      cerr << "PASSED" << endl;
    else
    {
      cerr << "FAILED" << endl;
      cerr << "\tExpected: " << print_array(Expected) << endl;
      cerr << "\tReceived: " << print_array(Received) << endl;
    }
  }
  void test_case_0()
  {
    int Arg0 = 2;
    string Arr1[] = {".....", ".XX..", ".X.X.", ".X...", "....."};
    vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(0, Arg1, construct(Arg0));
  }
  void test_case_1()
  {
    int Arg0 = 6;
    string Arr1[] = {"........", ".XXX..X.", "..X..X..", "..X..X..", "..X...X.", "........"};
    vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(1, Arg1, construct(Arg0));
  }
  void test_case_2()
  {
    int Arg0 = 1;
    string Arr1[] = {"XXXX", "XXXX", ".XXX"};
    vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(2, Arg1, construct(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main()
{
  ThreeNeighbors ___test;
  ___test.run_test(-1);
  return 0;
}
// END CUT HERE
