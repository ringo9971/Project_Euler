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

/*********************************************************************************
 * Problem 15 「格子経路」 †                                                           *
 *                                                                                     *
 * 2×2 のマス目の左上からスタートした場合, 引き返しなしで右下にいくルートは 6 つある. *
 *                                                                                     *
 * では, 20×20 のマス目ではいくつのルートがあるか.                                     *
 ********************************************************************/

signed main() {
  int N = 20;

  vector<vector<int>> dp(N+1, vector<int>(N+1));
  dp[0][0] = 1;
  REP(i, N+1) REP(j, N+1){
    if(i-1 >= 0) dp[i][j] += dp[i-1][j];
    if(j-1 >= 0) dp[i][j] += dp[i][j-1];
  }

  cout << dp[N][N] << endl;

  return 0;
}
