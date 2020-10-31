#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <complex>
#include <functional>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <random>
#include <chrono>

/* #include <atcoder/all> */
/* using namespace atcoder; */
using namespace std;

void debug_out(){ cout << "\n"; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << H << " ";
  debug_out(T...);
}
#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll MOD = 1000000007;
/* const ll MOD = 998244353; */
const ll INF = (1<<30)-1;
const ll INFLL = 1ll<<60;
const double PI = acos(-1);

struct INIT { INIT(){
  cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;

/************************************************************************************************************************************************
 * Problem 33 「桁消去分数」 †                                                                                                                         *
 *                                                                                                                                              *
 * 49/98は面白い分数である.「分子と分母からそれぞれ9を取り除くと, 49/98 = 4/8 となり, 簡単な形にすることができる」と経験の浅い数学者が誤って思い込んでしまうかもしれないからである. (方法は正しくないが，49/98の場合にはたまたま正しい約分になってしまう．) *
 *                                                                                                                                              *
 * 我々は 30/50 = 3/5 のようなタイプは自明な例だとする.                                                                                                            *
 *                                                                                                                                              *
 * このような分数のうち, 1より小さく分子・分母がともに2桁の数になるような自明でないものは, 4個ある.                                                                                         *
 *                                                                                                                                              *
 * その4個の分数の積が約分された形で与えられたとき, 分母の値を答えよ.                                                                                                          *
 ************************************************************************************************************************************************/


signed main() {
  int ans = 1;
  for(int i = 10; i < 100; i++) for(int j = i+1; j < 100; j++){
    if(j%10 == 0) continue;

    int a = i/10, b = i%10;
    int c = j/10, d = j%10;
    for(int k = 1; k < 10; k++){
      if((k == a || k == b) && (k == c || k == d)){
        int e = (k == a)? b : a;
        int f = (k == c)? d : c;

        if(i*f == j*e){
          ans *= j;
          ans /= gcd(ans, i);
        }
      }
    }
  }

  cout << ans << "\n";

  return 0;
}
