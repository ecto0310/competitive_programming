// URL: https://atcoder.jp/contests/abc091/submissions/2224989
// Date: Sun, 18 Mar 2018 00:38:23 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

bool redsort(const pair<int, int>& ab, const pair<int, int>& cd) {
	if(ab.second>cd.second)return true;
	return false;
}

bool blusort(const pair<int, int>& ab, const pair<int, int>& cd) {
	if(ab.first<cd.first)return true;
	return false;
}

int main()
{
  int N;
  vector<pair<int,int>> red;
  vector<pair<int,int>> blu;
  cin>> N;
  for(int i=0;i<N;i++)
  {
    int a,b;
    cin>> a>> b;
    red.push_back(pair<int,int>(a,b));
  }
  for(int i=0;i<N;i++)
  {
    int c,d;
    cin>> c>> d;
    blu.push_back(pair<int,int>(c,d));
  }

  int ret=0;
  sort(begin(red),end(red),redsort);
  sort(begin(blu),end(blu),blusort);
  for(int i=0;i<N;i++)cerr<< ":"<< red[i].first<< " "<< red[i].second<< " "<< blu[i].first<< " "<< blu[i].second<< endl;
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<red.size();j++)
    {
      if(blu[i].first>red[j].first&&blu[i].second>red[j].second)
      {
        red.erase(red.begin()+j);
        ret++;
        break;
      }
    }
  }
  cout<< ret<< endl;

  return 0;
}
