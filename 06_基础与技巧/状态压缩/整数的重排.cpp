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
#define ct1(x) __builtin_popcount(x)
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

int dp[N][105], n, m;
vector <int> ct(10, 0), base(10, 0);

int encode(vector <int> cnt)
{
    int res = 0;
    for (int i = 0; i < 10; i++) res += cnt[i] * base[i];
    return res;
}

vector <int> decode(int x)
{
    vector <int> res(10);
    for (int i = 0; i < 10; i++)
    {
        res[i] = x % (ct[i] + 1);
        x /= (ct[i] + 1);
    }
    return res;
}

void init()
{
    base[0] = 1;
    for (int i = 1; i < 10; i++) base[i] = base[i - 1] * (ct[i - 1] + 1);
}

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