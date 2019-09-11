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

/*****************************************************************************************************************************************************************************
 * Problem 17 「数字の文字数」 †                                                                                                                                                     *
 *                                                                                                                                                                                   *
 * 1 から 5 までの数字を英単語で書けば one, two, three, four, five であり, 全部で 3 + 3 + 5 + 4 + 4 = 19 の文字が使われている.                                                       *
 *                                                                                                                                                                                   *
 * では 1 から 1000 (one thousand) までの数字をすべて英単語で書けば, 全部で何文字になるか.                                                                                           *
 *                                                                                                                                                                                   *
 * 注: 空白文字やハイフンを数えないこと. 例えば, 342 (three hundred and forty-two) は 23 文字, 115 (one hundred and fifteen) は20文字と数える. なお, "and" を使用するのは英国の慣習. *
 *****************************************************************************************************************************************/

map<int, int> m{
    {1   , 3},
    {2   , 3},
    {3   , 5},
    {4   , 4},
    {5   , 4},
    {6   , 3},
    {7   , 5},
    {8   , 5},
    {9   , 4},
    {10  , 3},
    {11  , 6},
    {12  , 6},
    {13  , 8},
    {14  , 8},
    {15  , 7},
    {16  , 7},
    {17  , 9},
    {18  , 8},
    {19  , 8},
    {20  , 6},
    {30  , 6},
    {40  , 5},
    {50  , 5},
    {60  , 5},
    {70  , 7},
    {80  , 6},
    {90  , 6},
    {100 , 7},
    {1000, 8}
};

int mozi(int dig){
  int res = 0;
  if(dig >= 100 && dig%100 != 0) res += 3;
  if(dig >= 1000){
    res += m[dig/1000]+m[1000];
    dig %= 1000;
  }
  if(dig >= 100){
    res += m[dig/100]+m[100];
    dig %= 100;
  }
  if(20 <= dig){
    res += m[dig/10*10];
    dig %= 10;
  }
  if(1 <= dig) res += m[dig];

  return res;
}

signed main() {
  int N = 1000;

  int ans = 0;
  FOR(i, 1, N+1) ans += mozi(i);

  cout << ans << endl;

  return 0;
}
