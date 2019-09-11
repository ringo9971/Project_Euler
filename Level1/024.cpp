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
  int N = 1000000;

  vector<int> vec{
      -1,
      1,
      2,
      6,
      24,
      120,
      720,
      5040,
      40320,
      362880
  };

  int num = 0;
  vector<bool> used(10, false);
  RREP(i, 10){
    int cnt = 0;
    if(vec[i] <= N){
      cnt = N/vec[i];
      N -= cnt*vec[i];
    }
    REP(i, 10){
      if(used[i] == false) cnt--;
      if(cnt == -1){
        used[i] = true;
        cout << i;
        break;
      }
    }
  }
  cout << endl;

  return 0;
}
