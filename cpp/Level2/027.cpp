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

/*********************************************************************************************************************************************************
 * Problem 27 「二次式素数」 †                                                                                                                                  *
 *                                                                                                                                                       *
 * オイラーは以下の二次式を考案している:                                                                                                                                   *
 * n2 + n + 41.                                                                                                                                          *
 *                                                                                                                                                       *
 * この式は, n を0から39までの連続する整数としたときに40個の素数を生成する. しかし, n = 40 のとき 402 + 40 + 41 = 40(40 + 1) + 41 となり41で割り切れる. また, n = 41 のときは 412 + 41 + 41 であり明らかに41で割り切れる. *
 *                                                                                                                                                       *
 * 計算機を用いて, 二次式 n2 - 79n + 1601 という式が発見できた. これは n = 0 から 79 の連続する整数で80個の素数を生成する. 係数の積は, -79 × 1601 で -126479である.                                         *
 *                                                                                                                                                       *
 * さて, |a| < 1000, |b| ≤ 1000 として以下の二次式を考える (ここで |a| は絶対値): 例えば |11| = 11 |-4| = 4である.                                                                   *
 * n2 + an + b                                                                                                                                           *
 *                                                                                                                                                       *
 * n = 0 から始めて連続する整数で素数を生成したときに最長の長さとなる上の二次式の, 係数 a, b の積を答えよ.                                                                                           *
 *********************************************************************************************************************************************************/

signed main() {
  int MAX = 10000000;
  vector<bool> prime(MAX, true);
  prime[0] = prime[1] = false;
  for(int i = 2; i < MAX; i++){
    if(prime[i] == false) continue;
    for(int j = 2; i*j < MAX; j++){
      prime[i*j] = false;
    }
  }

  MAX = 0;
  pair<int, int> ans;
  for(int i = -1000; i <= 1000; i++){
    for(int j = -1000; j <= 1000; j++) {
      int n = 0;
      while(1){
        if(n*n+i*n+j < 0) break;
        if(prime[n*n+i*n+j] == false) break;
        n++;
      }
      if(MAX < n){
        MAX = n;
        ans = make_pair(i, j);
      }
    }
  }

  cout << ans.first*ans.second << endl;

  return 0;
}
