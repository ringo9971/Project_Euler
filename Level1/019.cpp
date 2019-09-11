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

int year = 1901, month = 1, day = 1;
int week = 0;

void update(){
  day = 0;
  month++;
  if(month == 13){
    year++;
    month = 1;
  }
}

signed main() {

  int ans = 0;
  while(year < 2001){
    week = week+1 == 8?1:week+1;
    day++;

    if(day == 1 && week == 7) ans++;

    if(month == 2){
      if(year%4 != 0 || (year%400 != 0 && year%100 == 0 && day == 28)) update();
      else if(day == 29) update();
    }else if(month == 9 || month == 4 || month == 6 || month == 11){
      if(day == 30) update();
    }else if(day == 31) update();
  }

  cout << ans << endl;

  return 0;
}
