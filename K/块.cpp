#include <bits/stdc++.h>
#define endl '\n'
#define i128 __int128
#define int long long int
#define ld long double
#define gcd __gcd
#define inf 0x3f3f3f3f3f3f3f3fLL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define tos to_string
using namespace std;

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &x : v)
        is >> x;
    return is;
}
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

const int N = 5e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

int n, q;
int a[N], st[N], ed[N], pos[N], sum[1005], add[1005];
void init()
{
    int blo = sqrt(n);
    int t = n / blo;
    if (n % blo)
    {
        t++;
    }
    for (int i = 1; i <= t; i++)
    {
        st[i] = (i - 1) * blo + 1;
        ed[i] = i * blo;
    }
    ed[t] = n;
    for (int i = 1; i <= n; i++)
    {
        pos[i] = (i - 1) / blo + 1;
    }
    for (int i = 1; i <= t; i++)
    {
        for (int j = st[i]; j <= ed[i]; j++)
        {
            sum[i] += a[j];
        }
    }
}
void change(int L, int R, int d)
{
    int p = pos[L], q = pos[R];
    if (p == q)
    {
        for (int i = L; i <= R; i++)
        {
            a[i] += d;
        }
        sum[p] += (R - L + 1) * d;
    }
    else
    {
        for (int i = p + 1; i < q; i++)
        {
            add[i] += d;
        }
        for (int i = L; i <= ed[p]; i++)
        {
            a[i] += d;
        }
        sum[p] += d * (ed[p] - L + 1);
        for (int i = st[q]; i <= R; i++)
        {
            a[i] += d;
        }
        sum[q] += d * (R - st[q] + 1);
    }
}
int query(int L, int R)
{
    int p = pos[L], q = pos[R];
    int ans = 0;
    if (p == q)
    {
        ans += add[p] * (R - L + 1);
        for (int i = L; i <= R; i++)
        {
            ans += a[i];
        }
    }
    else
    {
        for (int i = p + 1; i < q; i++)
        {
            ans += sum[i] + add[i] * (ed[i] - st[i] + 1);
        }
        for (int i = L; i <= ed[p]; i++)
        {
            ans += a[i];
        }
        ans += add[p] * (ed[p] - L + 1);
        for (int i = st[q]; i <= R; i++)
        {
            ans += a[i];
        }
        ans += add[q] * (R - st[q] + 1);
    }
    return ans;
}
void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    init();
    while (q--)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int l, r, d;
            cin >> l >> r >> d;
            change(l, r, d);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(l, r) << endl;
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