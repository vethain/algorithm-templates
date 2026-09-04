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

const int N = (1ll << 62) + ((1ll << 62) - 1);
const double eps = 1e-9;
int mod = 1e9 + 7;

// O(n + q)判断每个查询序列是不是一个排列
void solve() 
{
    int n, q;
    cin >> n >> q;
    vector <int> a(n + 1), b(n + 1), pr1(n + 1, 0), pr2(n + 1, 0);
    for (int i = 1; i <= n; i++) b[i] = rd(1ll, N), pr2[i] = pr2[i - 1] ^ b[i];
    for (int i = 1; i <= n; i++) cin >> a[i], pr1[i] = pr1[i - 1] ^ b[a[i]];
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int len = (r - l + 1);
        if (pr2[len] == (pr1[r] ^ pr1[l - 1])) Y;
        else O;
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