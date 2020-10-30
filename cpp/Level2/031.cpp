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

/*******************************************************
 * Problem 31 「硬貨の和」 †                                 *
 *                                                     *
 * イギリスでは硬貨はポンド£とペンスpがあり，一般的に流通している硬貨は以下の8種類である.       *
 *                                                     *
 * 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p). *
 *                                                     *
 * 以下の方法で£2を作ることが可能である．                                *
 *                                                     *
 * 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p           *
 *                                                     *
 * これらの硬貨を使って£2を作る方法は何通りあるか?                           *
 *******************************************************/

vector<int> v = {1, 2, 5, 10, 20, 50, 100, 200};
int memo[10][220];

int dfs(int depth, int sum){
  if(depth == v.size()){
    if(sum == 200) return 1;
    return 0;
  }

  if(memo[depth][sum] != -1) return memo[depth][sum];

  int ret = 0;
  REP(i, 201){
    if(sum+v[depth]*i > 200) break;
    ret += dfs(depth+1, sum+v[depth]*i);
  }

  return memo[depth][sum] = ret;
}

signed main() {
  REP(i, 10) REP(j, 220) memo[i][j] = -1;

  cout << dfs(0, 0) << "\n";

  return 0;
}
