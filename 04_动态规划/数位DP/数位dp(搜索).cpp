// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define i128 __int128
#define i32 int32_t
#define int long long int
#define ld long double
#define gcd __gcd
#define inf 0x3f3f3f3f3f3f3fLL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x) cerr << #x << " : " << x << endl
#define sig cerr << "OK" << endl;
using namespace std;

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &x : v)
        is >> x;
    return is;
}
template <typename T>
T rd(T l, T r)
{
    static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<T> dist(l, r);
    return dist(rng);
}
template <typename T>
bool ckmax(T &a, T b)
{
    return a < b ? (a = b, true) : false;
}
template <typename T>
bool ckmin(T &a, T b)
{
    return b < a ? (a = b, true) : false;
}

const int N = 1e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

/*
int dfs(int pos, State state, bool lmt, bool num) {
    if (pos < 0) return 边界条件;
    if (!lmt && num && vis[pos][state]) return dp[pos][state];
    int up = lmt ? dig[pos] : 9;
    int res = 0;
    for (int i = 0; i <= up; i++) {
        res += dfs(pos - 1, 转移(state, i), lmt && i == up, num || (i != 0));
    }
    if (!lmt && num) { dp[pos][state] = res; vis[pos][state] = 1; }
    return res;
}
*/

void solve() 
{
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundus
    int _ = 1;
    cin >> _;
    while (_--)
        solve();

    return 0;
}