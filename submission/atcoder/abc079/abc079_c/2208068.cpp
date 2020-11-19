// URL: https://atcoder.jp/contests/abc079/submissions/2208068
// Date: Thu, 15 Mar 2018 17:51:39 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  string ABCD;
  cin>> ABCD;

  string ret;
  int A,B,C,D;
  A=ABCD[0]-'1'+1;
  B=ABCD[1]-'1'+1;
  C=ABCD[2]-'1'+1;
  D=ABCD[3]-'1'+1;
  for(int i=0;i<2;i++)
  for(int j=0;j<2;j++)
  for(int k=0;k<2;k++)
  {
    int tmp=A;
    if(i==0)tmp+=B;
    else tmp-=B;
    if(j==0)tmp+=C;
    else tmp-=C;
    if(k==0)tmp+=D;
    else tmp-=D;
    if(tmp==7)ret=to_string(A)+(i?"-":"+")+to_string(B)+(j?"-":"+")+to_string(C)+(k?"-":"+")+to_string(D);
  }
  cout<< ret<<"=7"<< endl;

  return 0;
}
