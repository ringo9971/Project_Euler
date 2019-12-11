#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

// output
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
// utility
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline T chmax(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T chmin(T& a, const T b) { return a = (a > b) ? b : a; }

// type/const
#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
const int INF = 1e18;

using namespace std;

/***********************************************************************************************************************
 * Problem 4 「最大の回文積」 †                                                                                                *
 *                                                                                                                             *
 * 左右どちらから読んでも同じ値になる数を回文数という. 2桁の数の積で表される回文数のうち, 最大のものは 9009 = 91 × 99 である. *
 *                                                                                                                             *
 * では, 3桁の数の積で表される回文数の最大値を求めよ.                                                                          *
 ********************************************************************************************************/

signed main() {
  int N = 3;

  int ans = 0;
  FOR(i, pow(10, N-1), pow(10, N)) FOR(j, pow(10, N-1), pow(10, N)){
    int res = i*j;
    if(ans > res) continue;
    string s = to_string(res);
    string t = s;
    reverse(ALL(t));
    if(t == s) ans = res;
  }

  cout << ans << endl;

  return 0;
}
