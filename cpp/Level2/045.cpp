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


signed main() {

  auto f = [&](int n){
    n = 1+24*n;
    int m = sqrt(n);
    if(m*m != n) return false;
    if(m%6 == 5) return true;
    return false;
  };
  auto g = [&](int n){
    n = 1+8*n;
    int m = sqrt(n);
    if(m*m != n) return false;
    if(m%2 == 1) return true;
    return false;
  };

  for(int i = 144; ; i++){
    int n = i*(2*i-1);
    if(f(n) && g(n)){
      cout << n << "\n";
      return 0;
    }
  }

  return 0;
}
