#include <bits/stdc++.h>
#define endl '\n'
#define uul __int128
#define int long long int
#define ull unsigned long long int
#define ld long double
#define inf 1000000000000000000LL
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

const int mod = 1e9 + 7;
const int N = 5e5 + 5;
const double eps = 1e-9;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
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