// URL: https://atcoder.jp/contests/future-meets-you-contest-2018-open/submissions/3286488
// Date: Sat, 29 Sep 2018 14:09:13 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
using namespace std;


int main()
{
  int n,k;
  cin>>n>>k;
  vector<int> a(n),dif(n);
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    dif[i]=a[i]-i-1;
  }
  for(int cnt=0;cnt<k;cnt++)
  {
    int mi=min_element(dif.begin(), dif.end())-dif.begin();
    int ma=max_element(dif.begin(), dif.end())-dif.begin();
    if(dif[mi]>0)cout<<"!"<< 1<<" "<<2<<" "<<3<<" "<<4<<" "<< 0<< endl;
    else
    {
      int v=min({abs(dif[mi]),abs(dif[ma]),abs(a[ma]-v)});
      cout<< ma+1<<" "<< ma+1<<" "<<mi+1<<" "<<mi+1<<" "<<v << endl;
      dif[ma]-=v;
      dif[mi]+=v;
      a[ma]-=v;
      a[mi]+=v;
    }
  }
}
