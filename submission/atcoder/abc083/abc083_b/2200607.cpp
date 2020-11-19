// URL: https://atcoder.jp/contests/abc083/submissions/2200607
// Date: Tue, 13 Mar 2018 21:27:36 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N,A,B;
  cin>> N>> A>> B;

  int ret=0;
  for(int i=1;i<=N;i++)
  {
    cerr<< "::"<< i<< endl;
    int num=i;
    int sum=0;
    while(num)
    {
      sum+=num%10;
      num/=10;
      cerr<< ":"<< sum<< " "<< num<< endl;
    }
    if(A<=sum&&sum<=B)ret+=i;
  }
  cout<< ret<< endl;

  return 0;
}
