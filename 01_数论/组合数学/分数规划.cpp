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
const int N = 1e5 + 5;
const double eps = 1e-11;

struct node
{
    int a, b;
    ld y;
} p[N];
void solve()
{
    int n, k;
    cin >> n >> k;
    ld l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].a;
        r += p[i].a;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].b;
    }
    const auto check = [&](const ld &x) -> bool
    {
        for (int i = 1; i <= n; i++)
        {
            p[i].y = p[i].a * 1.0 - x * p[i].b * 1.0;
        }
        sort(p + 1, p + 1 + n, [&](const node &x, const node &y)
             { return x.y > y.y; });
        double sum = 0;
        for (int i = 1; i <= k; i++)
        {
            sum += p[i].y;
        }
        return sum > 0;
    };
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << fixed << setprecision(10) << r << endl;
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