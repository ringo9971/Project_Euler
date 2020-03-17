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

/***************************************************
 * Problem 28 「螺旋状に並んだ数の対角線」 †                     *
 *                                                 *
 * 1から初めて右方向に進み時計回りに数字を増やしていき, 5×5の螺旋が以下のように生成される: *
 * 21	22	23	24	25                                  *
 * 20	7	8	9	10                                     *
 * 19	6	1	2	11                                     *
 * 18	5	4	3	12                                     *
 * 17	16	15	14	13                                  *
 *                                                 *
 * 両対角線上の数字の合計は101であることが確かめられる.                    *
 *                                                 *
 * 1001×1001の螺旋を同じ方法で生成したとき, 対角線上の数字の和はいくつか?       *
 ***************************************************/

signed main() {
  int N = 1001;

  int ans = 1;
  REP(i, N/2){
    int j = i*2+3;
    ans += 4*j*j-(j-1)*6;
  }

  cout << ans << endl;

  return 0;
}
