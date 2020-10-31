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

bool is_prime(int n){
  if(n < 2) return false;
  if(n == 2) return true;
  if(n%2 == 0) return false;
  for(int i = 3; i*i <= n; i += 2){
    if(n%i == 0) return false;
  }
  return true;
}

bool comp(int i, int j){
  return i > j;
}

signed main() {
  int ans = 0;
   
  vector<int> v = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  RREP(i, 10){
    sort(ALL(v));
    v.pop_back();
    reverse(ALL(v));

    do{
      int n = 0;
      REP(i, v.size()){
        n = n*10+v[i];
      }

      if(is_prime(n)){
        cout << n << "\n";
        return 0;
      }
    }while(next_permutation(ALL(v), comp));

  }

  return 0;
}
