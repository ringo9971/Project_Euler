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

/**************************************************************************************  * Problem 26 「逆数の循環節 その1」 †                                                          *
 *                                                                                              *
 * 単位分数とは分子が1の分数である. 分母が2から10の単位分数を10進数で表記すると次のようになる. *
 *                                                                                              *
 * 1/2 = 0.5                                                                                    *
 * 1/3 = 0.(3)                                                                                  *
 * 1/4 = 0.25                                                                                   *
 * 1/5 = 0.2                                                                                    *
 * 1/6 = 0.1(6)                                                                                 *
 * 1/7 = 0.(142857)                                                                             *
 * 1/8 = 0.125                                                                                  *
 * 1/9 = 0.(1)                                                                                  *
 * 1/10 = 0.1                                                                                   *
 *                                                                                              *
 * 0.1(6)は 0.166666... という数字であり, 1桁の循環節を持つ. 1/7 の循環節は6桁ある.             *
 *                                                                                              *
 * d < 1000 なる 1/d の中で小数部の循環節が最も長くなるような d を求めよ.                       *
 **********************************************************************/

signed main() {
  int N = 23;

  pair<int, int> ans = make_pair(0, 0);
  FOR(i, 2, N+1){
    int cur = i;
    int a = 0, b = 0;
    while(cur%2 == 0){
      a++; cur /= 2;
    }
    while(cur%5 == 0){
      b++; cur /= 5;
    }

    int m = i/pow(2, a)/pow(5, b);
    int cnt = 1;
    if(m == 1) continue;
    while((int)pow(10, cnt)%m != 1) cnt++;
    if(ans.second < cnt){
      ans.second = cnt;
      ans.first = i;
    }
    cout << i << " " << cnt << endl;
  }

  cout << ans.first << " " << ans.second << endl;

  return 0;
}
