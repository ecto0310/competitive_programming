// URL: https://atcoder.jp/contests/arc080/submissions/4248245
// Date: Wed, 13 Feb 2019 03:22:44 +0900
// Language: C++14 (GCC 5.4.1)
#include "bits/stdc++.h"
using namespace std;
#pragma region define/typedef
//auto
#define var auto
//a..b-1
#define FOR(i, a, b) for(var (i) = (a); (i) < (b); (i)++)
//b..a
#define FORR(i, a, b) for(var (i) = (b); (i) >= (a); (i)--)
//0..n-1
#define rep(i, n) for(var (i) = 0; (i) < (n); (i)++) 
//1..n
#define rep1(i, n) for(var (i) = 1; (i) <= (n); (i)++)
//n-1..0
#define repr(i, n) for(var (i) = (n) - 1; (i) >= 0; (i)--)
//n-1..1
#define repr1(i, n) for(var (i) = (n); (i) > 0; (i)--)
#define out(a) cout<<(a)<<endl;
#define pb(a) push_back((a))
#define mp make_pair
#define mt make_tuple
#define endl "\n";
#define outif(b, t, f) cout << ((b) ? (t) : (f)) << endl;
#define sort(vec) sort((vec).begin(), (vec).end())
typedef long long ll;
typedef unsigned int uint;
typedef vector<int> vint;
typedef vector<ll> vlong;
typedef vector<pair<int, int>> vpair;
const int MAX = 2147483647;
const int MIN = 0 - 2147483648;
const ll MAXL = 922337203685775807;
const ll MINL = 0 - 922337203685775808;
#pragma endregion
#pragma region methods/operators
ll parse(const string num) { stringstream ss; ss << num << flush; ll n; ss >> n; return n; }
string tostring(const ll n) { stringstream ss; ss << n << flush; return ss.str(); }

vector<string> split(string s, string delim) {
	vector<string> res;
	auto pos = 0;
	while (true) {
		const int found = s.find(delim, pos);
		if (found >= 0) {
			res.push_back(s.substr(pos, found - pos));
		}
		else {
			res.push_back(s.substr(pos));
			break;
		}
		pos = found + delim.size();
	}
	return res;
}

template<typename T>
string join(vector<T>& vec, string sep = " ")
{
	var size = vec.size();
	if (size == 0) return "";
	stringstream ss;
	for (int i = 0; i < size - 1; i++) {
		ss << vec[i] << sep;
	}
	ss << vec[size - 1];
	return ss.str();
}

template<typename T>
istream& operator >> (istream& is, vector<T>& vec)
{
	for (T& x : vec) is >> x;
	return is;
}

template<typename T>
void print(T t) {
	cout << t << endl;
}

ll gcd(ll a, ll b)
{
	if (a < b) gcd(b, a);
  ll r;
	while ((r = a % b)) {
		a = b;
		b = r;
	}
	return b;
}
#pragma endregion

int main()
{
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int N;
  while (cin >> N) {
    vint a(N);
    cin >> a;

    int cnt4 = 0, cntEven = 0, cntOdd = 0;

    rep(i, N)
    {
      if (a[i] % 4 == 0) cnt4++;
      else if (a[i] % 2 == 0)cntEven++;
      else cntOdd++;
    }

    var ans = false;
    if (cntEven == 0) ans =cntOdd -cnt4 <= 1;
    else ans = cnt4 >= cntOdd;
    
    print(ans ? "Yes" : "No");
  }
  return 0;
}
