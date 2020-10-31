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

/****************************************************************************************************
 * Problem 32 「パンデジタル積」 †                                                                           *
 *                                                                                                  *
 * すべての桁に 1 から n が一度だけ使われている数をn桁の数がパンデジタル (pandigital) であるということにしよう: 例えば5桁の数 15234 は1から5のパンデジタルである. *
 *                                                                                                  *
 * 7254 は面白い性質を持っている. 39 × 186 = 7254 と書け, 掛けられる数, 掛ける数, 積が1から9のパンデジタルとなる.                          *
 *                                                                                                  *
 * 掛けられる数/掛ける数/積が1から9のパンデジタルとなるような積の総和を求めよ.                                                         *
 *                                                                                                  *
 * HINT: いくつかの積は, 1通り以上の掛けられる数/掛ける数/積の組み合わせを持つが1回だけ数え上げよ.                                           *
 ****************************************************************************************************/


signed main() {
  int N = 9;

  set<int> ans;
  for(int a = 1; a <= N; a++) for(int b = a; a+b <= N; b++){
    for(int i = (int)pow(10, a-1); i < (int)pow(10, a); i++){
      for(int j = max(i, (int)pow(10, b-1)); j < (int)pow(10, b); j++){
        int k = i*j;
        int c = to_string(k).size();
        if(a+b+c > N) break;
        if(a+b+c == N){
          string s = to_string(i);
          string t = to_string(j);
          string u = to_string(k);
          set<char> set;
          REP(i, s.size()) set.insert(s[i]);
          REP(i, t.size()) set.insert(t[i]);
          REP(i, u.size()) set.insert(u[i]);

          if(set.size() == N && !set.count('0')){
            ans.insert(k);
          }
        }
      }
    }
  }

  int sum = 0;
  for(auto p : ans){
    sum += p;
  }

  cout << sum << "\n";

  return 0;
}
