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

/***************************************************************************************************************************************************************************
 * Problem 18 「最大経路の和 その1」 †                                                                                                                                               *
 *                                                                                                                                                                                   *
 * 以下の三角形の頂点から下の行の隣接する数字を通って下まで移動するとき, その数値の和の最大値は23になる.                                                                             *
 * 3                                                                                                                                                                                 *
 * 7 4                                                                                                                                                                               *
 * 2 4 6                                                                                                                                                                             *
 * 8 5 9 3                                                                                                                                                                           *
 *                                                                                                                                                                                   *
 * この例では 3 + 7 + 4 + 9 = 23.                                                                                                                                                    *
 *                                                                                                                                                                                   *
 * 以下の三角形を頂点から下まで移動するとき, その最大の和を求めよ.                                                                                                                   *
 * 75                                                                                                                                                                                *
 * 95 64                                                                                                                                                                             *
 * 17 47 82                                                                                                                                                                          *
 * 18 35 87 10                                                                                                                                                                       *
 * 20 04 82 47 65                                                                                                                                                                    *
 * 19 01 23 75 03 34                                                                                                                                                                 *
 * 88 02 77 73 07 63 67                                                                                                                                                              *
 * 99 65 04 28 06 16 70 92                                                                                                                                                           *
 * 41 41 26 56 83 40 80 70 33                                                                                                                                                        *
 * 41 48 72 33 47 32 37 16 94 29                                                                                                                                                     *
 * 53 71 44 65 25 43 91 52 97 51 14                                                                                                                                                  *
 * 70 11 33 28 77 73 17 78 39 68 17 57                                                                                                                                               *
 * 91 71 52 38 17 14 91 43 58 50 27 29 48                                                                                                                                            *
 * 63 66 04 68 89 53 67 30 73 16 69 87 40 31                                                                                                                                         *
 * 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23                                                                                                                                      *
 *                                                                                                                                                                                   *
 * 注: ここではたかだか 16384 通りのルートしかないので, すべてのパターンを試すこともできる. Problem 67 は同じ問題だが100行あるので, 総当りでは解けない. もっと賢い方法が必要である. *
 ************************************************************************************************************/

signed main() {
  vector<vector<int>> vec = {
      {75},
      {95, 64},
      {17, 47, 82},
      {18, 35, 87, 10},
      {20,  4, 82, 47, 65},
      {19,  1, 23, 75,  3, 34},
      {88,  2, 77, 73,  7, 63, 67},
      {99, 65,  4, 28,  6, 16, 70, 92},
      {41, 41, 26, 56, 83, 40, 80, 70, 33},
      {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
      {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
      {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
      {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
      {63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
      { 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23}
  };

  RREP(i, vec.size()){
    REP(j, i){
      vec[i-1][j] += max(vec[i][j], vec[i][j+1]);
    }
  }

  cout << vec[0][0] << endl;

  return 0;
}
