#include <bits/stdc++.h>
#define endl '\n'
#define i128 __int128
#define int long long int
#define ull unsigned long long int
#define ld long double
#define inf 1000000000000000000LL
#define gcd __gcd
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

template <typename T, size_t SIZE>
void fl(T (&arr)[SIZE], const T &val)
{
    fill(arr, arr + SIZE, val);
}
template <typename Container>
void fl(Container &container, const typename Container::value_type &val)
{
    fill(container.begin(), container.end(), val);
}

const int N = 5e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

/*注意模数必须为质数*/
int fact[N];
int inv_fact[N];
int pw(int a, int b)
{
    int ans = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
        {
            ans = (i128)ans * a % mod;
        }
        a = (i128)a * a % mod;
        b >>= 1;
    }
    return ans % mod;
}
void init(int n, int mod)
{
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
    inv_fact[n] = pw(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; i--)
    {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
    }
}
int C(int n, int k, int mod)
{
    if (k < 0 || k > n)
    {
        return 0;
    }
    return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}
int A(int n, int k, int mod)
{
    if (k < 0 || k > n)
    {
        return 0;
    }
    return 1LL * fact[n] * inv_fact[n - k] % mod;
}
void solve()
{
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundi
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();

    return 0;
}

/*模数为合数*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 200000 + 5;

int spf[MAXN];
vector<int> primes;

void sieve() {
    for (int i = 2; i < MAXN; i++) spf[i] = i;

    for (int i = 2; 1LL * i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    for (int i = 2; i < MAXN; i++) {
        if (spf[i] == i) primes.push_back(i);
    }
}

// n! 中质因子 p 的次数
ll vp_fact(int n, int p) {
    ll res = 0;
    while (n) {
        n /= p;
        res += n;
    }
    return res;
}

ll mul_mod(ll a, ll b, ll mod) {
    return (ll)((__int128)a * b % mod);
}

ll pow_mod(ll a, ll e, ll mod) {
    ll res = 1 % mod;
    a %= mod;

    while (e) {
        if (e & 1) res = mul_mod(res, a, mod);
        a = mul_mod(a, a, mod);
        e >>= 1;
    }

    return res;
}

// 任意模数组合数，n 不能超过 MAXN-1
ll C_any_mod(int n, int k, ll mod) {
    if (k < 0 || k > n) return 0;

    ll ans = 1 % mod;

    for (int p : primes) {
        if (p > n) break;

        ll e = vp_fact(n, p) - vp_fact(k, p) - vp_fact(n - k, p);

        if (e > 0) {
            ans = mul_mod(ans, pow_mod(p, e, mod), mod);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int n = 5, k = 2;
    ll mod = 12; // 合数

    cout << C_any_mod(n, k, mod) << '\n'; // C(5,2)=10, 10 mod 12 = 10

    return 0;
}