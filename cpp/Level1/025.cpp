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


signed main() {
  int N = 1000;

  vector<int> ppp(1002);
  vector<int>  pp(1002);
  vector<int>   p(1002);
  
  int num = 2;
  ppp[0] = 1; pp[0] = 1;
  while(num++){
    int next = 0;
    REP(i, 1000){
      p[i] = pp[i]+ppp[i]+next;
      next = 0;
      if(p[i] > 10000000000){
        next = p[i]/10000000000;
        p[i] %= 10000000000;
      }
    }
    ppp = pp;
    pp = p;

    if(p[99] > 999999999) break;
  }

  cout << num << endl;

  return 0;
}
