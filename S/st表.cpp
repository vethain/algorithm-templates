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

const int N = 5e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

int n, q;
int a[N], st[N][20], lg[N];
void init_log()
{
    lg[0] = -1;
    for (int i = 1; i < N; i++)
    {
        lg[i] = lg[i >> 1] + 1;
    }
}
void init_st()
{
    for (int i = 1; i <= n; i++)
    {
        st[i][0] = a[i];
    }
    for (int k = 1; k <= lg[n]; k++)
    {
        for (int s = 1; s + (1 << k) - 1 <= n; s++)
        {
            st[s][k] = max(st[s][k - 1], st[s + (1 << (k - 1))][k - 1]);
        }
    }
}
int get_st(int l, int r)
{
    int k = lg[r - l + 1];
    int ans = max(st[l][k], st[r - (1 << k) + 1][k]);
    return ans;
}
// 注意后半部分得 + 1  因为st表表示的是从当前开始  往后1<<k个数  如果不加1  那么最右端的数将不被计算
void solve()
{
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