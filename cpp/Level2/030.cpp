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
#include <bitset>
#include <complex>
#include <functional>

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
/* const int MOD = 1000000007; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;

/*****************************************************************
 * Problem 30 「各桁の5乗」 †                                          *
 *                                                               *
 * 驚くべきことに, 各桁を4乗した数の和が元の数と一致する数は3つしかない.                         *
 *                                                               *
 * 1634 = 14 + 64 + 34 + 44                                      *
 * 8208 = 84 + 24 + 04 + 84                                      *
 * 9474 = 94 + 44 + 74 + 44                                      *
 *                                                               *
 * ただし, 1=14は含まないものとする. この数たちの和は 1634 + 8208 + 9474 = 19316 である. *
 *                                                               *
 * 各桁を5乗した数の和が元の数と一致するような数の総和を求めよ.                               *
 *****************************************************************/

bool ok(int n){
  int cur = n;
  int sum = 0;
  while(cur > 0){
    sum += pow(cur%10, 5);
    cur /= 10;
  }
  return sum == n;
}

signed main() {
  int MAX = 7*pow(9, 5);

  int ans = 0;
  for(int i = 2; i < MAX; i++){
    if(ok(i)) ans += i;
  }
   
  cout << ans << endl;

  return 0;
}
