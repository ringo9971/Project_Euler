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

/***********************************************************************************************************
 * Problem 12 「高度整除三角数」 †                                                                                  *
 *                                                                                                                  *
 * 三角数の数列は自然数の和で表わされ, 7番目の三角数は 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28 である. 三角数の最初の10項は: *
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...                                                                         *
 *                                                                                                                  *
 * となる.                                                                                                          *
 *                                                                                                                  *
 * 最初の7項について, その約数を列挙すると, 以下のとおり.                                                           *
 *                                                                                                                  *
 * 1: 1                                                                                                             *
 * 3: 1,3                                                                                                           *
 * 6: 1,2,3,6                                                                                                       *
 * 10: 1,2,5,10                                                                                                     *
 * 15: 1,3,5,15                                                                                                     *
 * 21: 1,3,7,21                                                                                                     *
 * 28: 1,2,4,7,14,28                                                                                                *
 *                                                                                                                  *
 * これから, 7番目の三角数である28は, 5個より多く約数をもつ最初の三角数であることが分かる.                         *
 *                                                                                                                  *
 * では, 500個より多く約数をもつ最初の三角数はいくつか.                                                             *
 *********************************************************************************************/

signed main() {
  int N = 500;

  int i = 1;
  while(++i){
    int cur = i*(i+1)/2;

    map<int, int> m;
    while(cur%2 == 0){
      m[2]++;
      cur /= 2;
    }
    for(int j = 3; j <= cur; j += 2){
      while(cur%j == 0){
        m[j]++;
        cur /= j;
      }
    }

    int res = 1;
    for(pair<int, int> p : m){
      res *= p.second+1;
    }
    if(res > N){
      cout << ((i+1)*i/2) << endl;
      break;
    }
  }

  return 0;
}
