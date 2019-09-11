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

/**************************************************************************************************************************************************************************************************************************************************************************************************************************
 * Problem 23 「非過剰数和」 †                                                                                                                                                                                                                                                                                                   *
 *                                                                                                                                                                                                                                                                                                                               *
 * 完全数とは, その数の真の約数の和がそれ自身と一致する数のことである. たとえば, 28の真の約数の和は, 1 + 2 + 4 + 7 + 14 = 28 であるので, 28は完全数である.                                                                                                                                                                       *
 *                                                                                                                                                                                                                                                                                                                               *
 * 真の約数の和がその数よりも少ないものを不足数といい, 真の約数の和がその数よりも大きいものを過剰数と呼ぶ.                                                                                                                                                                                                                       *
 *                                                                                                                                                                                                                                                                                                                               *
 * 12は, 1 + 2 + 3 + 4 + 6 = 16 となるので, 最小の過剰数である. よって2つの過剰数の和で書ける最少の数は24である. 数学的な解析により, 28123より大きい任意の整数は2つの過剰数の和で書けることが知られている. 2つの過剰数の和で表せない最大の数がこの上限よりも小さいことは分かっているのだが, この上限を減らすことが出来ていない. *
 *                                                                                                                                                                                                                                                                                                                               *
 * 2つの過剰数の和で書き表せない正の整数の総和を求めよ.                                                                                                                                                                                                                                                                          *
 ********************************************************************************************************************************************************************************************************************************************************************************************************/

signed main() {
  int N = 28123;

  vector<int> vec;

  FOR(i, 1, N+1){
    int res = 1;
    for (int j = 2; j*j <= i; j++) {
      if(i%j == 0) res += j+i/j;
      if(j*j == i) res -= j;
    }
    if(i < res) vec.push_back(i);
  }

  vector<bool> flag(N+1, false);
  REP(i, vec.size()){
    REP(j, vec.size()){
      if(vec[i]+vec[j] < N+1) flag[vec[i]+vec[j]] = true;
      else break;
    }
  }

  int ans = 0;
  REP(i, N-1) if(!flag[i]) ans += i;

  cout << ans << endl;

  return 0;
}
