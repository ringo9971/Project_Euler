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

/*********************************************************************************************************************************************
 * Problem 14 「最長のコラッツ数列」 †                                                                                                                  *
 *                                                                                                                                                      *
 * 正の整数に以下の式で繰り返し生成する数列を定義する.                                                                                                  *
 *                                                                                                                                                      *
 * n → n/2 (n が偶数)                                                                                                                                   *
 *                                                                                                                                                      *
 * n → 3n + 1 (n が奇数)                                                                                                                                *
 *                                                                                                                                                      *
 * 13からはじめるとこの数列は以下のようになる.                                                                                                          *
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1                                                                                                           *
 *                                                                                                                                                      *
 * 13から1まで10個の項になる. この数列はどのような数字からはじめても最終的には 1 になると考えられているが, まだそのことは証明されていない(コラッツ問題) *
 *                                                                                                                                                      *
 * さて, 100万未満の数字の中でどの数字からはじめれば最長の数列を生成するか.                                                                             *
 *                                                                                                                                                      *
 * 注意: 数列の途中で100万以上になってもよい                                                                                                            *
 **************************************************************************************************************************************/

signed main() {
  int N = 1000000;

  pair<int, int> ans = make_pair(0, 0);
  vector<int> num(N+1, INF);
  num[1] = 1;
  FOR(i, 2, N+1){
    int cur = i;
    int cnt = 0;
    while(++cnt){
      if(cur%2 == 0){
        cur /= 2;
      }else{
        cur = 3*cur+1;
      }
      if(cur <= N && num[cur] != INF){
        num[i] = num[cur]+cnt;
        if(ans.second < num[i]){
          ans.second = num[i];
          ans.first = i;
        }
        break;
      }
    }
  }

  cout << ans.first << endl;

  return 0;
}
