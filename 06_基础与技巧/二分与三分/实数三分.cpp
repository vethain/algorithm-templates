#include <bits/stdc++.h>
#define endl '\n'
#define uul __int128
#define int long long int
#define ull unsigned long long int
#define ld long double
#define inf 1000000000000000000LL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
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
const double eps = 1e-6;

void solve()
{
    int n;
    ld l, r;
    cin >> n >> l >> r;
    ld a[15]; // x = i处的函数值
    for (int i = n; i >= 0; i--)
    {
        cin >> a[i];
    }
    const auto f = [&](const ld x) -> ld
    {
        ld sum = 0;
        for (int i = n; i >= 0; i--)
        {
            sum = sum * x + a[i];
        }
        return sum;
    };
    while (r - l > eps)
    {
        ld now = (r - l) / 3;
        ld mid1 = l + now, mid2 = r - now;
        if (f(mid1) > f(mid2))
        {
            r = mid2;
        }
        else
        {
            l = mid1;
        }
    }
    printf("%.5Lf", l);
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