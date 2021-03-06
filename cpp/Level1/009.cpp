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

/************************************************************************************
 * Problem 9 「特別なピタゴラス数」 †                                                          *
 *                                                                                             *
 * ピタゴラス数(ピタゴラスの定理を満たす自然数)とは a < b < c で以下の式を満たす数の組である. *
 * a2 + b2 = c2                                                                                *
 *                                                                                             *
 * 例えば, 32 + 42 = 9 + 16 = 25 = 52 である.                                                  *
 *                                                                                             *
 * a + b + c = 1000 となるピタゴラスの三つ組が一つだけ存在する.                                *
 * これらの積 abc を計算しなさい.                                                              *
 ***********************************************************************************/

signed main() {
  int N = 1000;

  FOR(i, 1, N-2) FOR(j, i+1, N-1){
    int k = N-i-j;
    if(k < 1) break;
    if(i*i+j*j == k*k) cout << i*j*k << endl;
  }

  return 0;
}
