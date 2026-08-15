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

const int N = 5e7 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

int p[N];
void solve()
{
    string s;
    cin >> s;
    string ss = "@#";
    for (int i = 0; i < s.size(); i++)
    {
        ss += s[i];
        ss += '#';
    }
    ss += '*';
    int n = ss.size();
    s = ss;
    int ans = 0;
    const auto manacher = [&]()
    {
        int r = 0, c = 0;
        for (int i = 1; i < n; i++)
        {
            if (i < r)
            {
                p[i] = min(p[2 * c - i], r - i);
            }
            else
            {
                p[i] = 1;
            }
            while (s[p[i] + i] == s[i - p[i]])
            {
                p[i]++;
            }
            if (p[i] + i > r)
            {
                r = p[i] + i;
                c = i;
            }
            ans = max(ans, p[i] - 1);
        }
    };
    manacher();
    cout << ans << endl;
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