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

using u64 = unsigned long long;
using u128 = __uint128_t;

u64 mul_mod(u64 a, u64 b, u64 mod) {
    return (u128)a * b % mod;
}

u64 pow_mod(u64 a, u64 d, u64 mod) {
    u64 res = 1;
    while (d) {
        if (d & 1) res = mul_mod(res, a, mod);
        a = mul_mod(a, a, mod);
        d >>= 1;
    }
    return res;
}

bool is_prime(u64 n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    u64 d = n - 1;
    int s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        ++s;
    }
    static const u64 bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (u64 a : bases) {
        if (a % n == 0) continue;
        u64 x = pow_mod(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool composite = true;
        for (int r = 1; r < s; ++r) {
            x = mul_mod(x, x, n);
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

u64 pollard_rho(u64 n) {
    if (n % 2 == 0) return 2;
    if (n % 3 == 0) return 3;
    static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    while (true) {
        u64 c = uniform_int_distribution<u64>(1, n - 1)(rng);
        u64 x = uniform_int_distribution<u64>(0, n - 1)(rng);
        u64 y = x;
        u64 d = 1;
        auto f = [&](u64 v) -> u64 {
            return (mul_mod(v, v, n) + c) % n;
        };
        for (int i = 1; d == 1; ++i) {
            x = f(x);
            y = f(f(y));
            d = std::gcd(x > y ? x - y : y - x, n);
        }
        if (d != n) return d;
    }
}

void factor(u64 n, vector<u64>& factors) {
    if (n == 1) return;
    if (is_prime(n)) {
        factors.push_back(n);
        return;
    }
    u64 d = pollard_rho(n);
    factor(d, factors);
    factor(n / d, factors);
}
// ----------------------------------------------------------------

vector<pair<int, int>> f;
void ise(int n)
{
    f.clear();
    if (n <= 1) return;
    u64 un = (u64)n;
    vector<u64> factors;
    factor(un, factors);
    sort(factors.begin(), factors.end());
    for (u64 p : factors) {
        if (f.empty() || f.back().first != (int)p) {
            f.push_back({(int)p, 1});
        } else {
            f.back().second++;
        }
    }
}

void solve() 
{
    int n;
    cin >> n;
    ise(n);
    for (auto [x, y] : f) cout << x << ' ' << y << endl;
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