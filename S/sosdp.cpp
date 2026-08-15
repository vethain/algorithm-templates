#include <bits/stdc++.h>
#define i128 __int128
#define i32 int32_t
#define int long long int
#define ld long double
#define gcd __gcd
#define inf 0x3f3f3f3f3f3f3f3fLL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define tos to_string
#define debug(x) cerr << #x << " : " << x << endl
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
    求一个二进制数的所有子集和
    父为1  可为1 0
    父为0  只可为0
*/
void solve() 
{
    int n;
    cin >> n;
    vector <int> dp(n);
    cin >> dp;
    for (int i = 0; i < dig; i++)
    {
        for (int mask = 0; mask < (1ll << dig); mask++)
        {
            if (mask & (1ll << i))
            {
                dp[mask] += dp[mask ^ (1ll << i)];
            }
        }
    }
    
    /*超集  反过来即可*/
    for (int i = 0; i < dig; i++) 
    {
        for (int mask = 0; mask < (1 << dig); mask++) 
        {
            if ((mask & (1 << i)) == 0) 
            {
                dp[mask] += dp[mask | (1 << i)];
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundus
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();

    return 0;
}