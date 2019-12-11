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

/********************************************************************************
 * Problem 20 「各位の数字の和 2」 †                                                     *
 *                                                                                       *
 * n × (n - 1) × ... × 3 × 2 × 1 を n! と表す.                                           *
 *                                                                                       *
 * 例えば, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800 となる.                              *
 * この数の各桁の合計は 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27 である.                           *
 *                                                                                       *
 * では, 100! の各位の数字の和を求めよ.                                                  *
 *                                                                                       *
 * 注: Problem 16 も各位の数字の和に関する問題です。解いていない方は解いてみてください。 *
 *****************************************************/

signed main() {
  int N = 100;

  vector<int> num(100);
  num[0] = 1;
  while(N){
    RREP(i, 100){
      num[i] *= N;
      if(num[i] > 1000000000){
        num[i+1] += num[i]/1000000000;
        num[i] %= 1000000000;
      }
    }
    N--;
  }

  int ans = 0;
  RREP(i, 100){
    while(num[i]){
      ans += num[i]%10;
      num[i] /= 10;
    }
  }

  cout << ans << endl;

  return 0;
}
