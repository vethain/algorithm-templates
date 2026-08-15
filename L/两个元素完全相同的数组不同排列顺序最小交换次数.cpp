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

const int mod = 1e8 - 3;
const int N = 5e5 + 5;
const double eps = 1e-9;

int a[N], b[N], c[N], B[N], ans = 0;
void mgs(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    mgs(l, mid);
    mgs(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (c[i] > c[j])
        {
            ans += (mid - i + 1);
            B[k++] = c[j++];
        }
        else
        {
            B[k++] = c[i++];
        }
    }
    while (i <= mid)
    {
        B[k++] = c[i++];
    }
    while (j <= r)
    {
        B[k++] = c[j++];
    }
    for (int i = l; i <= r; i++)
    {
        c[i] = B[i];
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    map<int, int> m1, m2;
    vector<int> va(a + 1, a + n + 1);
    sort(va.begin(), va.end());
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(va.begin(), va.end(), a[i]) - va.begin() + 1;
    }
    vector<int> vb(b + 1, b + n + 1);
    sort(vb.begin(), vb.end());
    for (int i = 1; i <= n; i++)
    {
        b[i] = lower_bound(vb.begin(), vb.end(), b[i]) - vb.begin() + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        m1[a[i]] = i;
        m2[b[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        c[m1[i]] = m2[i];
    }
    mgs(1, n);
    cout << ans % mod << endl;
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