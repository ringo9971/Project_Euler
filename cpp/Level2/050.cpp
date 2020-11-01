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


vector<pair<bool, int>> is_prime;
vector<int> p;
void prime(int n){
  is_prime = vector<pair<bool, int>>(n, {true, 0});
  is_prime[0].first = is_prime[1].first = false;
  REP(i, n){
    if(!is_prime[i].first) continue;
    p.emplace_back(i);
    for(int j = 2; i*j < n; j++){
      is_prime[i*j].first = false;
    }
  }
}

signed main() {
  int N = 1000000;

  prime(N);

  REP(i, p.size()){
    int now = p[i];
    FOR(j, i+1, p.size()){
      now += p[j];
      if(now > N) break;

      if(is_prime[now].first){
        chmax(is_prime[now].second, j-i+1);
      }
    }
  }


  int MAX = 0;
  int ans = -1;
  REP(i, N){
    if(is_prime[i].first) if(chmax(MAX, is_prime[i].second)){
      ans = i;
    }
  }

  cout << ans << "\n";

  return 0;
}
